#ifndef OMS_BYTEMESSAGE_H
#define OMS_BYTEMESSAGE_H

#include <vector>

#include <boost/move/move.hpp>

#include "Message.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        class ByteMessage : public Message {
        public:
            std::vector<char> &getBody() {
                return _body;
            }

            ByteMessage &setBody(const std::vector<char> &body) {
                _body = boost::move(body);
                return *this;
            }

        protected:
            std::vector<char> _body;
        };

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_BYTEMESSAGE_H
