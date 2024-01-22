/*Ta sxolia stin parakato askisi einai grammena se greeklish
 *gia tin apofigi sfalmaton kata tin anagnwsi apo diaforetika programmata*/
#include <stdio.h>
#include <stdlib.h>

/* Tha ylopoihsoume th domh ths dinamikis ouras
 *me th xrhsh mias listas*/
struct Node{            // Dimiourgoume ti domi tou komvou
    int data;           // pou apoteleitai apo to pedio ton dedomenon
    struct Node* next;  // kai ton deikti gia ton epomeno komvo
};

struct circQueue {          // Dimiourgoume ti domi tis ouras
    struct Node* front; // Pou xrisimopoiei tous xaraktiristikous komvous front
    struct Node* rear;  // Kai rear
};

void initCircularQueue(struct circQueue* queue) {   // Arxikopoihsh ths ouras
    queue->front = NULL;                            // Oi komvoi front kai rear pairnun tin timi NULL
    queue->rear = NULL;                             // Epeidi i oura einai adeia
}

int isEmpty(struct circQueue* queue) {              // Elegxos: an h oura einai adeia
    return (queue->front == NULL);                  // An o front exei periexomeno NULL tote h stoiva den exei kamia timi
}                                                   // Ara i sinthiki epistrefei 1 diaforetika 0 (alithis || psevdis)

void enqueue(struct circQueue* queue, int item) {   // Dimiourgia neou komvou
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {      // Elegxos epitixias tis dimiourgeias tou komvou
        printf("Σφάλμα δημιουργίας νέου κόμβου!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = item;       // Anathesi tis timis pou dothike sto pedio ton dedomenon
    newNode->next = NULL;
    if (isEmpty(queue)) {       // An i oura einai adeia ( i sinthiki afti tha lavei tin timi 1)
        queue->front = newNode; // Tote o komvos front
        queue->rear = newNode;  // Kai o rear isountai
    } else {
        queue->rear->next = newNode;    // Alliws eisagoume ton neo komvo meta ton rear
        queue->rear = newNode;          // kai enhmerwnoume ton rear (einai pleon o neos komvos)
    }
    queue->rear->next = queue->front;   // "Ennonoume" ton proto me ton teleftaio komvo
}

int dequeue(struct circQueue* queue) {  // Aferaish stoixeiou apo thn oura
    if (isEmpty(queue)) {               // An h oura einai adeia tote prokyptei ypoxeilish
        printf("Υποχείλιση ουράς!\n");   // Ara den mporoume na aferaisoume kapoio stoixeio
        exit(EXIT_FAILURE);
    }
    int data = queue->front->data;          // Antloume ta dedomena apo ton komvo rear
    if (queue->front == queue->rear) {      // An o front kai o rear einai isoi
        free(queue->front);             // Diagrafoume to teleftaio stoixeio ths ouras
        queue->front = NULL;                // Kai thetoume ton front
        queue->rear = NULL;                 // Kai ton rear se NULL
    } else {                                // alliws
        struct Node* temp = queue->front;   // kanoume mia prospelasi
        queue->front = queue->front->next;  // kai ton apothikevoume
        free(temp);                     // Diagrafoume ton komvo rear
        queue->rear->next = queue->front;   // "Ennonoume" ton proto me ton teleftaio komvo
    }
    return data;                            // kai epistrefoume pros emfanisi tin timi pou diagrapsame
}

void display(struct circQueue* queue) {
    if (isEmpty(queue)) {
        printf("Η κυκλική ουρά είναι άδεια!\n");
    }else{
        struct Node* current = queue->front;    // Dimiourgia "trexon" komvou pros provoli (ksekiname apo ton front)
        do {
            printf("%d ", current->data);  // Emfanizume ta periexomena tis ouras
            current = current->next;              /* Proxorame ston epomeno (amesos meta tin proti prospellasi allazei o komvos
            * apo front kai gia afto ginetai kai i xrisi tis do while,
            // etsi oste na epitefxthei toulaxiston mia epanalipsi)*/
        } while (current != queue->front);        // Mexri o trexon komvos na ksanaginei o front
        printf("\n");
    }
}

int main() {
    struct circQueue circQueue;     // Dimiourgoume th domh ths kiklikis ouras
    initCircularQueue(&circQueue);  // Arxikopoioume tin oura
    /* Se afto to simeio tha eisagoume dedomena sthn oura
     * afto mporoume na to kanoume eite mesw mias domis epanalipsis
     * me input apo to xristi
     * i stin periptosi mas gia logous aplotitas tha eisagoume manually
     * kapoies times*/
    enqueue(&circQueue, 10);
    enqueue(&circQueue, 20);
    enqueue(&circQueue, 30);
    enqueue(&circQueue,40);
    printf("\nΗ ουρά περιέχει τα στοιχεία:");
    display(&circQueue);    // Emfanisi ton perioexomenon tis ouras
    printf("\nΔιαγράφτηκε το στοιχείο %d από την ουρά!", dequeue(&circQueue));  // Diagrafi stoixeiou apo tin oura
    printf("\nΗ ουρά περιέχει τα στοιχεία: ");
    display(&circQueue);    // Emfanisi ton perioexomenon tis ouras
    return 0;
}

