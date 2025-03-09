#include "mymath.h"

namespace mymath {
    int NOD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return NOD(b, a % b);
    }
}