#ifndef OMS_PULL_CONSUMER_H
#define OMS_PULL_CONSUMER_H

#include <string>

#include "smart_pointer.h"
#include "KeyValue.h"
#include "ServiceLifecycle.h"
#include "Namespace.h"
#include "Message.h"
#include "OMS.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

    /**
     * A {@code PullConsumer} object can poll messages from the specified queue,
     * and supports submit the consume result by acknowledgement.
     *
     * @version OMS 1.0
     * @see MessagingAccessPoint#createPullConsumer(String)
     * @since OMS 1.0
     */
    class PullConsumer : public virtual ServiceLifecycle {
    public:
        virtual ~PullConsumer() {

        }

        /**
         * Returns the attributes of this {@code PullConsumer} instance.
         * Changes to the return {@code KeyValue} are not reflected in physical {@code PullConsumer}.
         * <p>
         * There are some standard attributes defined by OMS for {@code PullConsumer}:
         * <ul>
         * <li> {@link OMSBuiltinKeys#CONSUMER_ID}, the unique consumer id for a consumer instance.
         * <li> {@link OMSBuiltinKeys#OPERATION_TIMEOUT}, the default timeout period for operations of {@code PullConsumer}.
         * </ul>
         *
         * @return the attributes
         */
        virtual KeyValuePtr attributes() = 0;

        /**
         * Attaches the {@code PullConsumer} to a specified queue.
         *
         * @param queueName a specified queue
         * @return this {@code PullConsumer} instance
         */
        virtual PullConsumer& attachQueue(const std::string &queueName, const KeyValuePtr &properties = kv_nullptr) = 0;

        /**
         * Detaches the {@code PullConsumer} from a specified queue.
         * <p>
         * After the success call, this consumer won't receive new message
         * from the specified queue any more.
         *
         * @param queueName a specified queue
         * @return this {@code PullConsumer} instance
         */
        virtual PullConsumer& detachQueue(const std::string &queueName) = 0;

        /**
         * Receives the next message from the attached queues of this consumer.
         * <p>
         * This call blocks indefinitely until a message is arrives, the timeout expires,
         * or until this {@code PullConsumer} is shut down.
         *
         * @return the next message received from the attached queues, or null if the consumer is
         * concurrently shut down or the timeout expires
         * @throws OMSRuntimeException if the consumer fails to pull the next message due to some internal error.
         */
        virtual MessagePtr receive(const KeyValuePtr &props = kv_nullptr) = 0;

        /**
         * Acknowledges the specified and consumed message with the specified attributes.
         * <p>
         * Messages that have been received but not acknowledged may be redelivered.
         *
         * @param messageId the consumed message id
         * @throws OMSRuntimeException if the consumer fails to acknowledge the messages due to some internal error.
         */
        virtual void ack(const std::string &messageId,
                         const KeyValuePtr &props = kv_nullptr) = 0;
    };

    typedef NS::shared_ptr<PullConsumer> PullConsumerPtr;


END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_PULL_CONSUMER_H
