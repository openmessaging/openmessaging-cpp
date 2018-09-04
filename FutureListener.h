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

#ifndef OMS_FUTURE_LISTENER_H
#define OMS_FUTURE_LISTENER_H


#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    class Future;

    class FutureListener : private Uncopyable {
    public:
        virtual ~FutureListener() {

        }

        /**
         * Invoked when the operation completes, be the associated {@link Promise} successful or not.
         * @param future The associated promise facade
         */
        virtual void operationComplete(const Future& future) = 0;
    };

    typedef NS::shared_ptr<FutureListener> FutureListenerPtr;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_FUTURE_LISTENER_H
