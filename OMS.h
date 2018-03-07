#ifndef OMS_OMS_H
#define OMS_OMS_H

#include <cstring>

#include <boost/smart_ptr.hpp>

#include "KeyValue.h"
#include "Namespace.h"
#include "Uncopyable.h"
#include "OMSException.h"

BEGIN_NAMESPACE_2(io, openmessaging)

        extern boost::shared_ptr<KeyValue> kv_nullptr;

        template<typename T>
        class scoped_array {
        public:
            scoped_array(const T *ptr, int length) : ptr_(NULL), length_(length) {
                ptr_ = new T[length_];
                memcpy(ptr_, ptr, length_);
            }

            /**
             * Copy constructor is assumed to be expensive and used with caution.
             */
            scoped_array(const scoped_array& other) {
                ptr_ = new T[other.length_];
                length_ = other.length_;
                std::memcpy(ptr_, other.ptr_, other.length_ * sizeof(T));
            }

            // copy assignment
            scoped_array& operator= (const scoped_array &other) {
                if (this != &other) {
                    delete[](ptr_);
                    length_ = other.length_;
                    ptr_ = new T[length_];
                    std::memcpy(ptr_, other.ptr_, length_ * sizeof(T));
                }
                return *this;
            }

            ~scoped_array() {
                delete[](ptr_);
            }

            int getLength() const {
                return length_;
            }

            const T* getRawPtr() const {
                return ptr_;
            }

            T& operator[](int i) {
                if (i >= length_ || i < 0) {
                    throw OMSException("IndexOutOfBoundary");
                }
                return *(ptr_ + i);
            }

        private:
            T *ptr_;
            int length_;
        };

        class OMS {
        public:
            static boost::shared_ptr<KeyValue> newKeyValue();
        };

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_OMS_H
