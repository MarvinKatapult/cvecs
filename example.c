#include "vec.h"
#include <stdio.h>

int main() {

    StrVec vec = createStrVec(DEFAULT_CAP_STRVEC);
    for (int i = 0; i < 100; i++) {
        appendStrVec(&vec, "Hello World");
    }

    updateStrVec(vec, "Bye World :(", vec.count-1);

    for (int i = 0; i < vec.count; i++) {
        printf("%s\n", vec.vals[i]);
    }

    freeStrVec(vec);
    return 0;
}
