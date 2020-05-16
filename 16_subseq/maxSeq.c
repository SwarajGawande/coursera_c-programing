#include <stdio.h>
#include <stdlib.h>


size_t maxSeq(int *array,size_t n){
  if (n==0){
    return 0;
  }
  if (n==1){
    return 1;
  }
  int i=1;
  size_t maxseq =1;
  while (i<n){
    int j=1;
    if (array[i-1]<array[i]){
      j=j+1;
      i=i+1;
      while (array[i-1]<array[i]&&i<n){
	j=j+1;
	i=i+1;
      }
    }
    else{
      i=i+1;
    }
    if (maxseq<j){
      maxseq=j;
    }
  }
  return maxseq;
}


      
