#ifndef OMS_MESSAGE_LISTENER_H
#define OMS_MESSAGE_LISTENER_H

#include "Context.h"
#include "Namespace.h"
#include "Message.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

    /**
     * The message listener interface. A message listener must implement this {@code MessageListener} interface and register
     * itself to a consumer instance to asynchronously receive messages.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class MessageListener : private Uncopyable {
    public:
        virtual ~MessageListener() {

        }

        virtual void onMessage(boost::shared_ptr<Message>& message, boost::shared_ptr<Context>& context) = 0;
    };

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_MESSAGE_LISTENER_H
