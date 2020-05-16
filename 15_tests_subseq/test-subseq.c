#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n);

int main(void){
  size_t n;
  int array1[] = {};
  int array2[] = {0};
  int array3[] = {1,2,3,4};
  int array4[] = {4,3,2,1,0};
  int array5[] = {-1,2,-3,4};
  int array6[] = {-4,-3,-2,2};
  int array7[] = {1001,-2203,0,0,23,56,56};
  if (maxSeq(array1,0)!=0) {
    return EXIT_FAILURE;
  }
  if (maxSeq(array2,1)!=1){
    return EXIT_FAILURE;
  }
  if (maxSeq(array3,4)!=4){
    return EXIT_FAILURE;
  }
  if (maxSeq(array4,5)!=1){
    return EXIT_FAILURE;
  }
  if (maxSeq(array5,4)!=2){
    return EXIT_FAILURE;
  }
  if (maxSeq(array6,4)!=4){
    return EXIT_FAILURE;
  }
  if (maxSeq(array7,7)!= 3){
    return EXIT_FAILURE;
  }
	     
  return EXIT_SUCCESS;
}
    
  
