#ifndef OMS_BUILTIN_KEYS_H
#define OMS_BUILTIN_KEYS_H

#include <string>
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        /**
         * The {@code MESSAGE_ID} header field contains a value that uniquely identifies
         * each message sent by a {@code Producer}.
         * <p>
         * When a message is sent, MESSAGE_ID is assigned by the producer.
         */
        static const std::string MESSAGE_ID = "MESSAGE_ID";

        /**
         * The {@code DESTINATION} header field contains the destination to which the message is being sent.
         * <p>
         * When a message is sent this value is set to the right {@code Queue}, then the message will be sent to
         * the specified destination.
         * <p>
         * When a message is received, its destination is equivalent to the {@code Queue} where the message resides in.
         */
        static const std::string DESTINATION = "DESTINATION";

        /**
         * The {@code RECEIPT_HANDLE} header field contains an identifier associated with the act of receiving a message.
         * <p></p>
         * A new receipt handle will be set properly every time a message is received, and the consumer could use
         * it to acknowledge the consumed message.
         */
        static const std::string RECEIPT_HANDLE = "RECEIPT_HANDLE";

        /**
         * The {@code BORN_TIMESTAMP} header field contains the time a message was handed
         * off to a {@code Producer} to be sent.
         * <p>
         * When a message is sent, BORN_TIMESTAMP will be set with current timestamp as the born
         * timestamp of a message in client side, on return from the send method, the message's
         * BORN_TIMESTAMP header field contains this value.
         * <p>
         * When a message is received its, BORN_TIMESTAMP header field contains this same value.
         * <p>
         * This filed is a {@code long} value, measured in milliseconds.
         */
        static const std::string BORN_TIMESTAMP = "BORN_TIMESTAMP";

        /**
         * The {@code BORN_HOST} header field contains the born host info of a message in client side.
         * <p>
         * When a message is sent, BORN_HOST will be set with the local host info,
         * on return from the send method, the message's BORN_HOST header field contains this value.
         * <p>
         * When a message is received, its BORN_HOST header field contains this same value.
         */
        static const std::string BORN_HOST = "BORN_HOST";

        /**
         * The {@code STORE_TIMESTAMP} header field contains the store timestamp of a message in server side.
         * <p>
         * When a message is sent, STORE_TIMESTAMP is ignored.
         * <p>
         * When the send method returns it contains a server-assigned value.
         * <p>
         * This filed is a {@code long} value, measured in milliseconds.
         */
        static const std::string STORE_TIMESTAMP = "STORE_TIMESTAMP";

        /**
         * The {@code STORE_HOST} header field contains the store host info of a message in server side.
         * <p>
         * When a message is sent, STORE_HOST is ignored.
         * <p>
         * When the send method returns it contains a server-assigned value.
         */
        static const std::string STORE_HOST = "STORE_HOST";

        /**
         * The {@code START_TIME} header field contains the startup timestamp that a message
         * can be delivered to consumer client.
         * <p>
         * If START_TIME field isn't set explicitly, use BORN_TIMESTAMP as the startup timestamp.
         * <p>
         * This filed is a {@code long} value, measured in milliseconds.
         */
        static const std::string START_TIME = "START_TIME";

        /**
         * The {@code STOP_TIME} header field contains the stop timestamp that a message
         * should be discarded after this timestamp, and no consumer can consume this message.
         * <p>
         * {@code (START_TIME ~ STOP_TIME)} represents an absolute valid interval that a message
         * can be delivered in it.
         * <p>
         * If an earlier timestamp is set than START_TIME, that means the message does not expire.
         * <p>
         * This filed is a {@code long} value, measured in milliseconds.
         * <p>
         * When an undelivered message's expiration time is reached, the message should be destroyed.
         * OMS does not define a notification of message expiration.
         */
        static const std::string STOP_TIME = "STOP_TIME";

        /**
         * The {@code TIMEOUT} header field contains the expiration time, it represents a
         * time-to-live value.
         * <p>
         * {@code (BORN_TIMESTAMP ~ BORN_TIMESTAMP + TIMEOUT)} represents a relative valid interval
         * that a message can be delivered in it.
         * If the TIMEOUT field is specified as zero, that indicates the message does not expire.
         * <p>
         * The TIMEOUT header field has higher priority than START_TIME/STOP_TIME header fields.
         * <p>
         * When an undelivered message's expiration time is reached, the message should be destroyed.
         * OMS does not define a notification of message expiration.
         */
        static const std::string TIMEOUT = "TIMEOUT";

        /**
         * The {@code PRIORITY} header field contains the priority level of a message,
         * a message with a higher priority value should be delivered preferentially.
         * <p>
         * OMS defines a ten level priority value with 1 as the lowest priority and 10 as the highest,
         * and the default priority is 5. The priority beyond this region will be ignored.
         * <p>
         * OMS does not require or provide any guarantee that the message should be delivered
         * in priority order strictly, but the vendor should provide a best effort to
         * deliver expedited messages ahead of normal messages.
         * <p>
         * If PRIORITY field isn't set explicitly, use {@code 5} as the default priority.
         */
        static const std::string PRIORITY = "PRIORITY";

        /**
         * The {@code RELIABILITY} header field contains the reliability level of a message, the vendor
         * should guarantee the reliability level for a message.
         * <p>
         * OMS defines two modes of message delivery:
         * <ul>
         * <li>
         * PERSISTENT, the persistent mode instructs the vendor should provide stable storage to
         * ensure the message won't be lost.
         * </li>
         * <li>
         * NON_PERSISTENT, this mode does not require the message be logged to stable storage,
         * in most cases, the memory storage is enough for better performance and lower cost.
         * </li>
         * </ul>
         */
        static const std::string RELIABILITY = "RELIABILITY";

        /**
         * The {@code SEARCH_KEYS} header field contains the multiple search keys of a message.
         * <p>
         * The keyword indexes will be built by the search keys, users can query similar
         * messages through these indexes and have a quick response.
         * <p>
         * This field is a {@code String} value, the different search keys are joined
         * together with a comma delimiter.
         * <p>
         * OMS defines that a message at most has five search keys.
         */
        static const std::string SEARCH_KEYS = "SEARCH_KEYS";

        /**
         * The {@code SCHEDULE_EXPRESSION} header field contains schedule expression of a message.
         * <p>
         * The message will be delivered by the specified SCHEDULE_EXPRESSION, which is a CRON expression.
         *
         * @see <a href="https://en.wikipedia.org/wiki/Cron#CRON_expression">https://en.wikipedia.org/wiki/Cron#CRON_expression</a>
         */
        static const std::string SCHEDULE_EXPRESSION = "SCHEDULE_EXPRESSION";

        /**
         * The {@code TRACE_ID} header field contains the trace ID of a message, which represents a global and unique
         * identification, to associate key events in the whole lifecycle of a message,
         * like sent by who, stored at where, and received by who.
         * <p></p>
         * And, the messaging system only plays exchange role in a distributed system in most cases,
         * so the TraceID can be used to trace the whole call link with other parts in the whole system.
         */
        static const std::string TRACE_ID = "TRACE_ID";

        /**
         * The {@code STREAM_KEY} header field contains the stream key of a message.
         * The messages with same stream key should be dispatched to the same stream of the queue.
         */
        static const std::string STREAM_KEY = "STREAM_KEY";

        /**
         * The {@code REDELIVERED_NUMBER} header field contains a number, which represents
         * the number of message delivery.
         */
        static const std::string REDELIVERED_NUMBER = "REDELIVERED_NUMBER";

        /**
         * The {@code REDELIVERED_REASON} header field contains the text description of the reason that causes
         * the last message delivery retry.
         */
        static const std::string REDELIVERED_REASON = "REDELIVERED_REASON";

        /**
         * The {@code DRIVER_IMPL} key represents the vendor implementation
         * entry of {@link MessagingAccessPoint}.
         */
        static const std::string DRIVER_IMPL = "DRIVER_IMPL";

        /**
         * The {@code ACCESS_POINTS} key shows the specified access points in OMS driver schema.
         * @see <a href="https://github.com/openmessaging/specification/blob/master/oms_access_point_schema.md">Access Point Schema</a>
         */
        static const std::string ACCESS_POINTS = "ACCESS_POINTS";

        /**
         * The {@code ACCOUNT_ID} key shows the specified account info in OMS driver schema.
         */
        static const std::string ACCOUNT_ID = "ACCOUNT_ID";

        /**
         * The {@code REGION} key shows the specified region in OMS driver schema.
         */
        static const std::string REGION = "REGION";

        /**
         * The {@code PRODUCER_ID} key represents the the unique producer id of a producer instance.
         */
        static const std::string PRODUCER_ID = "PRODUCER_ID";

        /**
         * The {@code CONSUMER_ID} key represents the the unique consumer id of a consumer instance.
         */
        static const std::string CONSUMER_ID = "CONSUMER_ID";

        /**
         * The {@code OPERATION_TIMEOUT} key defines the timeout of almost all the method calls in OMS.
         */
        static const std::string OPERATION_TIMEOUT = "OPERATION_TIMEOUT";

        /**
         * The {@code ROUTING_SOURCE} key shows the source queue of a {@code Routing} instance.
         * <p>
         * The {@code Routing} consists of a triple, include source queue, destination queue and expression.
         */
        static const std::string ROUTING_SOURCE = "ROUTING_SOURCE";

        /**
         * The {@code ROUTING_DESTINATION} key shows the destination queue of a {@code Routing} instance.
         * <p>
         * The {@code Routing} consists of a triple, include source queue, destination queue and expression.
         */
        static const std::string ROUTING_DESTINATION = "ROUTING_DESTINATION";

        /**
         * The {@code ROUTING_EXPRESSION} key shows the expression of a {@code Routing} instance.
         * <p>
         * The {@code Routing} consists of a triple, include source queue, destination queue and expression.
         */
        static const std::string ROUTING_EXPRESSION = "ROUTING_EXPRESSION";

END_NAMESPACE_2(io, openmessaging)
#endif // OMS_BUILTIN_KEYS_H
