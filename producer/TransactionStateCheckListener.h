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

#ifndef OMS_TRANSACTION_CHECK_LISTENER_H
#define OMS_TRANSACTION_CHECK_LISTENER_H

#include "Namespace.h"
#include "Message.h"
#include "producer/ExecutionContext.h"
#include "producer/CheckContext.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, producer)

    /**
     * Each executor will be associated with a transactional message, can be used to execute local transaction
     * branch and submit the transaction status(commit or rollback).
     * <p>
     *
     * The associated message will be exposed to consumer when the local transaction has been committed, or be
     * discarded if local transaction has been rolled back.
     *
     * <p>
     * If the executor don't submit the transaction status for a long time, the server may lookup it forwardly through
     * {@link LocalTransactionBranchExecutor#checkLocalTransactionBranch(Message, CheckLocalTransactionBranchContext)}
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class TransactionStateCheckListener : private Uncopyable {
    public:
        virtual ~TransactionStateCheckListener() {

        }
        /**
         * Checks the status of the local transaction branch.
         *
         * @param message the associated message.
         * @param checkContext the check context.
         */
        virtual void check(const MessagePtr &message, const CheckContextPtr &checkContext) = 0;

    };

    typedef NS::shared_ptr<TransactionStateCheckListener> TransactionStateCheckListenerPtr;

END_NAMESPACE_3(io, openmessaging, producer)

#endif //OMS_TRANSACTION_CHECK_LISTENER_H
