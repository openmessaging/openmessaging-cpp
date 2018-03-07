#ifndef OMS_LOCAL_TRANSACTION_EXECUTION_CONTEXT_H
#define OMS_LOCAL_TRANSACTION_EXECUTION_CONTEXT_H

#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, producer)

    class LocalTransactionExecutionContext : private Uncopyable {
    public:
        virtual ~LocalTransactionExecutionContext() {

        }

        virtual void commit() = 0;

        virtual void rollback() = 0;

    };

END_NAMESPACE_3(io, openmessaging, producer)

#endif //OMS_LOCAL_TRANSACTION_EXECUTION_CONTEXT_H
