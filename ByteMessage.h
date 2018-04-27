#ifndef OMS_BYTE_MESSAGE_H
#define OMS_BYTE_MESSAGE_H

#include "OMS.h"
#include "Message.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * The {@code BytesMessage} contains a stream of uninterpreted bytes. It inherits from the {@code Message} interface and
     * adds a bytes message body.
     * <p>
     * The {@code BytesMessage} doesn't know the format or encoding Rules of the body, the provider and consumer decide the
     * interpretation of the bytes body.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class ByteMessage : public virtual Message {
    public:
        virtual ~ByteMessage() {

        }

        virtual MessageBody getBody()  = 0;

        virtual ByteMessage& setBody(const MessageBody &body) = 0;

    };

    typedef NS::shared_ptr<ByteMessage> ByteMessagePtr;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_BYTE_MESSAGE_H
