#ifndef OMS_STREAM_H
#define OMS_STREAM_H

#include <boost/shared_ptr.hpp>

#include "ServiceLifecycle.h"
#include "Namespace.h"
#include "KeyValue.h"
#include "MessageIterator.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)
    /**
     * A {@code Queue} is divided by many streams.
     * <p>
     * A {@code Stream} object supports consume messages from a
     * specified partition like a iterator.
     *
     * @version OMS 1.0
     * @see StreamingConsumer#stream(String)
     * @since OMS 1.0
     */
    class Stream : public virtual ServiceLifecycle {
    public:
        virtual ~Stream() {

        }

        virtual boost::shared_ptr<KeyValue> properties() = 0;

        virtual boost::shared_ptr<MessageIterator> current() = 0;

        virtual boost::shared_ptr<MessageIterator> begin() = 0;

        virtual boost::shared_ptr<MessageIterator> end() = 0;

        virtual boost::shared_ptr<MessageIterator> seekByTime(long timestamp) = 0;
    };

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_STREAM_H
