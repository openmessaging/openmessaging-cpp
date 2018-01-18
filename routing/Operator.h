#ifndef OMS_OPERATOR_H
#define OMS_OPERATOR_H

#include <boost/shared_ptr.hpp>

#include "KeyValue.h"
#include "Namespace.h"

BEGIN_NAMESPACE_3(io, openmessaging, routing)
            class Operator {
            public:
                virtual ~Operator() {

                }

                virtual boost::shared_ptr<KeyValue> properties() = 0;

                virtual std::string expression() = 0;
            };
END_NAMESPACE_3(io, openmessaging, routing)

#endif //OMS_OPERATOR_H
