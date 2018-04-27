#ifndef OMS_FUTURE_H
#define OMS_FUTURE_H

#include <exception>
#include <climits>

#include "smart_pointer.h"
#include "producer/SendResult.h"
#include "Uncopyable.h"
#include "FutureListener.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * A {@code Future} represents the result of an asynchronous computation.  Methods are provided to check if the
     * computation is complete, to wait for its completion, and to retrieve the result of the computation.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Future : private Uncopyable {
    public:
        virtual ~Future() {

        }

        virtual bool isCancelled() = 0;

        virtual bool isDone() = 0;

        virtual producer::SendResultPtr get(unsigned long timeout = LONG_MAX) = 0;

        virtual Future &addListener(FutureListenerPtr listener) = 0;

        virtual std::exception &getThrowable() = 0;

    };

    typedef NS::shared_ptr<Future> FuturePtr;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_FUTURE_H
