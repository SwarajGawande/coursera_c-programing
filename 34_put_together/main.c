#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  counts_t *ansct=createCounts();
  FILE*flist=fopen(filename,"r");
  if(flist==NULL){
    fprintf(stderr,"unable to open list\n");
    exit(EXIT_FAILURE);
  }
  char* line=NULL;
  size_t sz=0;
  ssize_t len;
  while((len=getline(&line,&sz,flist))>0){
    line[len-1]='\0';
    const char*name=lookupValue(kvPairs,line);
    addCount(ansct,name);
    free(line);
    line=NULL;
  }
  free(line);
  if(fclose(flist)!=0){
    fprintf(stderr,"unable to close list\n");
  }
  return ansct;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
  if(argc<3){
    fprintf(stderr,"Usage: input file name, counts\n");
    return EXIT_FAILURE;
  }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t * kv=readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
  for(int i=2;i<argc;i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c
    counts_t * c=countFile(argv[i],kv);
    //compute the output file name from argv[i] (call this outName)
    size_t len=strlen(argv[i]);
    char*outName=malloc((len+7)*sizeof(*outName));
    strncpy(outName,argv[i],len+1);
    char*change=".count\0";
    outName=strcat(outName,change);
    //open the file named by outName (call that f)
    FILE*f=fopen(outName,"w");
    if(f==NULL){
      fprintf(stderr,"unable to open output file\n");
    }
    //print the counts from c into the FILE f
    printCounts(c,f);
    //close f
    if(fclose(f)!=0){
      fprintf(stderr,"unable to close output file\n");
    }

    //free the memory for outName and c
    freeCounts(c);
    free(outName);
  }
  //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
