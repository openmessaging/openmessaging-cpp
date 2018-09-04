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

#include "OpenMessaging.h"
#include "consumer/Consumer.h"

#include <iostream>

using namespace std;
using namespace io::openmessaging;

int main(int argc, char *argv[]) {

    MessagingAccessPoint *messagingAccessPoint =
            OMS.getMessagingAccessPoint("oms:rocketmq://alice@rocketmq.apache.org/us-east");

    consumer::ConsumerPtr consumer = messagingAccessPoint->createConsumer();

    interceptor::ConsumerInterceptorPtr interceptor = new interceptor::ConsumerInterceptor() {
        @Override
        public void preReceive(MessagePtr &message, ContextPtr &attributes) {
        }

        @Override
        public void postReceive(MessagePtr &message, ContextPtr &attributes) {
        }
    };
    consumer->addInterceptor(interceptor);

    consumer->bindQueue("NS://HELLO_QUEUE");

    consumer->start();

    ByteMessagePtr message = consumer->receive(1000);

    cout<<"Receive Message: " << ByteMessagePtr << endl;

    consumer.ack(ByteMessagePtr->headers()->getMessageId());

    return 0;
}
