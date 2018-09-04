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

#ifndef OMS_MESSAGING_ACCESS_POINT_H
#define OMS_MESSAGING_ACCESS_POINT_H

#include <string>

#include "ServiceLifecycle.h"
#include "KeyValue.h"
#include "producer/Producer.h"
#include "consumer/PullConsumer.h"
#include "consumer/PushConsumer.h"
#include "manager/ResourceManager.h"
#include "observer/Observer.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * An instance of {@code MessagingAccessPoint} may be obtained from {@link OMS}, which is capable of creating {@code
     * Producer}, {@code Consumer}, {@code ResourceManager}, and other facility entities.
     * <p>
     * For example:
     * <pre>
     * MessagingAccessPoint* accessPoint = getMessagingAccessPoint("oms:rocketmq://alice@rocketmq.apache.org/us-east:default_space");
     * accessPoint->startup();
     * ProducerPtr producer = accessPoint->createProducer();
     * producer->startup();
     * const char* body = "Hello OMS";
     * MessagePtr msg = producer->createBytesMessage("HELLO_QUEUE", MessageBody(body, strlen(body));
     * producer->send(msg);
     * </pre>
     *
     * @version OMS 1.0.0
     * @since OMS 1.0.0
     */
    class MessagingAccessPoint : public virtual ServiceLifecycle {
    public:
        virtual ~MessagingAccessPoint() {

        }

        /**
        * Returns the target OMS specification version of the specified vendor implementation.
        *
        * @return the OMS version of implementation
        * @see OMS#specVersion
        */
        virtual std::string version() = 0;

        /**
         * Returns the attributes of this {@code MessagingAccessPoint} instance.
         * <p>
         * There are some standard attributes defined by OMS for {@code MessagingAccessPoint}:
         * <ul>
         * <li> {@link OMSBuiltinKeys#ACCESS_POINTS}, the specified access points.
         * <li> {@link OMSBuiltinKeys#DRIVER_IMPL}, the fully qualified class name of the specified MessagingAccessPoint's
         * implementation, the default value is {@literal io.openmessaging.<driver_type>.MessagingAccessPointImpl}.
         * <li> {@link OMSBuiltinKeys#NAMESPACE}, the namespace the OMS resource resides in.
         * <li> {@link OMSBuiltinKeys#REGION}, the region the namespace resides in.
         * <li> {@link OMSBuiltinKeys#ACCOUNT_ID}, the ID of the specific account system that owns the resource.
         * </ul>
         *
         * @return the attributes
         */
        virtual KeyValuePtr attributes() = 0;

        /**
         * Creates a new {@code Producer} for the specified {@code MessagingAccessPoint}.
         *
         * @return the created {@code Producer}
         * @throws OMSRuntimeException if the {@code MessagingAccessPoint} fails to handle this request
         * due to some internal error
         */
        virtual producer::ProducerPtr createProducer() = 0;
        virtual producer::ProducerPtr createProducer(const TransactionStateCheckListenerPtr &transactionStateCheckListener) = 0;

        /**
         * Creates a new {@code PushConsumer} for the specified {@code MessagingAccessPoint}.
         * The returned {@code PushConsumer} isn't attached to any queue,
         * uses {@link PushConsumer#attachQueue(String, MessageListener)} to attach queues.
         *
         * @return the created {@code PushConsumer}
         * @throws OMSRuntimeException if the {@code MessagingAccessPoint} fails to handle this request
         * due to some internal error
         */
        virtual consumer::PushConsumerPtr createConsumer() = 0;

        /**
         * Gets a lightweight {@code ResourceManager} instance from the specified {@code MessagingAccessPoint}.
         *
         * @return the resource manger
         * @throws OMSRuntimeException if the {@code MessagingAccessPoint} fails to handle this request
         * due to some internal error
         */
        virtual ResourceManagerPtr resourceManager() = 0;
    };

    typedef NS::shared_ptr<MessagingAccessPoint> MessagingAccessPointPtr;

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_MESSAGING_ACCESS_POINT_H
