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
#include "producer/Producer.h"

#include <iostream>

using namespace std;
using namespace io::openmessaging;

int main(int argc, char *argv[]) {

    MessagingAccessPoint *messagingAccessPoint =
            OMS.getMessagingAccessPoint("oms:rocketmq://alice@rocketmq.apache.org/us-east");

    producer::ProducerPtr producer = messagingAccessPoint->createProducer();

    interceptor::ProducerInterceptorPtr interceptor = new interceptor::ProducerInterceptor() {
        @Override
        public void preSend(MessagePtr &message, ContextPtr &attributes) {
        }

        @Override
        public void postSend(MessagePtr &message, ContextPtr &attributes) {
        }
    };
    producer->addInterceptor(interceptor);

    producer->start();

    ByteMessagePtr message =producer->createMessage("NS://HELLO_QUEUE", new MessageBody("HELLO_BODY"));

    producer::SendResultPtr sendResult = producer.send(message);
    cout<<"SendResult: " << sendResult << endl;

    //Sends a message to the specified destination async.
    FuturePtr sendResultFuture = producer.sendAsync(message);
    sendResult = sendResultFuture.get(1000);
    cout<<"SendResult: " << sendResult << endl;

    //Sends a message to the specified destination in one way mode.
    producer.sendOneway(message);

    //Sends messages to the specified destination in batch mode.
    list<MessagePtr> messages(10);
    for (int i = 0; i < 10; i++) {
        MessagePtr msg = producer.createMessage("NS://HELLO_QUEUE", new MessageBody("HELLO_BODY"));
        messages.push_back(msg);
    }
    producer.send(messages);

    producer.removeInterceptor(interceptor);

    producer.stop();

    messages.clear();

    return 0;
}
