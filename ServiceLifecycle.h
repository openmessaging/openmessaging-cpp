#ifndef OMS_SERVICE_LIFECYCLE_H
#define OMS_SERVICE_LIFECYCLE_H

#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * The {@code ServiceLifecycle} defines a lifecycle interface for a OMS related service endpoint, like {@link Producer},
     * {@link PushConsumer}, and so on.
     * <p>
     * If the service endpoint class implements the {@code ServiceLifecycle} interface, most of the containers can manage
     * the lifecycle of the corresponding service endpoint objects easily.
     * <p>
     * Any service endpoint should support repeated restart if it implements the {@code ServiceLifecycle} interface.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class ServiceLifecycle : private Uncopyable {
    public:
        virtual void startup() = 0;

        virtual void shutdown() = 0;

        virtual ~ServiceLifecycle() {
        }
    };

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_SERVICE_LIFECYCLE_H
