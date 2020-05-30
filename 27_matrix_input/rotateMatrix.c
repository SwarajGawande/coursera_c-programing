#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]){
  char temp[10][10];
  for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
      temp[i][j]=matrix[i][j];
    }
  }
  for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
      matrix[i][j]=temp[9-j][i];
      if (j!=9){
      printf("%c",matrix[i][j]);
      }
      if(j==9){
	printf("%c\n",matrix[i][9]);
      }
    }
  }
}

int main(int argc,char **argv){
  if (argc!=2){
    fprintf(stderr,"Usage: inputFilename\n");
    return EXIT_FAILURE;
  }
  FILE* f = fopen(argv[1],"r");
  if (f==NULL){
    perror("Inavalid file");
    return EXIT_FAILURE;
  }
  char array[10][10];
  int c;
  for (int i=0;i<10;i++){
    for (int j=0;j<11;j++){
      c=fgetc(f);
      if (c==EOF){
	fprintf(stderr,"executin finished\n");
	return EXIT_FAILURE;
      }
      if(c=='\n'&&j!=10){
	fprintf(stderr,"invalid input\n");
	return EXIT_FAILURE;
      }
      if (j<10&&c!='\n'){
	array[i][j]=c;
      }
    }
  }
  if ((c=fgetc(f))!=EOF){
    fprintf(stderr,"invalid input\n");
    return EXIT_FAILURE;
  }
  rotate(array);
  if (fclose(f)!=0){
    perror("could not close file");
    return EXIT_FAILURE;
  }
  /*FILE* f = fopen(argv[2],"w");
  for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
      fprintf("%c",array[i][j]);
    }
  }
  if (fclose(f)!=0){
    perror("could not close file");
  }*/  
  return EXIT_SUCCESS;
}
      
	
    
  
    
