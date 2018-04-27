#ifndef OMS_EXECUTION_CONTEXT_H
#define OMS_EXECUTION_CONTEXT_H

#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, producer)

    class ExecutionContext : private Uncopyable {
    public:
        virtual ~ExecutionContext() {

        }

        virtual void commit() = 0;

        virtual void rollback() = 0;

    };

    typedef NS::shared_ptr<ExecutionContext> ExecutionContextPtr;

END_NAMESPACE_3(io, openmessaging, producer)

#endif //OMS_EXECUTION_CONTEXT_H
