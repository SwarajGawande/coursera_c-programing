#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}
void printsorted(size_t len,char** linearray){
   for(int  j=0;j<len;j++){
      fprintf(stdout,"%s",(linearray[j]));
      free(linearray[j]);
    }
}

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  if (argc==1){
    char*line=NULL;
    size_t sz=0;
    char**linearray=malloc(sizeof(*linearray));
    size_t i=0;
    while(getline(&line,&sz,stdin)>=0){
      linearray=realloc(linearray,(i+1)*sizeof(*linearray));
      linearray[i]=line;
      line=NULL;
      i++;
    }
    free(line);
    sortData(linearray,i);
    printsorted(i,linearray);
    free(linearray);
  }
  if(argc>1){
    for (int j=1;j<argc;j++){
     FILE *f=fopen(argv[j],"r");
     if(f==NULL){
       fprintf(stderr,"could not open file");
     }
     char*line=NULL;
     size_t sz=0;
     char** linearray=malloc(sizeof(*linearray));
     size_t i=0;
     while(getline(&line,& sz,f)>=0){
      linearray=realloc(linearray,(i+1)*sizeof(*linearray));      
      linearray[i]=line;
      line=NULL;
      i++;
      }
     free(line);
     sortData(linearray,i);
     printsorted(i,linearray);
     free(linearray);
     if(fclose(f)!=0){
       fprintf(stderr,"unable to close file\n");
     }
    }
  }
  return EXIT_SUCCESS;
}
