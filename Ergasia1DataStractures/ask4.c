#include <stdio.h>
#include <stdlib.h>

void asteriskos(int num){
  for (int i = 0;i<num;i++){
    printf("%d.* \n",i);
  }
}
int main(){
  int num;
  printf("Eisagete plithos asteriskon pros ektiposi-->"); 
  scanf("%d",&num);
  asteriskos(num);
  return 0;
}

