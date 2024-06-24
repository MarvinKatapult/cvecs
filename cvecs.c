#include "cvecs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char * copyCString(const char * str) {
    char * ret = malloc(sizeof(char) * strlen(str));
    if (ret) {
        strcpy(ret, str);
    }

    return ret;
}

StrVec createStrVec(unsigned int capacity) {
    char ** vals = malloc(sizeof(char *) * capacity);
    memset(vals, 0, capacity);

    StrVec vec = {
        0,
        capacity,
        vals
    };

    return vec;
}

void freeStrVec(StrVec str_vec) {
    for (unsigned int i = 0; i < str_vec.count; i++) {
        free(str_vec.vals[i]);
    }
    free(str_vec.vals);
}

bool appendStrVec(StrVec * str_vec, const char * str) {
    if (!str_vec) return false;
    char * new_str = copyCString(str);

    str_vec->count++;
    if (str_vec->capacity < str_vec->count) {
        // Realloc
        unsigned int new_cap = str_vec->capacity;
        new_cap += ((float)str_vec->capacity / DEFAULT_CAP_STRVEC) * DEFAULT_CAP_STRVEC;
        setCapacity(str_vec, new_cap);
    }

    str_vec->vals[str_vec->count-1] = new_str;
    return true;
}

bool updateStrVec(StrVec str_vec, const char * str, unsigned int pos) {
    if (pos >= str_vec.count) return false;
    free(str_vec.vals[pos]);
    str_vec.vals[pos] = copyCString(str);
    return true;
}

bool setCapacity(StrVec * str_vec, unsigned int cap) {
    if (!str_vec) return false;
    
    void * res = realloc(str_vec->vals, sizeof(char *) * cap);
    str_vec->capacity = cap;
    if (!res) {
        fprintf(stderr, "Realloc failed: %s %d\n", __FILE__, __LINE__);
        return false;
    }
    str_vec->vals = res;

    return true;
}
