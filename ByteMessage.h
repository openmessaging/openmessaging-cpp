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

#ifndef OMS_BYTE_MESSAGE_H
#define OMS_BYTE_MESSAGE_H

#include "OMS.h"
#include "Message.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * The {@code BytesMessage} contains a stream of uninterpreted bytes. It inherits from the {@code Message} interface and
     * adds a bytes message body.
     * <p>
     * The {@code BytesMessage} doesn't know the format or encoding Rules of the body, the provider and consumer decide the
     * interpretation of the bytes body.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class ByteMessage : public virtual Message {
    public:
        virtual ~ByteMessage() {

        }

        virtual MessageBody getBody()  = 0;

        virtual ByteMessage& setBody(const MessageBody &body) = 0;

    };

    typedef NS::shared_ptr<ByteMessage> ByteMessagePtr;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_BYTE_MESSAGE_H
