#ifndef OMS_MESSAGING_ACCESS_POINT_H
#define OMS_MESSAGING_ACCESS_POINT_H

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
#include "OMS.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * The {@code MessagingAccessPoint} obtained from {@link MessagingAccessPointFactory} is capable of creating {@code
     * Producer}, {@code Consumer}, {@code ServiceEndPoint}, and so on. <p> For example:
     * <pre>
     * MessagingAccessPoint messagingAccessPoint = MessagingAccessPointFactory.getMessagingAccessPoint("openmessaging:rocketmq://localhost:10911/namespace");
     * Producer producer = messagingAccessPoint.createProducer();
     * producer.send(producer.createTopicBytesMessage("HELLO_TOPIC", "HELLO_BODY".getBytes(Charset.forName("UTF-8"))));
     * </pre>
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class MessagingAccessPoint : public virtual ServiceLifecycle {
    public:
        virtual ~MessagingAccessPoint() {

        }

        virtual boost::shared_ptr<KeyValue> properties() = 0;

        virtual std::string implVersion() = 0;

        virtual boost::shared_ptr<producer::Producer>
        createProducer(const boost::shared_ptr<KeyValue> &properties = kv_nullptr) = 0;

        virtual boost::shared_ptr<consumer::PushConsumer>
        createPushConsumer(const boost::shared_ptr<KeyValue> &properties = kv_nullptr) = 0;

        virtual boost::shared_ptr<consumer::PullConsumer>
        createPullConsumer(const std::string &queueName,
                           const boost::shared_ptr<KeyValue> &properties = kv_nullptr) = 0;

        virtual boost::shared_ptr<consumer::StreamingConsumer>
        createStreamingConsumer(const std::string &queueName,
                                const boost::shared_ptr<KeyValue> &properties = kv_nullptr) = 0;

        virtual boost::shared_ptr<ResourceManager> getResourceManager() = 0;

        virtual void addObserver(const boost::shared_ptr<observer::Observer> &observer) = 0;

        virtual void removeObserver(const boost::shared_ptr<observer::Observer> &observer) = 0;

        virtual std::vector<boost::shared_ptr<producer::Producer> > producers() = 0;

        virtual std::vector<boost::shared_ptr<consumer::PushConsumer> > pushConsumers() = 0;

        virtual std::vector<boost::shared_ptr<consumer::PullConsumer> > pullConsumers() = 0;

        virtual std::vector<boost::shared_ptr<consumer::StreamingConsumer> > streamingConsumers() = 0;
    };

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_MESSAGING_ACCESS_POINT_H
