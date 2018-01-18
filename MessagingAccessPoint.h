#ifndef MESSAGINGACCESSPOINT_H
#define MESSAGINGACCESSPOINT_H

#include <string>
#include <boost/shared_ptr.hpp>

#include "ServiceLifecycle.h"
#include "KeyValue.h"
#include "producer/Producer.h"
#include "consumer/PullConsumer.h"
#include "consumer/PushConsumer.h"
#include "consumer/StreamingConsumer.h"
#include "ResourceManager.h"
#include "observer/Observer.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        class MessagingAccessPoint : public virtual ServiceLifecycle {
        public:
            virtual ~MessagingAccessPoint() {

            }

            virtual boost::shared_ptr<KeyValue> properties() = 0;

            virtual std::string implVersion() = 0;

            virtual boost::shared_ptr<producer::Producer>
            createProducer(boost::shared_ptr<KeyValue> properties = kv_nullptr) = 0;

            virtual boost::shared_ptr<consumer::PushConsumer>
            createPushConsumer(boost::shared_ptr<KeyValue> properties = kv_nullptr) = 0;

            virtual boost::shared_ptr<consumer::PullConsumer>
            createPullConsumer(const std::string &queueName, boost::shared_ptr<KeyValue> properties = kv_nullptr) = 0;

            virtual boost::shared_ptr<consumer::StreamingConsumer> createStreamingConsumer(const std::string &queueName,
                                                                                           boost::shared_ptr<KeyValue> properites = kv_nullptr) = 0;

            virtual boost::shared_ptr<ResourceManager> getResourceManager() = 0;

            virtual void addObserver(boost::shared_ptr<observer::Observer> observer) = 0;

            virtual void removeObserver(boost::shared_ptr<observer::Observer> observer) = 0;

            virtual std::vector<boost::shared_ptr<producer::Producer> > producers() = 0;

            virtual std::vector<boost::shared_ptr<consumer::PushConsumer> > pushConsumers() = 0;

            virtual std::vector<boost::shared_ptr<consumer::PullConsumer> > pullConsumers() = 0;

            virtual std::vector<boost::shared_ptr<consumer::StreamingConsumer> > streamingConsumers() = 0;
        };

END_NAMESPACE_2(io, openmessaging)

#endif // MESSAGINGACCESSPOINT_H
