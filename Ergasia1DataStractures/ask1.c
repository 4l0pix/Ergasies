#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    /*dimiourgoume ena random seed gia tin paragogi tixaiou arithmou
    to opoio vasizetai stin ora tou ipologisti*/
    srand(time(NULL)); 
    int A[100]; //dimiourgoume enan pinaka 100 theseon
    int range = (80 - 20 + 1); //kathorizoume to evros timon [20,80] (stin pragmatikotita einai [0,60])
    int sum = 0;
    for (int num = 0; num<100;num++){
        /*dinoume sto A[i] mia tixaia timi apo to range[0,60] opote
        afksanume olo to range kata 20 kai etsi ginetai [20,60]*/
        A[num] = rand() % range + 20;
        printf("%d\n",A[num]);
        sum = sum + A[num]; //prosthetoume ton neo arithmo sto sinoliko athrisma tou pinaka
    }
    float avrg = sum/100; //o mesos oros ton arithmon einai to athrisma/plithos arithmon
    printf("O mesos oros ton stoixion einai-->%f\n", avrg);
    
    return 0;
}
