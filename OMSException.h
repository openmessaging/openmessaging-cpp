#ifndef OMS_OMS_EXCEPTION_H
#define OMS_OMS_EXCEPTION_H

#include <string>
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        class OMSException {
        public:
            OMSException(const std::string &reason = "Unknown Reason")
                    : _reason(reason) {

            }

            const char *what() const {
                return _reason.c_str();
            }

        private:
            const std::string _reason;
        };

END_NAMESPACE_2(io, openmessaging)
#endif //OMS_OMS_EXCEPTION_H
