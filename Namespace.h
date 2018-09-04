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

#ifndef OMS_NAMESPACE_H
#define OMS_NAMESPACE_H

#define BEGIN_NAMESPACE_1(n1) namespace n1 {
#define END_NAMESPACE_1(n1)   }

#define BEGIN_NAMESPACE_2(n1, n2) namespace n1 { namespace n2 {
#define END_NAMESPACE_2(n1, n2)   } }

#define BEGIN_NAMESPACE_3(n1, n2, n3) namespace n1 { namespace n2 { namespace n3 {
#define END_NAMESPACE_3(n1, n2, n3)   } } }

#define BEGIN_NAMESPACE_4(n1, n2, n3, n4) namespace n1 { namespace n2 { namespace n3 { namespace n4{
#define END_NAMESPACE_4(n1, n2, n3, n4)   } } } }


#endif //OMS_NAMESPACE_H
