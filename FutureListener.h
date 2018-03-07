#ifndef OMS_FUTURE_LISTENER_H
#define OMS_FUTURE_LISTENER_H

#include <boost/smart_ptr.hpp>

#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    class Future;

    class FutureListener : private Uncopyable {
    public:
        virtual ~FutureListener() {

        }

        virtual void operationComplete(const Future& future) = 0;
    };

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_FUTURE_LISTENER_H
