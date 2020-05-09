#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void printline(int Age , double initial){
  printf("Age %3d month %2d you have $%.2f\n" ,Age/12, Age%12, initial);
}

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  printline(startAge,initial);
  startAge=startAge+1;
  int i = startAge;
  while (startAge <i+working.months){
    initial=initial+initial*working.rate_of_return+working.contribution;
    printline(startAge,initial);
    startAge=startAge+1;
  }
  int j = startAge;
  while (startAge<j+retired.months-1){
    initial=initial+initial*retired.rate_of_return+retired.contribution;
    printline(startAge,initial);
    startAge=startAge+1;
  }
}

int main (void){
  int Age = 327;
  int Savings = 21345;
  retire_info working;
  working.months = 489;
  working.contribution =1000;
  working.rate_of_return=0.045/12;
  retire_info retired;
  retired.months =384;
  retired.contribution = -4000;
  retired.rate_of_return =0.01/12;
  retirement(Age,Savings, working,retired);
  return 0;
  }
