#include<stdio.h>
#include<stdlib.h>

#define MAX_TEST_SIZE 100

//-----------------------------------------------STOIVA-----------------------------------------------//
struct StackNode{            // Dimiourgoume ti domi tou komvou
    char ekdilwsi[MAX_TEXT_SIZE];           // pou apoteleitai apo to pedio ton dedomenon
    struct Node* next;  // kai ton deikti gia ton epomeno komvo
};

struct Stack{           // Dimiourgoume ti domi tis stoivas
    struct Node* top;   // i opoia exei os stoixeio tis ton komvo top
};

void initStack(struct Stack* stack){ // Arxikopoihsh ths stoivas
    stack->top = NULL;      // O komvos top exei timh null ara h stoiva einai adeia
}

int isEmpty(struct Stack* stack){  // Elegxos: an h stoiva einai adeia
    return (stack->top == NULL);    // An o top exei periexomeno NULL tote h stoiva den exei kamia timi
}                                   // Ara i sinthiki epistrefei 1 diaforetika 0 (alithis || psevdis)

void push(struct Stack* stack, int item){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Dimiourgia enos neou komvou
    if (newNode == NULL) {      // Elegxos epitixias tis dimiourgeias tou komvou
        printf("Σφάλμα δημιουργίας νέου κόμβου!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = item;       // Anathesi tis timis pou dothike sto pedio ton dedomenon
    newNode->next = stack->top; // O neos komvos deixnei ston top
    stack->top = newNode;       // O neos komvos ginetai o top
}

void pop(struct Stack* stack){
    if (isEmpty(stack)) {
        printf(Υποχείλιση στοίβας\n");
        exit(EXIT_FAILURE);
    }
    char data = stack->top->data;    // Antloume ta dedomena apo ton komvo top
    struct StackNode* temp = stack->top; // Dimiourgia enos prosorinou komvou ston opoio antigrafoume ton komvo top
    stack->top = stack->top->next;  // Metakinisi tou top ston epomeno komvo
    free(temp);                 // Dagrafi tou prosorinou komvou (prwhn top)
}

void displayStack(struct Stack* stack){
    if (isEmpty(stack)) {
        printf("Η στοίβα είναι άδεια!\n");
    }
    else{
        struct Node* current = stack->top;       // Dimiourgia "trexon" komvou pros provoli (ksekiname apo ton top)
        while (current != NULL) {                // Mexri loipon o current na ginei NULL
            printf("\n--->%d", current->data); // Emfanizoume to perioxomeno tou komvou
            current = current->next;            // Kai o current ginetai o epomenos komvos
        }
    }
}
//-----------------------------------------------STOIVA-----------------------------------------------//

//-----------------------------------------------OURA-----------------------------------------------//
struct QueueNode{            // Dimiourgoume ti domi tou komvou
    int data;           // pou apoteleitai apo to pedio ton dedomenon
    struct Node* next;  // kai ton deikti gia ton epomeno komvo
};

struct Queue {          // Dimiourgoume ti domi tis stoivas
    struct QueueNode* front; // Pou xrisimopoiei tous xaraktiristikous komvous front
    struct QueueNode* rear;  // Kai rear
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

void displayQueue(struct Queue* queue) {
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
//-----------------------------------------------OURA-----------------------------------------------//

//-----------------------------------------------LISTA-----------------------------------------------//
struct ListNode {   // Dimiourgoume ti domi tou komvou
    int data;       // Dimiourgoume to meros pou tha apothikevei ta dedomena
    struct ListNode* next;  // Dimiourgoume to meros pou tha apothikevei ton epomeno komvo(deikti gia ton epomeno)
};

// Dilwsi neou komvou
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//  Sinartisi gia tin eisagwgh neou komvou stin arxi tis listas
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Sinartisi gia tin mefanisi ton periexomenwn tis listas
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//-----------------------------------------------LISTA-----------------------------------------------//


int main(){
//STOIVA
    struct Stack stoiva;        // Dimiourgoume mia domi stoivas
    initStack(&stoiva);   // Arxikopoioume ti stoiva
//OURA
    struct Queue oura; // Dimiourgoume th domh ths ouras
    initQueue(&oura); // Arxikopoioume tin oura
//APLI LISTA

//DIPLA SINDEDEMENI LISTA
    push(&stoiva, "To Tavli");
    enqueue(&oura, 700);
    push(&stoiva, "20lepto"); 
    enqueue(&oura,1500);
    push(&stoiva, "Airmax");
    enqueue(&oura, 3000);
    push(&stoiva, "Oneiro Therinis Nyktos");
    enqueue(&oura, 1000);
    displayStack(&stoiva);
    
    return 0;
}
