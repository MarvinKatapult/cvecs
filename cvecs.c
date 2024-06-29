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

StrVec createStrVec(size_t capacity) {
    char ** vals = calloc(capacity, sizeof(char *));

    StrVec vec = {
        .count = 0,
        .capacity = capacity,
        .vals = vals
    };

    return vec;
}

void freeStrVec(StrVec str_vec) {
    for (size_t i = 0; i < str_vec.count; i++) {
        free(str_vec.vals[i]);
    }
    free(str_vec.vals);
}

bool appendStrVec(StrVec * str_vec, const char * str) {
    if (!str_vec) return false;
    char * new_str = copyCString(str);

    str_vec->count++;
    if (str_vec->capacity < str_vec->count) {
        size_t new_cap = str_vec->capacity;
        new_cap += ((float)str_vec->capacity / DEFAULT_CAP_VEC) * DEFAULT_CAP_VEC;
        setStrVecCapacity(str_vec, new_cap);
    }

    str_vec->vals[str_vec->count-1] = new_str;
    return true;
}

bool updateStrVec(StrVec str_vec, const char * str, size_t pos) {
    if (pos >= str_vec.count) return false;
    free(str_vec.vals[pos]);
    str_vec.vals[pos] = copyCString(str);
    return true;
}

bool setStrVecCapacity(StrVec * str_vec, size_t cap) {
    if (!str_vec) return false;
    
    setVecCapacity((void **)&str_vec->vals, cap, sizeof(char *));
    str_vec->capacity = cap;

    return true;
}

bool setVecCapacity(void ** start, size_t cap, size_t size) {
    if (!start) return false;
    
    void * res = realloc(*start, size * cap);
    if (!res) {
        fprintf(stderr, "Realloc failed: %s %d\n", __FILE__, __LINE__);
        return false;
    }
    *start = res;

    return true;
}
