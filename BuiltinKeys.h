#ifndef OMS_BUILTIN_KEYS_H
#define OMS_BUILTIN_KEYS_H

#include <string>
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        class BuiltinKeys {
        public:
            static const std::string MessageId;

            static const std::string Topic;

            static const std::string Queue;

            static const std::string BornTimestamp;

            static const std::string BornHost;

            static const std::string StoreTimestamp;

            static const std::string StoreHost;

            static const std::string StartTime;

            static const std::string StopTime;

            static const std::string Timeout;

            static const std::string Priority;

            static const std::string Reliability;

            static const std::string SearchKey;

            static const std::string ScheduleExpression;

            static const std::string TraceId;

            static const std::string Stream;
        };

END_NAMESPACE_2(io, openmessaging)
#endif // OMS_BUILTIN_KEYS_H
