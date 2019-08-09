#include "algorithm_one.h"
#include "algorithm_two.h"
#include "structure.h"

int main(){
  struct dynArr array;
  int inversionTest;

  dynArrGenerator(&array);
  dynArrPrint(&array);

  inversionTest = bruteForceInversion(&array);
  printf("\n%d\n", inversionTest);
  inversionTest = divideConquerInversion(&array);
  printf("%d\n", inversionTest);

  dynArrPrint(&array);
  freeDynArr(&array);

  return 0;
}
