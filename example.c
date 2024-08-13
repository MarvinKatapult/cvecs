#include "cvecs.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /********************/
    Vec vec = createVec();
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < 10; i++) {
        appendVec(&vec, nums + i);
    }
    deleteVec(&vec, nums+2);

    for (size_t i = 0; i < vec.count; i++) {
        printf("%d\n", *(int *)vec.entries[i].val);
    }

    freeVec(vec);
    /********************/
    /*
    IntVec int_vec = createIntVec();
    for (int i = 0; i < 10; i++) 
        appendIntVec(&int_vec, i);

    PRINT_INT_VEC2(int_vec);
    freeIntVec(int_vec);
    */
    /********************/
    /*
    StrVec str_vec = createStrVec();
    for (int i = 0; i < 50; i++)
        appendStrVec(&str_vec, "Hello");
    PRINT_STR_VEC2(str_vec);
    freeStrVec(str_vec);
    */
    /********************/

    return 0;
}
