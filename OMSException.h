#ifndef OMS_EXCEPTION_H
#define OMS_EXCEPTION_H

#include <exception>
#include <string>
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        class OMSException : public std::exception {
        public:
            OMSException(const std::string &reason = "Unknown") : _reason(reason) {

            }

            const char *what() {
                return _reason.c_str();
            }

        private:
            string _reason;
        };

END_NAMESPACE_2(io, openmessaging)
#endif //OMS_EXCEPTION_H
