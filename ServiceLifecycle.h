#ifndef SERVICELIFECYCLE_H
#define SERVICELIFECYCLE_H

#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        class ServiceLifecycle {
        public:
            virtual void startup() = 0;

            virtual void shutdown() = 0;

            virtual ~ServiceLifecycle() {
            }
        };

END_NAMESPACE_2(io, openmessaging)

#endif // SERVICELIFECYCLE_H
