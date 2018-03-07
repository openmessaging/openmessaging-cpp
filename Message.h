#ifndef OMS_MESSAGE_H
#define OMS_MESSAGE_H

#include <string>
#include <boost/smart_ptr.hpp>

#include "KeyValue.h"
#include "BuiltinKeys.h"
#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * The {@code Message} interface is the root interface of all OMS messages, and the most commonly used OMS message is
     * {@link BytesMessage}.
     * <p>
     * Most message-oriented middleware (MOM) products treat messages as lightweight entities that consist of a header and a
     * body, like <a href="http://rocketmq.apache.org/">Apache RocketMQ</a>. The header part contains fields used for message
     * routing and identification; the body part contains the application data to sent.
     * <p>
     * The {@code Message} is a lightweight entity that only contains properties related to information of a specific message
     * object, and the {@code Message} is composed of the following parts:
     *
     * <UL>
     * <LI>Header - All messages support the same set of header fields. Header fields contain values used by both
     * clients and providers to identify and route messages.
     * <LI>Properties - Each message contains a built-in facility for supporting application-defined property values.
     * Properties provide an efficient mechanism for supporting application-defined message filtering.
     * </UL>
     *
     * The body part is deferred to the sub-classes of {@code Message}.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Message : private Uncopyable {
    public:
        virtual ~Message() {

        }

        virtual boost::shared_ptr<KeyValue> sysHeaders() = 0;

        virtual boost::shared_ptr<KeyValue> userHeaders() = 0;

        virtual Message& putSysHeaders(const std::string &key, int value) = 0;

        virtual Message& putSysHeaders(const std::string &key, long value) = 0;

        virtual Message& putSysHeaders(const std::string &key, double value) = 0;

        virtual Message& putSysHeaders(const std::string &key, const std::string &value) = 0;

        virtual Message& putUserHeaders(const std::string &key, int value) = 0;

        virtual Message& putUserHeaders(const std::string &key, long value) = 0;

        virtual Message& putUserHeaders(const std::string &key, double value) = 0;

        virtual Message& putUserHeaders(const std::string &key, const std::string &value) = 0;

    };

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_MESSAGE_H
