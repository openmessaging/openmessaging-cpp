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

#ifndef OMS_FUTURE_H
#define OMS_FUTURE_H

#include <exception>
#include <climits>

#include "smart_pointer.h"
#include "producer/SendResult.h"
#include "Uncopyable.h"
#include "FutureListener.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * A {@code Future} represents the result of an asynchronous computation.  Methods are provided to check if the
     * computation is complete, to wait for its completion, and to retrieve the result of the computation.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Future : private Uncopyable {
    public:
        virtual ~Future() {

        }

        /**
         * Returns {@code true} if this task was cancelled before it completed normally.
         *
         * @return {@code true} if this task was cancelled before it completed
         */
        virtual bool isCancelled() = 0;

        /**
         * Returns {@code true} if this task completed.
         * <p>
         * Completion may be due to normal termination, an exception, or cancellation -- in all of these cases, this method
         * will return {@code true}.
         *
         * @return {@code true} if this task completed
         */
        virtual bool isDone() = 0;

        /**
         * Waits if necessary for at most the given time for the computation to complete, and then retrieves its result, if
         * available.
         *
         * @param timeout the maximum time to wait
         * @return the computed result <p> if the computation was cancelled
         */
        virtual producer::SendResultPtr get(unsigned long timeout = LONG_MAX) = 0;

        /**
         * Adds the specified listener to this future. The specified listener is notified when this future is done. If this
         * future is already completed, the specified listener will be notified immediately.
         *
         * @param listener FutureListener
         */
        virtual Future &addListener(FutureListenerPtr listener) = 0;

        /**
         * Returns the cause of the failed future
         *
         * @return the cause of the failure. {@code null} if succeeded or this future is not completed yet.
         */
        virtual std::exception &getThrowable() = 0;

    };

    typedef NS::shared_ptr<Future> FuturePtr;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_FUTURE_H
