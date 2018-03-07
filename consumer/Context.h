#ifndef OMS_CONTEXT_H
#define OMS_CONTEXT_H

#include <boost/shared_ptr.hpp>

#include "KeyValue.h"
#include "Namespace.h"
#include "OMS.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

        class Context : private Uncopyable {
        public:
            virtual ~Context() {
            }

            virtual boost::shared_ptr<KeyValue> properties() = 0;

            virtual void ack(boost::shared_ptr<KeyValue> props = kv_nullptr) = 0;
        };

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_CONTEXT_H
