#ifndef OMS_MESSAGELISTENER_H
#define OMS_MESSAGELISTENER_H

#include "Context.h"
#include "Namespace.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

            class MessageListener {
            public:
                virtual ~MessageListener() {

                }

                virtual void onMessage(boost::shared_ptr <Message> message,
                                       boost::shared_ptr <Context> context) = 0;
            };

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_MESSAGELISTENER_H
