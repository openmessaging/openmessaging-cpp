#ifndef OMS_STREAM_CONSUMER_H
#define OMS_STREAM_CONSUMER_H

#include <string>
#include <vector>

#include <boost/smart_ptr.hpp>

#include "KeyValue.h"
#include "ServiceLifecycle.h"
#include "MessageIterator.h"
#include "Namespace.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)
    /**
     * A {@code Queue} is divided by many streams.
     * <p>
     * A {@code StreamingConsumer} object supports consume messages from a
     * specified partition like a iterator.
     *
     * @version OMS 1.0
     * @see Stream
     * @since OMS 1.0
     */
    class StreamingConsumer : public virtual ServiceLifecycle {
    public:
        virtual ~StreamingConsumer() {

        }

        virtual boost::shared_ptr<KeyValue> properties() = 0;

        virtual std::vector<std::string> streams() = 0;

        virtual std::vector<std::string> consumers() = 0;

        virtual boost::shared_ptr<MessageIterator> current() = 0;

        virtual boost::shared_ptr<MessageIterator> begin() = 0;

        virtual boost::shared_ptr<MessageIterator> end() = 0;

        virtual boost::shared_ptr<MessageIterator> seekByTime(long timestamp) = 0;
    };

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_STREAM_CONSUMER_H
