/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OMS_HEADERS_H
#define OMS_HEADERS_H

#include <string>

#include "smart_pointer.h"
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
    class Headers : private Uncopyable {
    public:
        virtual ~Headers() {

        }

        /**
         * The {@code DESTINATION} header field contains the destination to which the message is being sent.
         * <p>
         * When a message is sent this value is set to the right {@code Queue}, then the message will be sent to the
         * specified destination.
         * <p>
         * When a message is received, its destination is equivalent to the {@code Queue} where the message resides in.
         */
        virtual Headers &setDestination(const std::string &destination) = 0;

        /**
         * The {@code MESSAGE_ID} header field contains a value that uniquely identifies each message sent by a {@code
         * Producer}.
         */
        virtual Headers &setMessageId(const std::string &messageId) = 0;

        /**
         * The {@code BORN_TIMESTAMP} header field contains the time a message was handed off to a {@code Producer} to
         * be sent.
         * <p>
         * When a message is sent, BORN_TIMESTAMP will be set with current timestamp as the born timestamp of a message
         * in client side, on return from the send method, the message's BORN_TIMESTAMP header field contains this
         * value.
         * <p>
         * When a message is received its, BORN_TIMESTAMP header field contains this same value.
         * <p>
         * This filed is a {@code long} value, measured in milliseconds.
         */
        virtual Headers &setBornTimestamp(long bornTimestamp) = 0;

        /**
         * The {@code BORN_HOST} header field contains the born host info of a message in client side.
         * <p>
         * When a message is sent, BORN_HOST will be set with the local host info, on return from the send method, the
         * message's BORN_HOST header field contains this value.
         * <p>
         * When a message is received, its BORN_HOST header field contains this same value.
         */
        virtual Headers &setBornHost(const std::string &bornHost) = 0;

        /**
         * The {@code STORE_TIMESTAMP} header field contains the store timestamp of a message in server side.
         * <p>
         * When a message is sent, STORE_TIMESTAMP is ignored.
         * <p>
         * When the send method returns it contains a server-assigned value.
         * <p>
         * This filed is a {@code long} value, measured in milliseconds.
         */
        virtual Headers &setStoreTimestamp(long storeTimestamp) = 0;

        /**
         * The {@code STORE_HOST} header field contains the store host info of a message in server side.
         * <p>
         * When a message is sent, STORE_HOST is ignored.
         * <p>
         * When the send method returns it contains a server-assigned value.
         */
        virtual Headers &setStoreHost(const std::string &storeHost) = 0;

        /**
         * The {@code DELAY_TIME} header field contains a number that represents the delayed times in milliseconds.
         * <p></p>
         * The message will be delivered after delayTime milliseconds starting from {@CODE BORN_TIMESTAMP} . When this
         * filed isn't set explicitly, this means this message should be delivered immediately.
         */
        virtual Headers &setDelayTime(long delayTime) = 0;

        /**
         * The {@code EXPIRE_TIME} header field contains the expiration time, it represents a time-to-live value.
         * <p>
         * The {@code EXPIRE_TIME} represents a relative valid interval that a message can be delivered in it. If the
         * EXPIRE_TIME field is specified as zero, that indicates the message does not expire.
         * </p>
         * <p>
         * When an undelivered message's expiration time is reached, the message should be destroyed. OMS does not
         * define a notification of message expiration.
         * </p>
         */
        virtual Headers &setExpireTime(long expireTime) = 0;

        /**
         * The {@code PRIORITY} header field contains the priority level of a message, a message with a higher priority
         * value should be delivered preferentially.
         * <p>
         * OMS defines a ten level priority value with 1 as the lowest priority and 10 as the highest, and the default
         * priority is 5. The priority beyond this region will be ignored.
         * <p>
         * OMS does not require or provide any guarantee that the message should be delivered in priority order
         * strictly, but the vendor should provide a best effort to deliver expedited messages ahead of normal
         * messages.
         * <p>
         * If PRIORITY field isn't set explicitly, use {@code 5} as the default priority.
         */
        virtual Headers &setPriority(short priority) = 0;

        /**
         * The {@code RELIABILITY} header field contains the reliability level of a message, the vendor should guarantee
         * the reliability level for a message.
         * <p>
         * OMS defines two modes of message delivery:
         * <ul>
         * <li>
         * PERSISTENT, the persistent mode instructs the vendor should provide stable storage to ensure the message
         * won't be lost.
         * </li>
         * <li>
         * NON_PERSISTENT, this mode does not require the message be logged to stable storage, in most cases, the memory
         * storage is enough for better performance and lower cost.
         * </li>
         * </ul>
         */
        virtual Headers &setDurability(short durability) = 0;

        /**
         * The {@code messagekey} header field contains the custom key of a message.
         * <p>
         * This key is a customer identifier for a class of messages, and this key may be used for server to hash or
         * dispatch messages, or even can use this key to implement order message.
         * <p>
         */
        virtual Headers &setMessageKey(const std::string &messageKey) = 0;

        /**
         * The {@code TRACE_ID} header field contains the trace ID of a message, which represents a global and unique
         * identification, to associate key events in the whole lifecycle of a message, like sent by who, stored at
         * where, and received by who.
         * <p></p>
         * And, the messaging system only plays exchange role in a distributed system in most cases, so the TraceID can
         * be used to trace the whole call link with other parts in the whole system.
         */
        virtual Headers &setTraceId(const std::string &traceId) = 0;

        /**
         * The {@code DELIVERY_COUNT} header field contains a number, which represents the count of the message
         * delivery.
         */
        virtual Headers &setDeliveryCount(short deliveryCount) = 0;

        /**
         * This field {@code TRANSACTION_ID} is used in transactional message, and it can be used to trace a
         * transaction.
         * <p></p>
         * So the same {@code TRANSACTION_ID} will be appeared not only in prepare message, but also in commit message,
         * and consumer received message also contains this field.
         */
        virtual Headers &setTransactionId(const std::string &transactionId) = 0;

        /**
         * A client can use the {@code CORRELATION_ID} field to link one message with another. A typical use is to link
         * a response message with its request message.
         */
        virtual Headers &setCorrelationId(const std::string &scorrelationId) = 0;

        /**
         * The field {@code COMPRESSION} in headers represents the message body compress algorithm. vendors are free to
         * choose the compression algorithm, but must ensure that the decompressed message is delivered to the user.
         */
        virtual Headers &setCompression(short compression) = 0;

        /**
         * See {@link Headers#setDestination(String)}
         *
         * @return destination
         */
        virtual std::string getDestination() = 0;

        /**
         * See {@link Headers#setMessageId(String)}
         *
         * @return messageId
         */
        virtual std::string getMessageId() = 0;

        /**
         * See {@link Headers#setBornTimestamp(long)}
         *
         * @return bornTimestamp
         */
        virtual long getBornTimestamp() = 0;

        /**
         * See {@link Headers#setBornHost(String)}
         *
         * @return bornHost
         */
        virtual std::string getBornHost() = 0;

        /**
         * See {@link Headers#setStoreTimestamp(long)}
         *
         * @return storeTimestamp
         */
        virtual long getStoreTimestamp() = 0;

        /**
         * See {@link Headers#setStoreHost(String)}
         *
         * @return storeHost
         */
        virtual std::string getStoreHost() = 0;

        /**
         * See {@link Headers#setDelayTime(long)}
         *
         * @return delayTime
         */
        virtual long getDelayTime() = 0;

        /**
         * See {@link Headers#setExpireTime(long)}
         *
         * @return expireTime
         */
        virtual long getExpireTime() = 0;

        /**
         * See {@link Headers#setPriority(short)}
         *
         * @return priority
         */
        virtual short getPriority() = 0;

        /**
         * See {@link Headers#setDurability(short)}
         *
         * @return durability
         */
        virtual short getDurability() = 0;

        /**
         * See {@link Headers#setMessageKey(String)}
         *
         * @return messageKey
         */
        virtual std::string getMessageKey() = 0;

        /**
         * See {@link Headers#setTraceId(String)}
         *
         * @return traceId
         */
        virtual std::string getTraceId() = 0;

        /**
         * See {@link Headers#setDeliveryCount(int)}
         *
         * @return deliveryCount
         */
        virtual short getDeliveryCount() = 0;

        /**
         * See {@link Headers#setTransactionId(String)}
         *
         * @return transactionId
         */
        virtual std::string getTransactionId() = 0;

        /**
         * See {@link Headers#setCorrelationId(String)}
         *
         * @return correlationId
         */
        virtual std::string getCorrelationId() = 0;

        /**
         * See {@link Headers#setCompression(short)}
         *
         * @return compression
         */
        virtual short getCompression() = 0;

    };

    typedef NS::shared_ptr<Headers> HeadersPtr;

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_HEADERS_H
