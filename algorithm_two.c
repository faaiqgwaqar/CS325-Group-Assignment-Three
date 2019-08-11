/* Algorithm_Two Program*/
#include "algorithm_two.h"
#include "structure.h"

int divideConquerInversion(struct dynArr *da){
  return mergeInversion(da, 0, da->size - 1);
}

int mergeInversion(struct dynArr *da, int start, int end){
  int middle;
  int count = 0;
  if(start < end){
    middle = (start + end) / 2;
    count = mergeInversion(da, start, middle);
    count += mergeInversion(da, middle + 1, end);
    count += mergeSegments(da, start, middle + 1, end);
  }

  return count;
}

int mergeSegments(struct dynArr *da, int start, int middle, int end){
  int i;
  int j;
  int k;
  int count = 0;
  int temp[da->size];

  i = start;
  j = middle;
  k = start;

  while(i <= (middle - 1) && j <= end){
    if(da->data[i] <= da->data[j]){
      temp[k] = da->data[i];
      k++;
      i++;
    }
    else{
      temp[k] = da->data[j];
      k++;
      j++;
      count = count + (middle - i);
    }
  }

  while(i <= middle - 1){
    temp[k] = da->data[i];
    k++;
    i++;
  }

  while(j <= end){
    temp[k] = da->data[j];
    k++;
    j++;
  }

  for(i = start; i <= end; i++)
    da->data[i] = temp[i];

    return count;

}
