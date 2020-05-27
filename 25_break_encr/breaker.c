#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

size_t find_max(int * array){
  size_t max =0;
  for (int i=0;i<26;i++){
    if(array[max]<array[i]){
      max=i;
    }
    // printf("%d ",array[i]);
  }
  return max;
}

void decryptor(FILE *f){
  int array[26]={0};
  int c;
  long long int j=0;
  while((c=fgetc(f))!=EOF){
    if (isalpha(c)){
      c=c-'a';
      array[c]++;
      j++;
    }
  }
  size_t i=find_max(array);
  //printf("%d ",array[i]);
  if(((array[i]*100)/j)>8){
    if(i>=4){
      printf("%zu\n",i-4);
    }
    if(i<4&&i>=0){
      printf("%zu\n",i+22);
    }
  }
  else{
  printf("data not appropriate for decryption\n");
  }
}

    
      


int main(int argc,char ** argv){
  if (argc!=2){
    fprintf(stderr,"Usage: inputFilename");
    return EXIT_FAILURE;
  }
  FILE *f=  fopen(argv[1],"r");
  if (f==NULL){
    perror("could not open this file");
  }
  decryptor(f);
  if (fclose(f)!=0){
    perror("unable to close the file");
  }
  return EXIT_SUCCESS;
}
