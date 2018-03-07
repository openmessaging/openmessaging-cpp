#ifndef OMS_PUSH_CONSUMER_INTERCEPTOR_H
#define OMS_PUSH_CONSUMER_INTERCEPTOR_H

#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

    class PushConsumerInterceptor : private Uncopyable {
    public:
       virtual ~PushConsumerInterceptor() {
        }

        virtual void preHandle(boost::shared_ptr<void> context) = 0;

        virtual void postHandle(boost::shared_ptr<void> context) = 0;
    };

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_PUSH_CONSUMER_INTERCEPTOR_H
