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

#ifndef OMS_MESSAGE_LISTENER_H
#define OMS_MESSAGE_LISTENER_H

#include "smart_pointer.h"
#include "Context.h"
#include "Namespace.h"
#include "Message.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

    /**
     * The message listener interface. A message listener must implement this {@code MessageListener} interface and register
     * itself to a consumer instance to asynchronously receive messages.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class MessageListener : private Uncopyable {
    public:
        virtual ~MessageListener() {

        }

        /**
         * Callback method to receive incoming messages.
         * <p>
         * A message listener should handle different types of {@code Message}.
         *
         * @param message the received message object.
         * @param context the context delivered to the consume thread.
         */
        virtual void onReceived(MessagePtr &message, ContextPtr &context) = 0;
    };

    typedef NS::shared_ptr<MessageListener> MessageListenerPtr;

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_MESSAGE_LISTENER_H
