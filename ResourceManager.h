#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>

#include <boost/shared_ptr.hpp>

#include "ServiceLifecycle.h"
#include "KeyValue.h"
#include "routing/Routing.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        class ResourceManager : public virtual ServiceLifecycle {
        public:
            virtual ~ResourceManager() {

            }

            virtual void createNamespace(const std::string &ns, boost::shared_ptr<KeyValue> attributes) = 0;

            virtual void setNamespaceAttributes(const std::string &ns, boost::shared_ptr<KeyValue> attributes) = 0;

            virtual boost::shared_ptr<KeyValue> getNamespaceAttributes(const std::string &ns) = 0;

            virtual void deleteNamespace(const std::string &ns) = 0;

            virtual std::vector<std::string> listNamespaces() = 0;

            virtual void createTopic(const std::string &ns, const std::string &topic,
                                     boost::shared_ptr<KeyValue> attributes) = 0;

            virtual void setTopicAttributes(const std::string &ns, const std::string &topic,
                                            boost::shared_ptr<KeyValue> attributes) = 0;

            virtual boost::shared_ptr<KeyValue> getTopicAttributes(const std::string &ns, const std::string &topic) = 0;

            virtual void deleteTopic(const std::string &ns, const std::string &topic) = 0;

            virtual std::vector<std::string> listTopics(std::string &ns) = 0;

            virtual void createQueue(const std::string &ns, const std::string &queue,
                                     boost::shared_ptr<KeyValue> attributes) = 0;

            virtual void setQueueAttributes(const std::string &ns, const std::string &queue,
                                            boost::shared_ptr<KeyValue> attributes) = 0;

            virtual boost::shared_ptr<KeyValue> getQueueAttributes(const std::string &ns, const std::string &queue) = 0;

            virtual void deleteQueue(const std::string &ns, const std::string &queue) = 0;

            virtual std::vector<std::string> listQueues(std::string &ns) = 0;

            virtual void createRouting(const std::string &ns, boost::shared_ptr<routing::Routing> route) = 0;

            virtual void updateRouting(const std::string &ns, boost::shared_ptr<routing::Routing> route) = 0;

            virtual boost::shared_ptr<routing::Routing> getRouting(const std::string &ns, const std::string &route) = 0;

            virtual void deleteRouting(const std::string &ns, const std::string &route) = 0;

            virtual std::vector<boost::shared_ptr<routing::Routing> > listRoutings(const std::string &ns) = 0;

            virtual void updateMessage(const std::string &messageId, boost::shared_ptr<KeyValue> headers) = 0;
        };

END_NAMESPACE_2(io, openmessaging)

#endif // RESOURCEMANAGER_H
