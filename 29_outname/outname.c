#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  int len = strlen(inputName);
  char* outname=malloc((len+7)*sizeof(*outname));
  strcpy(outname,inputName);
  strcat(outname,".counts");
  return outname;
}
