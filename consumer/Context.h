#ifndef OMS_CONTEXT_H
#define OMS_CONTEXT_H

#include <boost/shared_ptr.hpp>

#include "KeyValue.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)
        extern boost::shared_ptr<KeyValue> kv_nullptr;
        BEGIN_NAMESPACE_1(consumer)
            class Context {
            public:
                virtual ~Context() {
                }

                virtual boost::shared_ptr <KeyValue> properties() = 0;

                virtual void ack(boost::shared_ptr <KeyValue> properties = kv_nullptr) = 0;
            };

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_CONTEXT_H
