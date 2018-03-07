#ifndef OMS_PRODUCER_INTERCEPTOR_H
#define OMS_PRODUCER_INTERCEPTOR_H

#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, interceptor)

    class PreSendContext : private Uncopyable {
    public:
        virtual ~PreSendContext() {
        }
    };

    class PostSendContext {
    public:
        virtual ~PostSendContext() {
        }
    };

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

        virtual void preSend(boost::shared_ptr<PreSendContext> context);

        virtual void postSend(boost::shared_ptr<PostSendContext> context);
    };

END_NAMESPACE_3(io, openmessaging, interceptor)

#endif // OMS_PRODUCER_INTERCEPTOR_H
