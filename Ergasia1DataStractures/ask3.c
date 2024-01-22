#include <stdio.h>
#include <stdlib.h>
int main(){
  int A[10][10]; //dilwnoume enan pinaka akeraiown 10x10
  for(int i = 0;i<10;i++){
    for (int j = 0;j<10;j++){
      A[i][j] = rand();   //gemizoume ton pinaka me tixaia noumera
    }
  }
  //dinoume stis times Main_min kai Secondary_min tin idia timi(tou protou keliou ston pinaka)
  int M_min = A[0][0];
  int S_min = M_min;
  //kanoume mia prospelasi tis kirias diagwniou opou isxyei i==j
  for(int i = 0;i<10;i++){
    if (A[i][i]<M_min){
      M_min = A[i][i]; //an to i timi sto keli einai mikrotero apo tin elaxisti timi tote anathetoume nea sto M_min
      }
    }
  //kanoume mia prospelasi tis dfterevusas diagwniou opou isxyei i==N+1-i (edw n=10)
  for (int i=0;i<10;i++){
    if (A[i][10+1-i] < S_min){
      S_min = A[i][10+1-i]; //an to i timi sto keli einai mikrotero apo tin elaxisti timi tote anathetoume nea sto S_min
    }
  }
  
  printf("Elaxisto kyrias diagwniou-->%d\n",M_min);
  printf("Elaxisto defterevusas diagwniou-->%d\n",S_min);
  return 0;
}
