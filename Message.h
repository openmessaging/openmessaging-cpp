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

#ifndef OMS_MESSAGE_H
#define OMS_MESSAGE_H

#include <string>

#include "smart_pointer.h"
#include "KeyValue.h"
#include "OMSBuiltinKeys.h"
#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * The {@code Message} interface is the root interface of all OMS messages, and the most commonly used OMS message is
     * {@link BytesMessage}.
     * <p>
     * Most message-oriented middleware (MOM) products treat messages as lightweight entities that consist of a header and a
     * body, like <a href="http://rocketmq.apache.org/">Apache RocketMQ</a>. The header part contains fields used for message
     * routing and identification; the body part contains the application data to sent.
     * <p>
     * The {@code Message} is a lightweight entity that only contains properties related to information of a specific message
     * object, and the {@code Message} is composed of the following parts:
     *
     * <UL>
     * <LI>Header - All messages support the same set of header fields. Header fields contain values used by both
     * clients and providers to identify and route messages.
     * <LI>Properties - Each message contains a built-in facility for supporting application-defined property values.
     * Properties provide an efficient mechanism for supporting application-defined message filtering.
     * </UL>
     *
     * The body part is deferred to the sub-classes of {@code Message}.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Message : private Uncopyable {
    public:
        virtual ~Message() {

        }

        virtual KeyValuePtr properties() = 0;
        virtual HeadersPtr headers() = 0;
    };

    typedef NS::shared_ptr<Message> MessagePtr;

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_MESSAGE_H
