/*Ta sxolia stin parakato askisi einai grammena se greeklish
 *gia tin apofigi sfalmaton kata tin anagnwsi apo diaforetika programmata*/

#include<stdio.h>
#include<stdlib.h>

/* Tha ylopoihsoume th domh ths dinamikis ouras
 *me th xrhsh mias listas*/
struct Node{            // Dimiourgoume ti domi tou komvou
    int data;           // pou apoteleitai apo to pedio ton dedomenon
    struct Node* next;  // kai ton deikti gia ton epomeno komvo
};

struct Queue {          // Dimiourgoume ti domi tis 
    struct Node* front; // Pou xrisimopoiei tous xaraktiristikous komvous front
    struct Node* rear;  // Kai rear
};

void initQueue(struct Queue* queue) { // Arxikopoihsh ths ouras
    queue->front = NULL;    // Oi komvoi front kai rear pairnun tin timi NULL
    queue->rear = NULL;     // Epeidi i oura einai adeia
}

int isEmpty(struct Queue* queue) {  // Elegxos: an h oura einai adeia
    return (queue->front == NULL);  // An o front exei periexomeno NULL tote h stoiva den exei kamia timi
}                                   // Ara i sinthiki epistrefei 1 diaforetika 0 (alithis || psevdis)

void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));   // Dimiourgia neou komvou
    if (newNode == NULL) {           // Elegxos epitixias tis dimiourgeias tou komvou
        printf("Σφάλμα δημιουργίας νέου κόμβου!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = item;           // Anathesi tis timis pou dothike sto pedio ton dedomenon
    newNode->next = NULL;
    if (isEmpty(queue)) {           // An i oura einai adeia ( i sinthiki afti tha lavei tin timi 1)
        queue->front = newNode;     // Tote o komvos front
        queue->rear = newNode;      // Kai o rear isountai
    } else {
        queue->rear->next = newNode;    // Alliws eisagoume ton neo komvo meta ton rear
        queue->rear = newNode;          // kai enhmerwnoume ton rear (einai pleon o neos komvos)
    }
}
int dequeue(struct Queue* queue) {      // Aferaish stoixeiou apo thn oura
    if (isEmpty(queue)) {               // An h oura einai adeia tote prokyptei ypoxeilish
        printf("Υποχείλιση ουράς!\n"); // Ara den mporoume na aferaisoume kapoio stoixeio
        exit(EXIT_FAILURE);
    }
    int data = queue->rear->data;       // Antloume ta dedomena apo ton komvo rear
    if (queue->front == queue->rear) {  // An o front kai o rear einai isoi
        free(queue->rear);          // Diagrafoume to teleftaio stoixeio ths ouras
        queue->front = NULL;            // Kai thetoume ton front
        queue->rear = NULL;             // Kai ton rear se NULL
    } else {                            // alliws
        struct Node* rearPrev = queue->front;   // kanoume mia prospelasi
        while (rearPrev->next != queue->rear) { // vriskume ton proteleftaio komvo
            rearPrev = rearPrev->next;          // kai ton apothikevoume
        }
        free(queue->rear);          // Diagrafoume ton komvo rear
        queue->rear = rearPrev;         // Kai ti thesi tou pairnei o proteleftaios
        queue->rear->next = NULL;       // Etsi o pointer tou rear ginetai NULL
    }
    return data;    // kai epistrefoume pros emfanisi tin timi pou diagrapsame
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Η ουρά είναι άδεια!\n");
    }else{
        struct Node* current = queue->front;        // Dimiourgia "trexon" komvou pros provoli (ksekiname apo ton front)
        while (current != NULL) {                   // Mexri loipon o current na ginei NULL
            printf("\n%d ", current->data);  // Emfanizoume to perioxomeno tou komvou
            current = current->next;               // Kai o current ginetai o epomenos komvos
        }
    }
}

int main(){
    struct Queue oura; // Dimiourgoume th domh ths ouras
    initQueue(&oura); // Arxikopoioume tin oura
    /* Se afto to simeio tha eisagoume dedomena sthn oura
     * afto mporoume na to kanoume eite mesw mias domis epanalipsis
     * me input apo to xristi
     * i stin periptosi mas gia logous aplotitas tha eisagoume manually
     * kapoies times*/
    enqueue(&oura,12);
    enqueue(&oura,45);
    enqueue(&oura,100);
    enqueue(&oura,0);
    enqueue(&oura,-43);
    printf("\nΗ ουρά περιέχει τα στοιχεία:");
    display(&oura); // Emfanisi ton perioexomenon tis ouras
    printf("\nΔιαγράφτηκε το στοιχείο %d από την ουρά!", dequeue(&oura)); // Diagrafi stoixeiou apo tin oura
    printf("\nΔιαγράφτηκε το στοιχείο %d από την ουρά!", dequeue(&oura)); // Diagrafi enos akoma stoixeiou
    printf("\nΗ ουρά περιέχει τα στοιχεία:");
    display(&oura); //Emfanisi ton perieoxomenon tis ouras meta ti diagrafi 2 stoixeion
    return 0;
}
