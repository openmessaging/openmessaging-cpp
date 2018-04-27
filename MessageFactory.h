#ifndef OMS_MESSAGE_FACTORY_H
#define OMS_MESSAGE_FACTORY_H

#include <string>
#include <vector>

#include "ByteMessage.h"
#include "Namespace.h"
#include "OMS.h"

BEGIN_NAMESPACE_2(io, openmessaging)
    /**
     * A factory interface for creating {@code Message} objects.
     *
     */
    class MessageFactory {
    public:
        virtual ~MessageFactory() {
        }

        /**
         * Creates a {@code BytesMessage} object. A {@code BytesMessage} object is used to send a message containing a
         * stream of uninterpreted bytes.
         * <p>
         * The returned {@code BytesMessage} object only can be sent to the specified queue.
         *
         * @param queue the target queue to send
         * @param body the body data for a message
         * @return the created {@code BytesMessage} object
         * @throws OMSRuntimeException if the OMS provider fails to create this message due to some internal error.
         */
        virtual ByteMessagePtr createBytesMessage(const std::string &topic, const MessageBody &body) = 0;
    };

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_MESSAGE_FACTORY_H
