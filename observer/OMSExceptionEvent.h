#ifndef OMS_OMS_EXCEPTION_EVENT_H
#define OMS_OMS_EXCEPTION_EVENT_H

#include "OMSEvent.h"
#include "Namespace.h"
BEGIN_NAMESPACE_3(io, openmessaging, observer)

    /**
     * Special {@link OMSEvent} which is abnormal.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class OMSExceptionEvent : public virtual OMSEvent {
    public:
        virtual ~OMSExceptionEvent() {

        }
    };

END_NAMESPACE_3(io, openmessaging, observer)
#endif //OMS_OMS_EXCEPTION_EVENT_H
