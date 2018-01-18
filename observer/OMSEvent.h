//
// Created by Li Zhanhui on 2018/1/13.
//

#ifndef OMS_OMSEVENT_H
#define OMS_OMSEVENT_H
#include "Namespace.h"

BEGIN_NAMESPACE_3(io, openmessaging, observer)

            class OMSEvent {
            public:
                virtual ~OMSEvent() {

                }

                virtual std::string type() = 0;

                virtual std::string details() = 0;
            };

END_NAMESPACE_3(io, openmessaging, observer)
#endif //OMS_OMSEVENT_H
