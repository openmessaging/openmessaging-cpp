//
// Created by Li Zhanhui on 2018/1/13.
//

#ifndef OMS_BUILTINKEYS_H
#define OMS_BUILTINKEYS_H

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

        const std::string BuiltinKeys::MessageId = "MessageId";
        const std::string BuiltinKeys::Topic = "Topic";
        const std::string BuiltinKeys::Queue = "Queue";
        const std::string BuiltinKeys::BornTimestamp = "BornTimestamp";
        const std::string BuiltinKeys::BornHost = "BornHost";
        const std::string BuiltinKeys::StoreTimestamp = "StoreTimestamp";
        const std::string BuiltinKeys::StoreHost = "StoreHost";
        const std::string BuiltinKeys::StartTime = "StartTime";
        const std::string BuiltinKeys::StopTime = "StopTime";
        const std::string BuiltinKeys::Timeout = "Timeout";
        const std::string BuiltinKeys::Priority = "Priority";
        const std::string BuiltinKeys::Reliability = "Reliability";
        const std::string BuiltinKeys::SearchKey = "SearchKey";
        const std::string BuiltinKeys::ScheduleExpression = "ScheduleExpression";
        const std::string BuiltinKeys::TraceId = "TraceId";
        const std::string BuiltinKeys::Stream = "Stream";
END_NAMESPACE_2(io, openmessaging)
#endif //OMS_BUILTINKEYS_H
