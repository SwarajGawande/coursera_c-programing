#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE* f=fopen(fname,"r");
  if(f==NULL){
    fprintf(stderr,"unable to open file");
    return NULL;
  }
  kvarray_t* temp=malloc(sizeof(*temp));
  temp->array=NULL;
  temp->numPairs=0;
  char* line=NULL;
  size_t sz=0;
  ssize_t len;
  size_t j=0;
  //size_t diff;
  while((len=getline(&line,&sz,f))>0){
    //diff=0;
    char *p=strchr(line,'=');
    /*if(len==1&&p!=NULL){
      ((*temp).array[j]).key=malloc(sizeof(*((*temp).array[j]).key));
      ((*temp).array[j]).key=NULL;
      ((*temp).array[j]).value=malloc(sizeof(*((*temp).array[j]).value));
      ((*temp).array[j]).value=NULL;
    }*/
    if(p==NULL){
      fprintf(stderr,"no '=' in string %s\n",line);
      free(line);
      line=NULL;
      continue;
    }
    (*temp).array=realloc((*temp).array,(j+1)*sizeof(*(*temp).array));
    temp->numPairs=j+1;
    kvpair_t *pair=malloc(sizeof(*pair));
    char* end=strchr(line,'\n');
    if(end!=NULL){
      *end='\0';
    }
    *p='\0';
    p++;
    (*pair).key=line;
    /*for(int i=0;i<diff;i++){
      ((*temp).array[j]).key[i]=line[i];
    }
    ((*temp).array[j]).key[diff]='\0';
    ((*temp).array[j]).value=malloc((len-diff-1)*sizeof(*((*temp).array[j]).value));
    for(int i=diff+1;i<len;i++){
      ((*temp).array[j]).value[i-diff-1]=line[i];
    }
    if(diff<len-1){
    ((*temp).array[j]).value[len-diff-2]='\0';
    }
    else{
      free(((*temp).array[j]).value);
      ((*temp).array[j]).value=malloc(sizeof(*((*temp).array[j]).value));
      ((*temp).array[j]).value[0]='\0';
      }*/
    pair->value=p;
    (*temp).array[j]=pair;
    j++;
    line=NULL;
  }
  free(line);
  if(fclose(f)!=0){
    fprintf(stderr,"unable to close  file\n");
  }
  return temp;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    free((*((*pairs).array[i])).key);
    free((*pairs).array[i]);
  }
  free((*pairs).array);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    printf("key  = '%s' value = '%s'\n",(*((*pairs).array[i])).key,(*((*pairs).array[i])).value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for(int i=0;i<pairs->numPairs;i++){
    if(strcmp((*((*pairs).array[i])).key,key)==0){
      return ((*(*pairs).array[i])).value;
    }
  }
  return NULL;
}
