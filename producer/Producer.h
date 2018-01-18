#ifndef OMS_PRODUCER_H
#define OMS_PRODUCER_H

#include <boost/shared_ptr.hpp>

#include "MessageFactory.h"
#include "ServiceLifecycle.h"
#include "Message.h"
#include "SendResult.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)
        extern boost::shared_ptr<KeyValue> kv_nullptr;
        BEGIN_NAMESPACE_1(producer)
            class Producer : public virtual MessageFactory, public virtual ServiceLifecycle {
            public:
                virtual ~Producer() {

                }

                virtual boost::shared_ptr<KeyValue> properties() = 0;

                virtual boost::shared_ptr<SendResult> send(boost::shared_ptr<Message> message,
                                                           boost::shared_ptr<KeyValue> properties = kv_nullptr) = 0;
            };
END_NAMESPACE_3(io, openmessaging, producer)
#endif //OMS_PRODUCER_H
