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

#ifndef OMS_KEY_VALUE_H
#define OMS_KEY_VALUE_H

#include <string>
#include <map>
#include <set>

#include "Namespace.h"
#include "Uncopyable.h"
#include "smart_pointer.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * The {@code KeyValue} class represents a persistent set of properties,
     * which supports method chaining.
     * <p>
     * A {@code KeyValue} object only allows {@code String} keys and can contain four primitive type
     * as values: {@code int}, {@code long}, {@code double}, {@code String}.
     * <p>
     * The {@code KeyValue} is a replacement of {@code Properties}, with simpler
     * interfaces and reasonable entry limits.
     * <p>
     * A {@code KeyValue} object may be used in concurrent scenarios, so the implementation
     * of {@code KeyValue} should consider concurrent related issues.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class KeyValue : private Uncopyable {
    public:
        virtual ~KeyValue() {

        }

        virtual KeyValue &put(const std::string &key, short value) = 0;

        virtual KeyValue &put(const std::string &key, int value) = 0;

        virtual KeyValue &put(const std::string &key, long value) = 0;

        virtual KeyValue &put(const std::string &key, double value) = 0;

        virtual KeyValue &put(const std::string &key, const std::string &value) = 0;

        virtual short getShort(const std::string &key, short defaultValue = 0) = 0;

        virtual int getInt(const std::string &key, int defaultValue = 0) = 0;

        virtual long getLong(const std::string &key, long defaultValue = 0L) = 0;

        virtual double getDouble(const std::string &key, double defaultValue = 0.0) = 0;

        virtual std::string getString(const std::string &key, const std::string &defaultValue = "") = 0;

        virtual std::set<std::string> keySet() = 0;

        virtual bool containsKey(const std::string &key) = 0;
    };

    typedef NS::shared_ptr<KeyValue> KeyValuePtr;

    static KeyValuePtr kv_nullptr;

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_KEY_VALUE_H
