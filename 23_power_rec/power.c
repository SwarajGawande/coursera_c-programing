#include <stdio.h>
#include <stdlib.h>

unsigned powerhelper(unsigned x, unsigned y, unsigned ans){
  if (y<=0){
    return ans;
  }
  return powerhelper(x,y-1,ans*x);
}


unsigned power(unsigned x, unsigned y){
  return powerhelper(x,y,1);
}
