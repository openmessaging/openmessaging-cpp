#ifndef OMS_MESSAGING_ACCESS_POINT_FACTORY_H
#define OMS_MESSAGING_ACCESS_POINT_FACTORY_H

#include <string>

#include <boost/shared_ptr.hpp>

#include "KeyValue.h"
#include "MessagingAccessPoint.h"
#include "interceptor/MessagingAccessPointInterceptor.h"
#include "Namespace.h"
#include "OMS.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * A factory that provides some static methods to create a {@code MessagingAccessPoint}
     * from the specified OMS driver url.
     * <p>
     * The complete URL syntax is:
     * <p>
     * {@literal openmessaging:<driver_type>://<access_point>[,<access_point>,...]/<namespace>}
     * <p>
     * The first part of the URL specifies which OMS implementation is to be used, rocketmq is a
     * optional driver type.
     * <p>
     * The brackets indicate that the extra access points are optional, but a correct OMS driver url
     * needs at least one access point, which consists of hostname and port, like localhost:8081.
     * <p>
     * A namespace wraps the OMS resources in an abstraction that makes it appear to the users
     * within the namespace that they have their own isolated instance of the global OMS resources.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class MessagingAccessPointFactory {
    public:
        static boost::shared_ptr<MessagingAccessPoint>
        getMessagingAccessPoint(const std::string &url, const boost::shared_ptr<KeyValue> &properties = kv_nullptr);

        static void
        addInterceptor(const boost::shared_ptr<interceptor::MessagingAccessPointInterceptor> &interceptor);

        static void
        removeInterceptor(const boost::shared_ptr<interceptor::MessagingAccessPointInterceptor> &interceptor);
    };

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_MESSAGING_ACCESS_POINT_FACTORY_H
