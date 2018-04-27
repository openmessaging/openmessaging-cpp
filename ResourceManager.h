#ifndef OMS_RESOURCE_MANAGER_H
#define OMS_RESOURCE_MANAGER_H

#include <string>

#include "smart_pointer.h"
#include "ServiceLifecycle.h"
#include "KeyValue.h"
#include "routing/Routing.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

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
         * @param nsName the name of the new namespace
         * @param attributes the preset attributes
         */
        virtual void createNamespace(const std::string &ns, KeyValuePtr &attributes) = 0;

        /**
         * Sets the attributes of the configured namespace, the old attributes will be replaced
         * by the provided attributes, only the provided key will be updated.
         *
         * @param attributes the new attributes
         * @throws OMSResourceNotExistException if the configured namespace does not exist
         */
        virtual void setNamespaceAttributes(const KeyValuePtr &attributes) = 0;

        /**
         * Gets the attributes of the configured namespace.
         *
         * @return the attributes of namespace
         * @throws OMSResourceNotExistException if the configured namespace does not exist
         */
        virtual KeyValuePtr getNamespaceAttributes() = 0;

        /**
         * Deletes an existing namespace resource.
         *
         * @param ns the namespace to delete
         * @throws OMSResourceNotExistException if the specified namespace does not exist
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
         * @throws OMSResourceNotExistException if the new namespace does not exist
         */
        virtual void switchNamespace(const std::string &ns) = 0;

        /**
         * Creates a {@code Queue} resource in the configured namespace with some preset attributes.
         *
         * @param queueName the name of the new queue
         * @param attributes the preset attributes
         * @throws OMSResourceNotExistException if the specified queue name is duplicated
         */
        virtual void createQueue(const std::string &ns, const std::string &queue, KeyValuePtr attributes) = 0;

        /**
         * Sets the attributes of the specified queue, the old attributes will be replaced
         * by the provided attributes, only the provided key will be updated.
         *
         * @param queueName the queue name
         * @param attributes the new attributes
         * @throws OMSResourceNotExistException if the specified queue does not exist
         */
        virtual void setQueueAttributes(const std::string &ns, const std::string &queue, KeyValuePtr attributes) = 0;

        /**
         * Gets the attributes of the specified queue.
         *
         * @param queueName the queue name
         * @return the attributes of namespace
         * @throws OMSResourceNotExistException if the specified queue or namespace does not exist
         */
        virtual KeyValuePtr getQueueAttributes(const std::string &ns, const std::string &queue) = 0;

        /**
         * Deletes an existing queue resource.
         *
         * @param queueName the queue needs to be deleted
         * @throws OMSResourceNotExistException if the specified queue or namespace does not exist
         */
        virtual void deleteQueue(const std::string &queue) = 0;

        /**
         * Gets the queue list in the configured namespace.
         *
         * @return the list of all queues
         */
        virtual std::vector<std::string> listQueues() = 0;

        /**
         * Creates a {@code Routing} resource in the configured namespace with some preset attributes.
         *
         * @param routingName the name of the new routing
         * @param attributes the preset attributes
         * @throws OMSResourceNotExistException if the configured namespace is not exists
         */
        virtual void createRouting(const std::string &routingName, const KeyValuePtr &attributes) = 0;

        /**
         * Sets the attributes of the specified routing, the old attributes will be replaced
         * by the provided attributes, only the provided key will be updated.
         *
         * @param routingName the routing name
         * @param attributes the new attributes
         * @throws OMSResourceNotExistException if the specified routing or namespace is not exists
         */
        virtual void setRoutingAttributes(const std::string &routingName, const KeyValuePtr &attributes) = 0;

        /**
         * Gets the attributes of the specified routing.
         *
         * @param routingName the routing name
         * @return the attributes of routing
         * @throws OMSResourceNotExistException if the specified routing or namespace is not exists
         */
        virtual KeyValuePtr getRoutingAttributes(const std::string &queueName) = 0;

        /**
         * Deletes an existing routing resource.
         *
         * @param routingName the routing needs to be deleted
         * @throws OMSResourceNotExistException if the specified routing or namespace is not exists
         */
        virtual void deleteRouting(const std::string &ns, const std::string &route) = 0;

        /**
         * Gets the routing list in the configured namespace.
         *
         * @return the list of all routings
         * @throws OMSResourceNotExistException if the configured namespace is not exists
         */
        virtual std::vector<routing::RoutingPtr> listRoutings(const std::string &ns) = 0;

        /**
         * Gets the stream list behind the specified queue.
         *
         * @param queueName the queue name
         * @return the list of all streams
         */
        virtual std::vector<std::string> listStreams(const std::string &queueName) = 0;

        /**
         * Updates some system headers of a message in the configured namespace.
         * <p>
         * Below system headers are allowed to be changed dynamically:
         * <ul>
         * <li>{@link Message.BuiltinKeys#START_TIME}</li>
         * <li>{@link Message.BuiltinKeys#STOP_TIME}</li>
         * <li>{@link Message.BuiltinKeys#TIMEOUT}</li>
         * <li>{@link Message.BuiltinKeys#PRIORITY}</li>
         * <li>{@link Message.BuiltinKeys#SCHEDULE_EXPRESSION}</li>
         * </ul>
         *
         * @param messageId the id of message
         * @param headers the new headers
         */
        virtual void updateMessage(const std::string &messageId, KeyValuePtr &headers) = 0;
    };

    typedef NS::shared_ptr<ResourceManager> ResourceManagerPtr;

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_RESOURCE_MANAGER_H
