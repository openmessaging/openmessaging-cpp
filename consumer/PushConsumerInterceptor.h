#ifndef OMS_PUSHCONSUMERINTERCEPTOR_H
#define OMS_PUSHCONSUMERINTERCEPTOR_H

#include "Namespace.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

            class PushConsumerInterceptor {
            public:
               virtual ~PushConsumerInterceptor() {
                }

                virtual void preHandle(boost::shared_ptr<void> context) = 0;

                virtual void postHandle(boost::shared_ptr<void> context) = 0;
            };

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_PUSHCONSUMERINTERCEPTOR_H
