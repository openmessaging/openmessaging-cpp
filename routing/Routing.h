#ifndef OMS_ROUTING_H
#define OMS_ROUTING_H

#include <string>

#include "ServiceLifecycle.h"
#include "ServiceLifecycle.h"
#include "Namespace.h"
BEGIN_NAMESPACE_3(io, openmessaging, routing)
            class Routing : public virtual ServiceLifecycle {
            public:
                virtual ~Routing() {

                }

                virtual boost::shared_ptr <KeyValue> properties() = 0;

                virtual std::string source() = 0;

                virtual std::string destination() = 0;

                virtual std::string expression() = 0;

                virtual std::string routingName() = 0;
            };

END_NAMESPACE_3(io, openmessaging, routing)

#endif //OMS_ROUTING_H
