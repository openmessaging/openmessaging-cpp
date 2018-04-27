#ifndef OMS_STREAM_CONSUMER_H
#define OMS_STREAM_CONSUMER_H

#include <string>
#include <vector>

#include "smart_pointer.h"
#include "KeyValue.h"
#include "ServiceLifecycle.h"
#include "StreamingIterator.h"
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

        virtual KeyValuePtr attributes() = 0;

        virtual StreamingIteratorPtr seek(const std::string &name, long offset, int whence) = 0;

    };
    typedef NS::shared_ptr<StreamingConsumer> StreamingConsumerPtr;

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_STREAM_CONSUMER_H
