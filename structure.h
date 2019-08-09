#ifndef WAQARF_STRUCTURE_H
#define WAQARF_STRUCTURE_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct dynArr {
    int* data;
    int size;
    int capacity;
} dynArr;

void initDynArr(struct dynArr *da, int newCapacity);
void addDynArr(struct dynArr *da, int val);
void freeDynArr(struct dynArr *da);
void _dynArrDoubleCapacity(struct dynArr *da);
void dynArrGenerator(struct dynArr *da);
void dynArrPrint(struct dynArr *da);

#endif
