#ifndef OMS_CONTEXT_H
#define OMS_CONTEXT_H

#include "Namespace.h"
#include "OMS.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

        class Context : private Uncopyable {
        public:
            virtual ~Context() {
            }

            virtual KeyValuePtr attributes() = 0;

            virtual void ack() = 0;
        };

    typedef NS::shared_ptr<Context> ContextPtr;

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_CONTEXT_H
