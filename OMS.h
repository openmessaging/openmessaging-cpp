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

#ifndef OMS_OMS_H
#define OMS_OMS_H

#include <dlfcn.h>

#include <cstring>
#include <iostream>

#include "smart_pointer.h"
#include "Namespace.h"
#include "Uncopyable.h"
#include "OMSException.h"
#include "KeyValue.h"

// forward declaration
BEGIN_NAMESPACE_2(io, openmessaging)
    class MessagingAccessPoint;
END_NAMESPACE_2(io, openmessaging)

#ifdef __cplusplus
    extern "C" {
#endif

        static void *handle = NULL;

        static void load_library(const std::string &url) {
            std::string::size_type begin = url.find(":");
            std::string::size_type end = url.find(":", begin + 1);
            std::string driver = url.substr(begin + 1, end - begin - 1);

        #ifdef __APPLE__
            std::string extension = ".dylib";
        #endif
        #ifdef __linux__
            std::string extension = ".so";
        #endif
            std::string shared_library_name = "liboms_" + driver + extension;
            // clean previous error
            dlerror();
            handle = dlopen(shared_library_name.c_str(), RTLD_LAZY);
            if (!handle) {
                char * error = dlerror();
                std::cerr << "Failed to load shared library: " << shared_library_name
                          << "; Error Message:" << error << std::endl;
                std::string default_library = "liboms_jni";
                shared_library_name = default_library + extension;
                handle = dlopen(shared_library_name.c_str(), RTLD_LAZY);

                if (!handle) {
                    std::string msg = "Failed to dlopen shared library: ";
                    msg += shared_library_name;
                    msg += ". Reason: ";
                    msg += dlerror();
                    std::cout << msg << std::endl;
                    throw io::openmessaging::OMSException(msg);
                }
            }
        }

        static io::openmessaging::KeyValue* newKeyValue() {
            if (NULL == handle) {
                throw io::openmessaging::OMSException("Please call load_library first");
            }

            typedef io::openmessaging::KeyValue* (*Fn)();
            Fn fn;
            fn = (Fn)dlsym(handle, "newKeyValueImpl");
            return fn();
        }

        static io::openmessaging::MessagingAccessPoint*
        getMessagingAccessPoint(const std::string &url,
                                const io::openmessaging::KeyValuePtr &props = io::openmessaging::KeyValuePtr()) {

            typedef io::openmessaging::MessagingAccessPoint* (*Fn)(const std::string&, const io::openmessaging::KeyValuePtr &);

            if (NULL == handle) {
                load_library(url);
            }

            Fn fn;

            fn = (Fn)dlsym(handle, "getMessagingAccessPointImpl");

            return fn(url, props);
        }

        io::openmessaging::MessagingAccessPoint*
        getMessagingAccessPointImpl(const std::string &url,
                                    const io::openmessaging::KeyValuePtr &props = io::openmessaging::KeyValuePtr());


        io::openmessaging::KeyValue* newKeyValueImpl();

#ifdef __cplusplus
    }
#endif



#endif // OMS_OMS_H
