#ifndef __VEC_H__
#define __VEC_H__
#include <stdbool.h>

#define DEFAULT_CAP_STRVEC  69

typedef struct StrVec {
    unsigned int count;
    unsigned int capacity;
    char ** vals;
} StrVec;

StrVec createStrVec(unsigned int capacity); // Creates a StrVec with capacity (Normally put DEFAULT_CAP_STRVEC)
void freeStrVec(StrVec str_vec);            // Frees Memory of StrVec

bool appendStrVec(StrVec * str_vec, const char * str);                      // Appends to StrVec
bool updateStrVec(StrVec str_vec, const char * str, unsigned int pos); // Updates Value at position

#endif // __VEC_H__
