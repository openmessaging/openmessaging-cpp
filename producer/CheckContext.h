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

#ifndef OMS_CHECK_CONTEXT_H
#define OMS_CHECK_CONTEXT_H

#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, producer)

    class CheckContext : private Uncopyable {
    public:
        virtual ~CheckContext() {

        }
        /**
         * Commits a transaction.
         */
        virtual void commit() = 0;
        /**
         * Rolls back a transaction.
         */
        virtual void rollback() = 0;
        /**
         * Unknown transaction status, may be this transaction still on going.
         */
        virtual void unknown() = 0;

    };

    typedef NS::shared_ptr<CheckContext> CheckContextPtr;

END_NAMESPACE_3(io, openmessaging, producer)

#endif //OMS_CHECK_CONTEXT_H
