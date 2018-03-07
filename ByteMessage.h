#ifndef OMS_BYTE_MESSAGE_H
#define OMS_BYTE_MESSAGE_H

#include "Message.h"
#include "Namespace.h"
#include "OMS.h"

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

        virtual scoped_array<char> getBody()  = 0;

        virtual ByteMessage& setBody(const scoped_array<char> &body) = 0;

    };

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_BYTE_MESSAGE_H
