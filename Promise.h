#ifndef OMS_PROMISE_H
#define OMS_PROMISE_H

#include "OMS.h"
#include "Future.h"
#include "producer/SendResult.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)
    /**
     * Special {@link Future} which is writable.
     * <p>
     * A {@code Promise} can be completed or canceled, cancellation is performed by the {@code cancel} method.
     * Once a computation has completed, the computation cannot be cancelled. If you would like to use a {@code Promise}
     * for the sake of cancellability but not provide a usable result, you can declare type+s of the form
     * {@code Promise<?>} and return {@code null} as a result of the underlying task.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Promise : public Future {
    public:
        virtual ~Promise() {
        }

        virtual bool cancel(bool interruptIfRunning = false) = 0;

        virtual bool set(producer::SendResultPtr &value) = 0;

        virtual bool setFailure(std::exception &e) = 0;
    };

    typedef NS::shared_ptr<Promise> PromisePtr;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_PROMISE_H
