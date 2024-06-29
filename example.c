#include "cvecs.h"
#include <stdio.h>

int main() {

    StrVec vec = createStrVec(DEFAULT_CAP_VEC);
    appendStrVec(&vec, "Hello Worldn");
    appendStrVec(&vec, "Hello Worldadwwada");
    appendStrVec(&vec, "Hello Worldn");
    appendStrVec(&vec, "Hello Worldn");
    appendStrVec(&vec, "Hello Worldn");
    for (int i = 0; i < 5; i++) {
        const char num[2] = { i + '0' };
        appendStrVec(&vec, num);
    }

    for (int i = 0; i < vec.count; i++) {
        printf("%s\n", vec.vals[i]);
    }

    freeStrVec(vec);

    return 0;
}
