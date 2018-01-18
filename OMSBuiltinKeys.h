#ifndef OMS_OMSBUILTINKEYS_H
#define OMS_OMSBUILTINKEYS_H

#include <string>
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        class OMSBuiltinKeys {
        public:
            const static std::string DRIVER_IMPL;
            const static std::string ACCESS_POINTS;
            const static std::string NAMESPACE;
            const static std::string ACCOUNT_ID;
            const static std::string REGION;
            const static std::string PRODUCER_ID;
            const static std::string CONSUMER_ID;
            const static std::string OPERATION_TIMEOUT;
            const static std::string BEGIN_OFFSET;
            const static std::string END_OFFSET;
            const static std::string BEGIN_TIMESTAMP;
            const static std::string END_TIMESTAMP;
        };

        const static std::string OMSBuiltinKeys::DRIVER_IMPL = "oms.driver.impl";
        const static std::string OMSBuiltinKeys::ACCESS_POINTS = "oms.access.points";
        const static std::string OMSBuiltinKeys::NAMESPACE = "oms.namespace";
        const static std::string OMSBuiltinKeys::ACCOUNT_ID = "oms.account.id";
        const static std::string OMSBuiltinKeys::REGION = "oms.region";
        const static std::string OMSBuiltinKeys::PRODUCER_ID = "oms.producer.id";
        const static std::string OMSBuiltinKeys::CONSUMER_ID = "oms.consumer.id";
        const static std::string OMSBuiltinKeys::OPERATION_TIMEOUT = "oms.operation.timeout";
        const static std::string OMSBuiltinKeys::BEGIN_OFFSET = "oms.begin.offset";
        const static std::string OMSBuiltinKeys::END_OFFSET = "oms.end.offset";
        const static std::string OMSBuiltinKeys::BEGIN_TIMESTAMP = "oms.begin.timestamp";
        const static std::string OMSBuiltinKeys::END_TIMESTAMP = "oms.end.timestamp";

END_NAMESPACE_2(io, openmessaging)
#endif //OMS_OMSBUILTINKEYS_H
