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

#ifndef OMS_MESSAGE_FACTORY_H
#define OMS_MESSAGE_FACTORY_H

#include <string>
#include <vector>

#include "ByteMessage.h"
#include "Namespace.h"
#include "OMS.h"

BEGIN_NAMESPACE_2(io, openmessaging)
    /**
     * A factory interface for creating {@code Message} objects.
     *
     */
    class MessageFactory {
    public:
        virtual ~MessageFactory() {
        }

        /**
         * Creates a {@code BytesMessage} object. A {@code BytesMessage} object is used to send a message containing a
         * stream of uninterpreted bytes.
         * <p>
         * The returned {@code BytesMessage} object only can be sent to the specified queue.
         *
         * @param queue the target queue to send
         * @param body the body data for a message
         * @return the created {@code BytesMessage} object
         * @throws OMSRuntimeException if the OMS provider fails to create this message due to some internal error.
         */
        virtual ByteMessagePtr createMessage(const std::string &queueName, const MessageBody &body) = 0;
    };

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_MESSAGE_FACTORY_H
