#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//DIMIOURGIA DIADIKOU DENDROU ANAZITISIS
// Domi gia ton komvo tou diadikou dendrou
struct TreeNode {
    int data;   // Dimiourgoume to pedio dedomenon tou komvou(edw apothikevetai to key)
    struct TreeNode* left;  // Dimiourgoume tin akmi gia to aristero ipodendro
    struct TreeNode* right; // Kai gia to deksi
};
// Sinartisi gia tin dimiourgia neou komvou
struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));   // Desmevoume tin aparaititi mnimi gia ton neo komvo
    newNode->data = key;    // Apothikevoume to stoixeio ston komvo
    newNode->left = NULL;   // Kai ylopoioume tin dimiourgeia ton akmon(mexri na prostethei neo stoixeio einai mono "akmes xwris komvous", gia afto kai to NULL)
    newNode->right = NULL;
    return newNode;
}

// Sinartisi gia tin eisagogi komvou sto diadiko dendro
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Sinartisi gia tin anazitisi kleidiou(komvou) sto diadiko dendro
struct TreeNode* search(struct TreeNode* root, int key) {   // Dexomaste os orisma to dendro kai to stoixeio pros anazitisi
    if (root == NULL || root->data == key) {    // An to dendro einai keno, epistrefoume NULL, enw an vrethei to stoixeio ston komvo, epistrefoume ton komvo
        return root;
    }
    if (key < root->data) { // An to stoixeio einai mikrotero apo to stoixeio tou komvou pou vriskomaste, tote to stoixeio pros anazitisi vrisketai sto left
        return search(root->left, key);
    }else{
        return search(root->right, key);    // Diaforetika, vrisketai sto right
    }

}

int ipologismosKomvon(float d, float h) {  // Sinarthsh gia ton ipologismo tou megistou arithmou komvon
    // Xrhsimopoioume ton eksis tipo N = (d^(h+1) - 1) / (d - 1)
    float result = (pow(d, h + 1) - 1) / (d - 1);
    return (int)result; // Kai metatrepoume to apotelesma se akeraio
}

int main() {
    struct TreeNode* riza = NULL;   // Dimiourgoume to diadiko dendro
    // Eisagoume kapoious komvous
    /* Fysika, otan anaferomaste stous komvous me to onoma riza, den milame gia ton idio(arxiko) komvo kathe fora,
     * alla gia to kathe ipodendro ksexwrista. Isxyeio oti: kathe komvos einai riza tou ypodendrou tou*/
    riza = insertNode(riza, 4);
    insertNode(riza, 12);
    insertNode(riza, 27);
    insertNode(riza, 56);
    insertNode(riza, 2);
    insertNode(riza, 0);
    insertNode(riza, 23);
    insertNode(riza, 44);
    insertNode(riza, 16);
    insertNode(riza, 145);
    insertNode(riza, 0);
    // Anazitoume kapoio kleidi(afto yparxei)
    int searchKey = 23;
    struct TreeNode* searchResult = search(riza,searchKey); // kaloume tin sinartisi
    if (searchResult != NULL) { // kai an to apotelesma itan diaforo tou NULL to kleidi vrethike
        printf("Ο κόμβος με την τιμή %d βρέθηκε.\n",searchKey);
    } else {    // Diaforetika, to kleidi den iparxei sto dendro
        printf("Ο κόμβος με την τιμή %d δεν βρέθηκε.\n",searchKey);
    }

    // Edw tha ginei o ipologismos tou allou erwthmatos'
    float d,h; // d = o vathmos --- h = ipsos tou dendrou
    printf("Εισάγετε τον βαθμό (d) του δένδρου: \n");
    scanf("%f", &d);

    printf("Εισάγετε το ύψος (h) του δένδρου: \n");
    scanf("%f", &h);

    // Calculating and printing the number of nodes
    int result = ipologismosKomvon(d, h);
    printf("Ο αριθμός των κόμβων στο δένδρο είναι: %d\n", result);
    return 0;
}
