#ifndef OMS_SMART_POINTER_H
#define OMS_SMART_POINTER_H

#include "OMSException.h"

// In case C++11 or later version is available.
#if __cplusplus >= 201103L
    #include <memory>
    #define NS std
    #define USE_CXX_11 1
#else
    // If boost is used, we would use Boost.SmartPointer
    #ifdef USE_BOOST
        #include <boost/smart_ptr.hpp>
        #define NS boost
    #else
        #include "shared_ptr.hpp"
        #include <cstring>
        #define NS io::openmessaging
    #endif

#endif

#include <cstring>
BEGIN_NAMESPACE_2(io, openmessaging)

    template <typename T>
    class ManagedArray {
    public:
        ManagedArray(T* payload, unsigned int len, bool copy = true) : len_(len), copy_(copy) {
            payload_ = new T[len_];
            if (copy_) {
                std::memcpy(payload_, payload, len * sizeof(T));
            } else {
                payload_ = payload;
            }
        }

        ManagedArray(ManagedArray &other) {
            len_ = other.len_;
            copy_ = true;
            payload_ = new T[len_];
            std::memcpy(payload_, other.payload_, len_ * sizeof (T));
        }

        ~ManagedArray() {
            if (copy_) {
                delete[](payload_);
            }
        }

        T* get() const {
            return payload_;
        }

        unsigned int length() const {
            return len_;
        }

        T& operator[](int index) {
            if (index < len_) {
                return *(payload_ + index);
            }
            throw io::openmessaging::OMSException("IndexOutOfBoundary");
        }

    private:
        T* payload_;
        unsigned int len_;
        bool copy_;
    };

typedef ManagedArray<signed char> MessageBody;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_SMART_POINTER_H
