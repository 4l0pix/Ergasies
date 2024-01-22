/*Ta sxolia stin parakato askisi einai grammena se greeklish
 *gia tin apofigi sfalmaton kata tin anagnwsi apo diaforetika programmata*/

#include<stdio.h>
#include<stdlib.h>

/* Tha ylopoihsoume th domh ths dinamikis stoivas
 *me th xrhsh mias listas*/
struct Node{            // Dimiourgoume ti domi tou komvou
    int data;           // pou apoteleitai apo to pedio ton dedomenon
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

int pop(struct Stack* stack){
    if (isEmpty(stack)) {
        printf(Υποχείλιση στοίβας\n");
        exit(EXIT_FAILURE);
    }
    int data = stack->top->data;    // Antloume ta dedomena apo ton komvo top
    struct Node* temp = stack->top; // Dimiourgia enos prosorinou komvou ston opoio antigrafoume ton komvo top
    stack->top = stack->top->next;  // Metakinisi tou top ston epomeno komvo
    free(temp);                 // Dagrafi tou prosorinou komvou (prwhn top)
    return data;                    // Epistrofh ton dedomenon pou diagrafikan
}

void display(struct Stack* stack){
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

int main(){
    struct Stack stoiva;        // Dimiourgoume mia domi stoivas
    initStack(&stoiva);   // Arxikopoioume ti stoiva
    /* Se afto to simeio tha eisagoume dedomena sth stoiva
     * afto mporoume na to kanoume eite mesw mias domis epanalipsis
     * me input apo to xristi
     * i stin periptosi mas gia logous aplotitas tha eisagoume manually
     * kapoies times*/
    push(&stoiva,4);
    push(&stoiva,-6);
    push(&stoiva,13);
    push(&stoiva,0);
    printf("\nΗ στοίβα περιέχει τα στοιχεία:");
    display(&stoiva); // Emfanisi ton perioexomenon tis stoivas
    printf("\nΔιαγράφτηκε το στοιχείο %d από τη στόιβα!", pop(&stoiva)); // Diagrafi stoixeiou apo ti stoiva
    printf("\nΔιαγράφτηκε το στοιχείο %d από τη στόιβα!", pop(&stoiva)); // Diagrafi enos akoma stoixeiou
    printf("\nΗ στοίβα περιέχει τα στοιχεία:");
    display(&stoiva); //Emfanisi ton perieoxomenon tis stoivas meta ti diagrafi 2 stoixeion
    return 0;
}
