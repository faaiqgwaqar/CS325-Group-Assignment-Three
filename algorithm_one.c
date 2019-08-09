/* Algorithm_One Program*/
#include "algorithm_one.h"
#include "structure.h"

int bruteForceInversion(struct dynArr *da){
  int i;
  int j;
  int count = 0;

  for(i = 0; i < da->size; i++){
    for(j = i; j < da->size; j++){
      if(da->data[i] > da->data[j])
        count++;
    }
  }

  return count;
}
