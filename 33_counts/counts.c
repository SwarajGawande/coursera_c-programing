#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t *init=malloc(sizeof(*init));
  init->array=NULL;
  init->numcounts=0;
  init->unknown=0;
  return init;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  int f=0;
  if(name==NULL){
    c->unknown=c->unknown+1;
    f=1;
  }
  for(int j=0;j<c->numcounts&&f==0;j++){
    if(strcmp((*(*c).array[j]).value,name)==0){
      (*((*c).array[j])).times++;
      f=1;
    }
  }
  if(f==0){
  c->array=realloc(c->array,(c->numcounts+1)*sizeof(*c->array));
  c->numcounts++;
  one_count_t *new=malloc(sizeof(*new));
  new->times=1;
  size_t len=0;
  while(name[len]!='\0'){
    len++;
  }
  new->value=malloc((len+1)*sizeof(*new->value));
  strncpy(new->value,name,len+1);
  c->array[c->numcounts-1]=new;
  }
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(int i=0;i<c->numcounts;i++){
    fprintf(outFile,"%s: %d\n",(*(*c).array[i]).value,(*(*c).array[i]).times);
  }
  if(c->unknown!=0){
    fprintf(outFile,"<unknown> : %zu\n",c->unknown);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(int j=c->numcounts-1;j>=0;j--){
    free((*((*c).array[j])).value);
    free((*c).array[j]);
  }
  free((*c).array);
  free(c);
}
