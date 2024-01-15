#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 100
#define MAX_ITEMS_STOCK 20
#define NUM_OF_CUSTOMERS 5
struct Item{
    char description[MAX_DESCRIPTION_LENGTH];
    float price;
    int item_count;
    int item_requests;
};

struct Order{
    int customerID;
    int itemID;
};


int main(){
    // dimiourgoume ena seed gia tin sinatisi random(tha tin xrisimopoihsoume stin dimiourgia paraggelias)
    srand(time(NULL));
    struct Item catalog[MAX_ITEMS_STOCK]; // dilwnooume ton katalogo me ta proionta
    // kai sti sinexeia arxikopoioume to kathe pedio ton proionton tou katalogou
    for (int i = 0; i<MAX_ITEMS_STOCK;++i){
        snprintf(catalog[i].description,sizeof(catalog[i].description), "Προϊόν---> %d", i + 1); // os perigrafi se kathe proion dinoume ti leksi proion kai ton kata seira arithmo tou
        catalog[i].price = 40 + (rand() / (RAND_MAX / (100 - 40))); // oi times einai tixaioi arithmoi apo to 40 eos to 100
        catalog[i].item_count = 2; // thetoume tin posotita isi me 2
    }

    int order_pipe[2];
    int result_pipe[2];

    // anoigoume dio agogous gia thn epikoinwnia katastimatos pelath
    pipe(order_pipe);   // afto to pipe ektelei thn paragelia ek merous tou pelati
    pipe(result_pipe);  // enw afto to pipe epistrefei ta stoixeia tis paraggelias

    for(int customer = 0;customer<NUM_OF_CUSTOMERS;++customer){
        pid_t pid = fork();     // to proccess id tis kathe diergasias

        if (pid == 0) {          // an eimaste se child proccess
            close(order_pipe[0]);   // kleinoume ton axrisimopoihto agogo pou exoume gia tin apostoli dedomenon apo ton pelti sto eshop
            close(result_pipe[1]);  // kleinoume ton axrisimopoihto agogo pou exoume gia tin apostoli dedomenon apo to eshop ston pelati
            printf("\nΚωδικός πελάτη--->%d", customer+1);
            for (int i = 0; i < 10; ++i) {  // gia kathe pelati ektelountai 10 paraggelies
                //sleep(05) // anamoni 0.5 sec anamesa se kathe paraggelia
                // dimiourgoume mia paraggelia (tixaia)
                struct Order paraggelia;
                paraggelia.customerID = customer+1;
                paraggelia.itemID = rand() % MAX_ITEMS_STOCK;

                // stelnoume tin paraggelia sto eshop
                write(order_pipe[1], &paraggelia, sizeof(struct Order));

                // dexomaste to apotelesma tis paraggelias (apo to eshop os apantisi)
                int result;
                read(result_pipe[0], &result, sizeof(int));
                printf("\nΑποτέλεσμα παραγγελίας--->%d", result);
            }
            // kleinoume tous agogous pou xrisimopoihthikan
            close(order_pipe[1]);
            close(result_pipe[0]);
            exit(0);

        }else if (pid > 0) {   // patriki diergasia (eshop)
            close(order_pipe[1]);
            close(result_pipe[0]);
            struct Order paraggelia;
            sleep(1);   // eikoniki anamoni 1 defteroleptou
            read(order_pipe[0], &paraggelia, sizeof(paraggelia));
            catalog[paraggelia.itemID].item_requests++;
            if(catalog[paraggelia.itemID].item_count>0){     // elegxoume an iparxei diathesimo apothema
                 --catalog[paraggelia.itemID].item_count; // meiewnoume kata ena to apothema tou proiontos
                int success = 1;
                write(result_pipe[1], &success, sizeof(success));
                printf("\nΟ πελάτης %d παρήγγειλε %s", paraggelia.customerID,catalog[paraggelia.itemID].description);
            }else{
                // apostoli minimatos apotixias
                int failure = 0;
                write(result_pipe[1], &failure, sizeof(failure));
                printf("\nΗ παραγγελία του πελάτη απέτυχε λόγο έλλειψης αποθεμάτων!");
            }
            close(order_pipe[0]);
            close(result_pipe[1]);
        }else{
            printf("Τερματικό σφάλμα κατά την εκτέλεση της παραγγελίας(θυγατρικής λειτουργίας)!");
            exit(-1);
        }

    }
    // pragmatopoioume mia anafora gia ton tziro pou ekane to katastima
    printf("\nΑναφορά τζίρου από eshop:\n");
    int sum = 0;
    for (int i = 0; i < MAX_ITEMS_STOCK; ++i){
        printf("\n\nΠροϊόν---> %d \nΑιτήματα--->%d \nΠωλήσεις--->%f", i+1, catalog[i].item_requests,catalog[i].price*(2- catalog[i].item_count));
        sum+=catalog[i].price*(2-catalog[i].item_count);
    }
    printf("\nΣυνολικός τζίρος--->%d", sum);
    return 0;
}


