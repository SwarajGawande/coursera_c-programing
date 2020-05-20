#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

int main(void){
  int x1 = 0;
  int x2 = 1;
  int x3 = -1;
  int x4 = 4;
  int x5 = 7;
  if (power(x1,x2)!=0){
    return EXIT_FAILURE;
  }
  if (power(x2,x4)!=1&&power(x2,x5)!=1){
    return EXIT_FAILURE;
  }
  if (power(x1,5)!= 0){
    return EXIT_FAILURE;
  }
  if (power(-3,4)!=81){
    return EXIT_FAILURE;
  }
  if (power(-3,3)!=-27){
    return EXIT_FAILURE;
  }
  if (power(0,0)!=1){
    return EXIT_FAILURE;
  }
  if (power(1,-2)!=1){
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
