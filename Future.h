#ifndef OMS_FUTURE_H
#define OMS_FUTURE_H

#include <exception>
#include <boost/shared_ptr.hpp>

#include "SendResult.h"
#include "Namespace.h"
BEGIN_NAMESPACE_2(io, openmessaging)

        class Future {
        public:
            virtual ~Future() {

            }

            virtual bool isCancelled() = 0;

            virtual bool isDone() = 0;

            boost::shared_ptr<producer::SendResult> get() = 0;

            boost::shared_ptr<producer::SendResult> get(long timeout) = 0;

            Future &addListener(boost::function<void(Future &)> f) = 0;

            std::exception &getThrowable() = 0;

        };

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_FUTURE_H
