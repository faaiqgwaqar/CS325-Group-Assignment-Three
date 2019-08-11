#include "algorithm_one.h"
#include "algorithm_two.h"
#include "structure.h"

int main(){
  struct dynArr array;
  int inversionTest;
  clock_t t;
  double time_taken;

  dynArrGenerator(&array);
  dynArrPrint(&array);

  t = clock();
  inversionTest = bruteForceInversion(&array);
  t = clock() - t;
  time_taken = ((double)t)/ CLOCKS_PER_SEC;

  printf("\nbrute force: %d\n", inversionTest);
  printf("Total Time Taken by CPU: %f seconds\n", time_taken);

  t = clock();
  inversionTest = divideConquerInversion(&array);
  t = clock() - t;
  time_taken = ((double)t)/ CLOCKS_PER_SEC;

  printf("\nDivide and conquer: %d\n", inversionTest);
  printf("Total Time Taken by CPU: %f seconds\n\n", time_taken);

  freeDynArr(&array);

  return 0;
}
