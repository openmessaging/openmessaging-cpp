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

#ifndef OMS_RESPONSE_STATUS_H
#define OMS_RESPONSE_STATUS_H
BEGIN_NAMESPACE_u2(io, openmessaging)
enum OMSResponceStatus{
    UnsupportedVersion = 1101,
    Success = 1200,
    BadRequest = 1400,
    Unauthorized = 1401,
    MessageBodyRequired = 1402,
    Forbidden = 1403,
    DestinationNotFound = 1404,
    NamespaceNotFound = 1405,
    DestinationAlreadyExists = 1406,
    NamespaceAlreadyExists = 1407,
    ConsumerIdAlreadyExists = 1408,
    ProducerIdAlreadyExists = 1409,
    RequestTimeout = 1410,
    MessageAttributesTooLarge = 1411,
    MessageHeaderTooLarge = 1412,
    MessageBodyTooLarge = 1413,
    NoNewMessageFound = 1414,
    MaxTopicsReached = 1415,
    MaxQueuesReached = 1416,
    MaxNamespacesReached = 1417,
    BadParameter = 1416,
    ServerStatus = 1500,
    StorageServiceStatus = 1501,
    StorageServiceBusy = 1502,
    ServiceNotAvailable = 1503,
    FlushDiskTimeout = 1504,
    CreateMessagingAccessPointFailed = 10000,
    IllegalDriver = 10001,
    IllegalVersion = 10002,
    VersionNotCompatibleSpecification = 10003,
};
END_NAMESPACE_2(io, openmessaging)
#endif //OMS_RESPONSE_STATUS_H
