#ifndef OMS_UNCOPYABLE_H
#define OMS_UNCOPYABLE_H

#include "Namespace.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    class Uncopyable {

    protected:
        Uncopyable() {

        }

        ~Uncopyable() {

        }

    private:
        Uncopyable(const Uncopyable& other);

        Uncopyable& operator=(const Uncopyable& other);
    };

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_UNCOPYABLE_H
