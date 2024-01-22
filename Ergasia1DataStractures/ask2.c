#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int main(){
  /*dimiourgoume ena random seed gia tin paragogi tixaiou arithmou
  to opoio vasizetai stin ora tou ipologisti*/
  srand(time(NULL)); 
  int A[6];  //dilwoume enan pinaka 6 thesewn
  
  for (int num=0;num<6;num++){
  int flag = 0; //arxikopoioume ena flag pou tha xrisimopoioume gia ton entopismo diplotipon arithmon
  int rand_num = rand()% 50; //edw pou to range einai [1,49] boroume na thesoume mono upper bound
    for (int i=0; i<num;i++){ //kanoume mia grigori anazitisi sta kelia pou exoume idi gemisei
      if (rand_num == A[i]){ // an vrethei diplotipo noumero 
        flag = 1; //allazume to flag se 1
      }
    }
      if (flag == 0){
        A[num] = rand_num; // an den vrethike diplotipos anathetoume ton arithmo sto keli
      }else{
        rand_num = rand()% 49; //paragoume allo tixaio arithmo
        A[num] = rand_num;
      }
    }
  for (int num=0;num<6;num++){
    printf("%d\n",A[num]);  //emfanizoume ta periexomena tou pinaka
  }
 
  return 0;
 }
