#ifndef OMS_STREAMING_ITERATOR_H
#define OMS_STREAMING_ITERATOR_H


#include "smart_pointer.h"
#include "ServiceLifecycle.h"
#include "Namespace.h"
#include "Message.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

    class StreamingIterator : public virtual ServiceLifecycle {
    public:
        virtual ~StreamingIterator() {

        }

        virtual KeyValuePtr attributes() = 0;

        virtual void commit(bool flush) = 0;

        virtual bool hasNext() = 0;

        virtual MessagePtr next() = 0;

        virtual bool hasPrevious() = 0;

        virtual MessagePtr previous() = 0;
    };

    typedef NS::shared_ptr<StreamingIterator> StreamingIteratorPtr;

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_STREAMING_ITERATOR_H
