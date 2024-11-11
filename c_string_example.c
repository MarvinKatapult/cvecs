#include "cstring.h"
#include "cvecs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    StrVec str_vec = createStrVecEx(1);
    String c_str_printf(const char * format, ...);

    for (size_t i = 0; i < 50; i++) {
        String str = c_str_printf("%ld", i);
        insertStrVec(&str_vec, str.s, i);
        freeString(str);
    }

    PRINT_STR_VEC(str_vec);
    freeStrVec(str_vec);

    return 0;
}
