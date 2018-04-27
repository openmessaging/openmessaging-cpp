#ifndef OMS_PUSH_CONSUMER_H
#define OMS_PUSH_CONSUMER_H

#include <string>

#include "smart_pointer.h"
#include "ServiceLifecycle.h"
#include "MessageListener.h"
#include "Namespace.h"
#include "OMS.h"
#include "interceptor/ConsumerInterceptor.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)
    /**
     * A {@code PushConsumer} object to receive messages from multiple queues, these messages are pushed from
     * MOM server to {@code PushConsumer} client.
     *
     * @version OMS 1.0
     * @see MessagingAccessPoint#createPushConsumer()
     * @since OMS 1.0
     */
    class PushConsumer : public virtual ServiceLifecycle {
    public:
        virtual ~PushConsumer() {

        }

        /**
         * Returns the attributes of this {@code PushConsumer} instance.
         * Changes to the return {@code KeyValue} are not reflected in physical {@code PushConsumer}.
         * <p>
         * There are some standard attributes defined by OMS for {@code PushConsumer}:
         * <ul>
         * <li> {@link OMSBuiltinKeys#CONSUMER_ID}, the unique consumer id for a consumer instance.
         * <li> {@link OMSBuiltinKeys#OPERATION_TIMEOUT}, the default timeout period for operations of {@code PushConsumer}.
         * </ul>
         *
         * @return the attributes
         */
        virtual KeyValuePtr attributes() = 0;

        /**
         * Resumes the {@code PushConsumer} after a suspend.
         * <p>
         * This method resumes the {@code PushConsumer} instance after it was suspended.
         * The instance will not receive new messages between the suspend and resume calls.
         *
         * @throws OMSRuntimeException if the instance has not been suspended.
         * @see PushConsumer#suspend()
         */
        virtual void resume() = 0;

        /**
         * Suspends the {@code PushConsumer} for later resumption.
         * <p>
         * This method suspends the consumer until it is resumed.
         * The consumer will not receive new messages between the suspend and resume calls.
         * <p>
         * This method behaves exactly as if it simply performs the call {@code suspend(0)}.
         *
         * @throws OMSRuntimeException if the instance is not currently running.
         * @see PushConsumer#resume()
         */
        virtual void suspend(long timeout = 0) = 0;

        /**
         * This method is used to find out whether the {@code PushConsumer} is suspended.
         *
         * @return true if this {@code PushConsumer} is suspended, false otherwise
         */
        virtual bool isSuspended() = 0;

        /**
         * Attaches the {@code PushConsumer} to a specified queue, with a {@code MessageListener}.
         * <p>
         * {@link MessageListener#onReceived(Message, MessageListener.Context)} will be called when new
         * delivered message is coming.
         *
         * @param queueName a specified queue
         * @param listener a specified listener to receive new message
         * @return this {@code PushConsumer} instance
         */
        virtual PushConsumer &attachQueue(const std::string &queueName,
                                          const MessageListenerPtr &listener,
                                          const KeyValuePtr &properties = kv_nullptr) = 0;

        /**
         * Detaches the {@code PushConsumer} from a specified queue.
         * <p>
         * After the success call, this consumer won't receive new message
         * from the specified queue any more.
         *
         * @param queueName a specified queue
         * @return this {@code PushConsumer} instance
         */
        virtual PushConsumer &detachQueue(const std::string &queueName) = 0;

        /**
         * Adds a {@code PushConsumerInterceptor} instance to this consumer.
         *
         * @param interceptor an interceptor instance
         */
        virtual void addInterceptor(const interceptor::ConsumerInterceptorPtr &interceptor) = 0;

        /**
         * Removes an interceptor from this consumer.
         *
         * @param interceptor an interceptor to be removed
         */
        virtual void removeInterceptor(const interceptor::ConsumerInterceptorPtr &interceptor) = 0;
    };

    typedef NS::shared_ptr<PushConsumer> PushConsumerPtr;

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_PUSH_CONSUMER_H
