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

#ifndef OMS_RESOURCE_MANAGER_H
#define OMS_RESOURCE_MANAGER_H

#include <string>

#include "../smart_pointer.h"
#include "../ServiceLifecycle.h"
#include "../KeyValue.h"
#include "../routing/Routing.h"
#include "../Namespace.h"

BEGIN_NAMESPACE_3(io, openmessaging, manager)

    /**
     * The {@code ResourceManager} is to provide a unified interface of resource management,
     * allowing developers to manage the namespace, queue and routing resources.
     * <p>
     * Create, set, get and delete are the four basic operations of {@code ResourceManager}.
     * <p>
     * {@code ResourceManager} also supports fetching and updating resource attributes dynamically.
     * <p>
     * {@link MessagingAccessPoint#resourceManager()} ()} is the unique method to obtain a {@code ResourceManager}
     * instance. Changes made through this instance will immediately apply to the message-oriented middleware (MOM) behind
     * {@code MessagingAccessPoint}.
     * <p>
     * All operations conducted via this instance are confined to the configured namespace,
     * with default namespace derived from the OMS driver url of {@code MessagingAccessPoint}.Change namespace
     * by {@link ResourceManager#switchNamespace(String)} whenever necessary.
     *
     * @version OMS 1.0.0
     * @since OMS 1.0.0
     */
    class ResourceManager : public virtual Uncopyable {
    public:
        virtual ~ResourceManager() {

        }

        /**
         * Creates a {@code Namespace} resource with some preset attributes.
         *
         * @param ns the name of the new namespace
         */
        virtual void createNamespace(const std::string &ns) = 0;

        /**
         * Deletes an existing namespace resource.
         *
         * @param ns the namespace to delete
         */
        virtual void deleteNamespace(const std::string &ns) = 0;

        /**
         * Gets the namespace list in the current {@code MessagingAccessPoint}.
         *
         * @return the list of all namespaces
         */
        virtual std::vector<std::string> listNamespaces() = 0;

        /**
         * Switches the default namespace to the new one, and all the operations will reflect to
         * the new namespace after the method returns successfully.
         *
         * @param ns the target namespace to switch to
         */
        virtual void switchNamespace(const std::string &ns) = 0;

        /**
         * Creates a {@code Queue} resource in the configured namespace with some preset attributes.
         *
         * @param queueName the name of the new queue
         * @param attributes the preset attributes
         */
        virtual void createQueue(const std::string &ns, const std::string &queue, KeyValuePtr attributes) = 0;

        /**
         * Deletes an existing queue resource.
         *
         * @param queueName the queue needs to be deleted
         */
        virtual void deleteQueue(const std::string &queue) = 0;

        /**
         * Gets the queue list in the configured namespace.
         *
         * @return the list of all queues
         */
        virtual std::vector<std::string> listQueues() = 0;

        /**
         * Routing from sourceQueue to targetQueue. Both queues are could be received messages after creating route action.
         *
         * @param sourceQueue source queue, process messages received from producer and duplicate those to target queue.
         * @param targetQueue receive messages from source queue.
         */
        virtual void routing(const std::string &sourceQueue, const std::string &targetQueue) = 0;

        /**
         * In order to enable consumers to get the message in the specified mode, the filter rule follows the sql standard
         * to filter out messages.
         *
         * @param queueName queue name.
         * @param filterString SQL expression to filter out messages.
         */
        virtual void filter(const std::string &queue, const std::string &filter) = 0;


    };

    typedef NS::shared_ptr<ResourceManager> ResourceManagerPtr;

END_NAMESPACE_3(io, openmessaging, manager)

#endif // OMS_RESOURCE_MANAGER_H
