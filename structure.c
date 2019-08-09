#include "structure.h"

void initDynArr(struct dynArr *da, int newCapacity){
  assert(newCapacity >= 0);
  da->capacity = newCapacity;
  da->size = 0;
  da->data = (int*) malloc(sizeof(int)*newCapacity);
  assert(da->data);
}

void addDynArr(struct dynArr *da, int val){
  if(da->size >= da->capacity)
    _dynArrDoubleCapacity(da);
  da->data[da->size] = val;
  da->size++;
}

void freeDynArr(struct dynArr *da){
  assert(da);
  free(da->data);
  da->capacity = 0;
  da->size = 0;
}

void _dynArrDoubleCapacity(struct dynArr *da){
  int *oldBuffer = da->data;
  int oldSize = da->size;
  int i;
  initDynArr(da, 2 * da->capacity);
  for(i = 0; i < oldSize; i++)
    da->data[i] = oldBuffer[i];
  da->size = oldSize;
  free(oldBuffer);
}

void dynArrGenerator(struct dynArr *da){
  int i;
  int randomVar;
  int arrCap = 5;
  int upper = 100;
  int lower = 1;
  srand(time(NULL));
  initDynArr(da,arrCap);
  for(i = 0; i < arrCap; i++){
    randomVar = (rand() % (upper - lower + 1)) + lower;
    addDynArr(da,randomVar);
  }
}

void dynArrPrint(struct dynArr *da){
  int i;
  printf("[ ");
  for(i = 0; i < da->size; i++)
    printf("%d ",da->data[i]);
  printf("]");
}
