#ifndef OMS_OPERATOR_H
#define OMS_OPERATOR_H

#include "smart_pointer.h"
#include "KeyValue.h"
#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, routing)

    /**
     * A {@code Operator} is used to handle the flowing messages in {@code Routing}.
     *
     * There are many kinds of {@code Operator}, expression operator, deduplicate operator,
     * joiner operator, filter operator, rpc operator, and so on.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Operator : private Uncopyable {
    public:
        virtual ~Operator() {

        }

        virtual KeyValuePtr properties() = 0;

        virtual std::string expression() = 0;
    };
    typedef NS::shared_ptr<Operator> OperatorPtr;

END_NAMESPACE_3(io, openmessaging, routing)

#endif //OMS_OPERATOR_H
