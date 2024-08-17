#include "cstring.h"
#include "cvecs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    StrVec str_vec = createStrVecEx(1);
    for (int i = 0; i < 1000; i++) {
        appendStrVec(&str_vec, "Hello");
    }

    for (int i = 0; i < 1000; i++) {
        updateStrVec(str_vec, "Dies ist meine Nachricht", i);
    }

    PRINT_STR_VEC(str_vec);
    freeStrVec(str_vec);

    return 0;
}
