#ifndef OMS_MESSAGE_ITERATOR_H
#define OMS_MESSAGE_ITERATOR_H

#include <boost/shared_ptr.hpp>

#include "ServiceLifecycle.h"
#include "Namespace.h"
#include "Message.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

    class MessageIterator : public virtual ServiceLifecycle {
    public:
        virtual ~MessageIterator() {

        }

        virtual boost::shared_ptr<KeyValue> properties() = 0;

        virtual void commit(bool flush) = 0;

        virtual bool hasNext() = 0;

        virtual boost::shared_ptr<Message> next() = 0;

        virtual bool hasPrevious() = 0;

        virtual boost::shared_ptr<Message> previous() = 0;
    };

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_MESSAGE_ITERATOR_H
