#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  kvarray_t* temp=malloc(sizeof(*temp));
  (*temp).array=malloc(sizeof(*(*temp).array));
  temp->numPairs=1;
  FILE* f=fopen(fname,"r");
  if(f==NULL){
    fprintf(stderr,"unable to open file");
  }
  char* line=NULL;
  size_t sz=0;
  ssize_t len;
  size_t j=0;
  size_t diff;
  while((len=getline(&line,&sz,f))>0){
    (*temp).array=realloc((*temp).array,(j+1)*sizeof(*(*temp).array));
    temp->numPairs=j+1;
    for(int i=0;i<len;i++){
      if(line[i]=='='){
	diff=i;
	break;
      }
    }
    ((*temp).array[j]).key=malloc((diff+1)*sizeof(*((*temp).array[j]).key));
    for(int i=0;i<diff;i++){
      ((*temp).array[j]).key[i]=line[i];
    }
    ((*temp).array[j]).key[diff]='\0';
    ((*temp).array[j]).value=malloc((len-diff-1)*sizeof(*((*temp).array[j]).value));
    for(int i=diff+1;i<len;i++){
      ((*temp).array[j]).value[i-diff-1]=line[i];
    }
    ((*temp).array[j]).value[len-diff-2]='\0';
    j++;
    free(line);
    line=NULL;
  }
  free(line);
  fclose(f);
  return temp;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    free(((*pairs).array[i]).key);
    free(((*pairs).array[i]).value);
  }
  free((*pairs).array);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    printf("key  = '%s' value = '%s'\n",((*pairs).array[i]).key,((*pairs).array[i]).value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    if(strcmp(((*pairs).array[i]).key,key)==0){
      return ((*pairs).array[i]).value;
    }
  }
  return NULL;
}
