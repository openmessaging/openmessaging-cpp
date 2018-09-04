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

#ifndef OMS_PROMISE_H
#define OMS_PROMISE_H

#include "OMS.h"
#include "Future.h"
#include "producer/SendResult.h"
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)
    /**
     * Special {@link Future} which is writable.
     * <p>
     * A {@code Promise} can be completed or canceled, cancellation is performed by the {@code cancel} method.
     * Once a computation has completed, the computation cannot be cancelled. If you would like to use a {@code Promise}
     * for the sake of cancellability but not provide a usable result, you can declare type+s of the form
     * {@code Promise<?>} and return {@code null} as a result of the underlying task.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Promise : public Future {
    public:
        virtual ~Promise() {
        }

        virtual bool cancel(bool interruptIfRunning = false) = 0;

        virtual bool set(producer::SendResultPtr &value) = 0;

        virtual bool setFailure(std::exception &e) = 0;
    };

    typedef NS::shared_ptr<Promise> PromisePtr;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_PROMISE_H
