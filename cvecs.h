/*
    MIT License

    Copyright (c) 2024 Marvin Katapult
    https://github.com/marvinkatapult/cvecs

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#ifndef __VEC_H__
#define __VEC_H__
#include <stdbool.h>

/** BEGIN OF STRVEC **/
#define DEFAULT_CAP_STRVEC          69

typedef struct StrVec {
    unsigned int count;
    unsigned int capacity;
    char ** vals;
} StrVec;

StrVec createStrVec(unsigned int capacity); // Creates a StrVec with capacity (Normally put DEFAULT_CAP_STRVEC)
void freeStrVec(StrVec str_vec);            // Frees Memory of StrVec

bool appendStrVec(StrVec * str_vec, const char * str);                      // Appends to StrVec
bool updateStrVec(StrVec str_vec, const char * str, unsigned int pos);      // Updates Value at position
bool setCapacity(StrVec * str_vec, unsigned int cap);                       // Sets Capacity and reallocs
/** END OF STRVEC **/

#endif // __VEC_H__
