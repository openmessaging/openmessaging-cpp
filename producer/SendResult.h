#ifndef SENDRESULT_H
#define SENDRESULT_H

#include <string>

#include <boost/shared_ptr.hpp>

#include "KeyValue.h"
#include "Namespace.h"

BEGIN_NAMESPACE_3(io, openmessaging, producer)

            class SendResult {
            public:
                SendResult(const std::string &msgId, boost::shared_ptr<KeyValue> props) : _messageId(msgId),
                                                                                          _properties(props) {
                }

                const std::string &messageId() const {
                    return _messageId;
                }

                boost::shared_ptr<KeyValue> properties() const {
                    return _properties;
                }

            protected:
                std::string _messageId;
                boost::shared_ptr<KeyValue> _properties;
            };

END_NAMESPACE_3(io, openmessaging, producer)

#endif // SENDRESULT_H
