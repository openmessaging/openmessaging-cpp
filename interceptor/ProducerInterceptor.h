#ifndef OMS_PRODUCER_INTERCEPTOR_H
#define OMS_PRODUCER_INTERCEPTOR_H

#include "Namespace.h"
#include "Uncopyable.h"
#include "smart_pointer.h"
#include "Message.h"

BEGIN_NAMESPACE_3(io, openmessaging, interceptor)

    /**
     * A {@code ProducerInterceptor} is used to intercept send operations of producer.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class ProducerInterceptor : private Uncopyable {
    public:
        virtual ~ProducerInterceptor() {

        }

        virtual std::string name() const = 0;

        virtual void preSend(const MessagePtr &message, const KeyValuePtr &attributes = kv_nullptr) = 0;

        virtual void postSend(const MessagePtr &message, const KeyValuePtr &attributes = kv_nullptr) = 0;

    };
    typedef NS::shared_ptr<ProducerInterceptor> ProducerInterceptorPtr;

END_NAMESPACE_3(io, openmessaging, interceptor)

#endif // OMS_PRODUCER_INTERCEPTOR_H
