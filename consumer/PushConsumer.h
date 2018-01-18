#ifndef OMS_PUSHCONSUMER_H
#define OMS_PUSHCONSUMER_H

#include <string>

#include <boost/shared_ptr.hpp>

#include "ServiceLifecycle.h"
#include "PushConsumerInterceptor.h"
#include "MessageListener.h"
#include "Namespace.h"
BEGIN_NAMESPACE_2(io, openmessaging)
        extern boost::shared_ptr<KeyValue> kv_nullptr;
        BEGIN_NAMESPACE_1(consumer)
            class PushConsumer : public virtual ServiceLifecycle {
            public:
                virtual ~PushConsumer() {

                }

                virtual boost::shared_ptr<KeyValue> properties() = 0;

                virtual void resume() = 0;

                virtual void suspend() = 0;

                virtual bool isSuspended() = 0;

                virtual PushConsumer &attachQueue(std::string &queueName,
                                                  boost::shared_ptr<MessageListener> listener,
                                                  boost::shared_ptr<KeyValue> properties = kv_nullptr) = 0;

                virtual PushConsumer &detachQueue(std::string &queueName) = 0;

                virtual void addInterceptor(boost::shared_ptr<PushConsumerInterceptor> interceptor) = 0;

                virtual void removeInterceptor(boost::shared_ptr<PushConsumerInterceptor> interceptor) = 0;
            };

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_PUSHCONSUMER_H
