#ifndef OMS_PRODUCER_H
#define OMS_PRODUCER_H

#include "smart_pointer.h"
#include "MessageFactory.h"
#include "ServiceLifecycle.h"
#include "Message.h"
#include "SendResult.h"
#include "Namespace.h"
#include "OMS.h"
#include "LocalTransactionExecutor.h"
#include "Future.h"
#include "BatchMessageSender.h"
#include "interceptor/ProducerInterceptor.h"

BEGIN_NAMESPACE_3(io, openmessaging, producer)

    /**
     * A {@code Producer} is a simple object used to send messages on behalf
     * of a {@code MessagingAccessPoint}. An instance of {@code Producer} is
     * created by calling the {@link MessagingAccessPoint#createProducer()} method.
     * It provides various {@code send} methods to send a message to a specified destination.
     * A destination can be a {@link MessageHeader#TOPIC} or a {@link MessageHeader#QUEUE}.
     * <p>
     *
     * {@link Producer#send(Message)} means send a message to destination synchronously,
     * the calling thread will block until the send request complete.
     * <p>
     * {@link Producer#sendAsync(Message)} means send a message to destination asynchronously,
     * the calling thread won't block and will return immediately. Since the send call is asynchronous
     * it returns a {@link Promise} for the send result.
     * <p>
     * {@link Producer#sendOneway(Message)} means send a message to destination in one way,
     * the calling thread won't block and will return immediately. The caller won't care about
     * the send result, while the server has no responsibility for returning the result.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Producer : public virtual MessageFactory, public virtual ServiceLifecycle {
    public:
        virtual ~Producer() {

        }

        /**
         * Returns the attributes of this {@code Producer} instance.
         * Changes to the return {@code KeyValue} are not reflected in physical {@code Producer}.
         * <p>
         * There are some standard attributes defined by OMS for {@code Producer}:
         * <ul>
         * <li> {@link OMSBuiltinKeys#PRODUCER_ID}, the unique producer id for a producer instance.
         * <li> {@link OMSBuiltinKeys#OPERATION_TIMEOUT}, the default timeout period for operations of {@code Producer}.
         * </ul>
         *
         * @return the attributes
         */
        virtual KeyValuePtr attributes() = 0;

        /**
         * Sends a message to the specified destination synchronously, the destination should be preset to
         * {@link Message#sysHeaders()}, other header fields as well.
         *
         * @param message a message will be sent
         * @return the successful {@code SendResult}
         * @throws OMSMessageFormatException if an invalid message is specified.
         * @throws OMSTimeOutException if the given timeout elapses before the send operation completes
         * @throws OMSRuntimeException if the {@code Producer} fails to send the message due to some internal error.
         */
        virtual SendResultPtr send(const MessagePtr &message,
                                   const KeyValuePtr &properties = kv_nullptr) = 0;

        /**
         * Sends a transactional message to the specified destination synchronously, using the specified attributes,
         * the destination should be preset to {@link Message#sysHeaders()}, other header fields as well.
         * <p>
         * A transactional message will be exposed to consumer if and only if the local transaction
         * branch has been committed, or be discarded if local transaction has been rolled back.
         *
         * @param message a transactional message will be sent
         * @param branchExecutor local transaction executor associated with the message
         * @param attributes the specified attributes
         * @return the successful {@code SendResult}
         * @throws OMSMessageFormatException if an invalid message is specified.
         * @throws OMSTimeOutException if the given timeout elapses before the send operation completes
         * @throws OMSRuntimeException if the {@code Producer} fails to send the message due to some internal error.
         */
        virtual SendResultPtr send(const MessagePtr &message,
                                   const LocalTransactionExecutorPtr &executor,
                                   const KeyValuePtr &properties) = 0;

        /**
         * Asynchronously send a message to its destination, which is specified in system headers.
         *
         * This method returns immediately after invocation and returning future follows similar
         * semantics to that of C++ standard library. Additionally, future accepts callback hooks
         * that are executed on future completion.
         *
         * @param message The message to send.
         * @param properties Optional additional properties.
         * @return Smart pointer to Future instance.
         */
        virtual FuturePtr sendAsync(const MessagePtr &message, const KeyValuePtr &properties = kv_nullptr) = 0;

        /**
         * Sends a message to the specified destination in one way, using the specified attributes, the destination
         * should be preset to {@link Message.BuiltinKeys}, other header fields as well.
         * <p>
         * There is no {@code Promise} related or {@code RuntimeException} thrown. The calling thread doesn't
         * care about the send result and also have no context to get the result.
         *
         * @param message a message will be sent
         * @param properties the specified userHeaders
         */
        virtual void sendOneway(const MessagePtr &message, const KeyValuePtr &properties = kv_nullptr) = 0;

        /**
         * Creates a {@code BatchMessageSender} to send message in batch way.
         *
         * @return a {@code BatchMessageSender} instance
         */
        virtual BatchMessageSenderPtr createSequenceBatchMessageSender() = 0;

        /**
         * Adds a {@code ProducerInterceptor} to intercept send operations of producer.
         *
         * @param interceptor a producer interceptor
         */
        virtual void addInterceptor(const interceptor::ProducerInterceptorPtr &interceptor) = 0;

        /**
         * Removes a {@code ProducerInterceptor}
         *
         * @param interceptor a producer interceptor will be removed
         */
        virtual void removeInterceptor(const interceptor::ProducerInterceptorPtr &interceptor) = 0;
    };

    typedef NS::shared_ptr<Producer> ProducerPtr;

END_NAMESPACE_3(io, openmessaging, producer)
#endif //OMS_PRODUCER_H
