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

#ifndef OMS_BUILTIN_KEYS_H
#define OMS_BUILTIN_KEYS_H

#include <string>
#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        static const std::string DRIVER_IMPL = "DRIVER_IMPL";
        static const std::string ACCESS_POINTS = "ACCESS_POINTS";
        static const std::string ACCOUNT_ID = "ACCOUNT_ID";
        static const std::string REGION = "REGION";
        static const std::string OPERATION_TIMEOUT = "OPERATION_TIMEOUT";

END_NAMESPACE_2(io, openmessaging)
#endif // OMS_BUILTIN_KEYS_H
