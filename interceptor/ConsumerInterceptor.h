/* Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OMS_CONSUMER_INTERCEPTOR_H
#define OMS_CONSUMER_INTERCEPTOR_H

#include "smart_pointer.h"
#include "Namespace.h"
#include "Uncopyable.h"
#include "Message.h"

BEGIN_NAMESPACE_3(io, openmessaging, interceptor)

    /**
     * A {@code ConsumerInterceptor} is used to intercept consume operations of consumer.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class ConsumerInterceptor : private Uncopyable {
    public:
        virtual ~ConsumerInterceptor() {

        }

        virtual std::string name() const = 0;
        /**
         * Invoked before the invocation of {@link MessageListener#onReceived(Message, Context)}.
         *
         * @param message the message is actually received.
         * @param attributes the extensible attributes delivered to the intercept thread.
         */
        virtual void preReceive(const MessagePtr &message, const InterceptorContextPtr &attributes = kv_nullptr) = 0;

        /**
         * Invoked after the invocation of {@link MessageListener#onReceived(Message, MessageListener.Context)}.
         *
         * @param message the message is actually received.
         * @param attributes the extensible attributes delivered to the intercept thread.
         */
        virtual void postReceive(const MessagePtr &message, const InterceptorContextPtr &attributes = kv_nullptr) = 0;
    };

    typedef NS::shared_ptr<ConsumerInterceptor> ConsumerInterceptorPtr;

END_NAMESPACE_3(io, openmessaging, interceptor)

#endif //OMS_CONSUMER_INTERCEPTOR_H
