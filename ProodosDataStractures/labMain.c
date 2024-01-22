#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------------------------------STOIVA-----------------------------------------------//

typedef struct Ekdilwsh {
    char onoma[50];
    char ora[20];
    char topothesia[50];
} Ekdilwsh;

typedef struct Eisitirio {
    int indexEkdilwshs;
} Eisitirio;

typedef struct StoivaEkdilwsewn {
    Ekdilwsh data[100];
    int koryfi;
} StoivaEkdilwsewn;

void arxikopoiisiStoivas(StoivaEkdilwsewn* stoiva) {
    stoiva->koryfi = -1;
}

int einaiKeniStoiva(StoivaEkdilwsewn* stoiva) {
    return stoiva->koryfi == -1;
}

void pushEkdilwsh(StoivaEkdilwsewn* stoiva, Ekdilwsh ekdilwsh) {
    if (stoiva->koryfi < 99) {
        stoiva->data[++stoiva->koryfi] = ekdilwsh;
    } else {
        printf("Η στοίβα είναι γεμάτη. Δεν μπορεί να προστεθούν άλλες εκδηλώσεις.\n");
    }
}

Ekdilwsh popEkdilwsh(StoivaEkdilwsewn* stoiva) {
    Ekdilwsh keniEkdilwsh = {"", "", ""};
    if (!einaiKeniStoiva(stoiva)) {
        return stoiva->data[stoiva->koryfi--];
    } else {
        printf("Η στοίβα είναι άδεια.\n");
        return keniEkdilwsh;
    }
}

void emfanisiStivasEkdiloseon(StoivaEkdilwsewn* stoiva) {
    if (einaiKeniStoiva(stoiva)) {
        printf("Η στοίβα εκδηλώσεων είναι κενή.\n");
    } else {
        printf("Τρέχουσες Εκδηλώσεις:\n");
        for (int i = 0; i <= stoiva->koryfi; ++i) {
            Ekdilwsh ekdilosi = stoiva->data[i];
            printf("Εκδήλωση \"%s\" stis %s sto %s\n", ekdilosi.onoma, ekdilosi.ora, ekdilosi.topothesia);
        }
    }
    printf("\n\n\n");
}

//-----------------------------------------------OURES-----------------------------------------------//
typedef struct OuraEisitiriwn {
    Eisitirio data[100];
    int arxi, telos;
} OuraEisitiriwn;

typedef struct OuraXriston {
    int data[100];
    int arxi, telos;
} OuraXriston;

void arxikopoiisiOurasEisitiriwn(OuraEisitiriwn* oura) {
    oura->arxi = oura->telos = -1;
}

int einaiKeniOuraEisitiriwn(OuraEisitiriwn* oura) {
    return oura->arxi == -1;
}

void eisagogiEisitiriou(OuraEisitiriwn* oura, Eisitirio eisitirio) {
    if (oura->telos < 99) {
        if (einaiKeniOuraEisitiriwn(oura)) {
            oura->arxi = oura->telos = 0;
        } else {
            oura->telos++;
        }
        oura->data[oura->telos] = eisitirio;
    } else {
        printf("Η ουρά εισιτηρίων είναι γεμάτη. Δεν μπορούν να προστεθούν άλλα εισιτήρια.\n");
    }
}

Eisitirio eksagogiEisitiriou(OuraEisitiriwn* oura) {
    Eisitirio kenoEisitirio = {-1};
    if (!einaiKeniOuraEisitiriwn(oura)) {
        Eisitirio eisitirio = oura->data[oura->arxi];
        if (oura->arxi == oura->telos) {
            arxikopoiisiOurasEisitiriwn(oura);
        } else {
            oura->arxi++;
        }
        return eisitirio;
    } else {
        printf("Η ουρά εισιτηρίων είναι άδεια.\n");
        return kenoEisitirio;
    }
}

void arxikopoiisiOurasXriston(OuraXriston* oura) {
    oura->arxi = oura->telos = -1;
}

int einaiKeniOuraXriston(OuraXriston* oura) {
    return oura->arxi == -1;
}

void eisagogiXristi(OuraXriston* oura, int kodikosXristi) {
    if ((oura->telos + 1) % 100 != oura->arxi) {
        if (einaiKeniOuraXriston(oura)) {
            oura->arxi = oura->telos = 0;
        } else {
            oura->telos = (oura->telos + 1) % 100;
        }
        oura->data[oura->telos] = kodikosXristi;
    } else {
        printf("Η ουρά χρηστών είναι γεμάτη. Δεν μπορούν να προστεθούν άλλοι χρήστες.\n");
    }
}

int eksagogiXristi(OuraXriston* oura) {
    int kenasKodikosXristi = -1;
    if (!einaiKeniOuraXriston(oura)) {
        int kodikosXristi = oura->data[oura->arxi];
        if (oura->arxi == oura->telos) {
            arxikopoiisiOurasXriston(oura);
        } else {
            oura->arxi = (oura->arxi + 1) % 100;
        }
        return kodikosXristi;
    } else {
        printf("Η ουρά χρηστών είναι άδεια.\n");
        return kenasKodikosXristi;
    }
}
//-----------------------------------------------LISTA-----------------------------------------------//
typedef struct KomvosEkdilwshs {
    Ekdilwsh ekdilwsh;
    struct KomvosEkdilwshs* epomenos;
} KomvosEkdilwshs;

typedef struct ListaEkdilwsewn {
    KomvosEkdilwshs* kefali;
} ListaEkdilwsewn;

void arxikopoiisiListaEkdilwsewn(ListaEkdilwsewn* lista) {
    lista->kefali = NULL;
}

void eisagogiEkdilwshs(ListaEkdilwsewn * lista, Ekdilwsh ekdilwsh) {
    KomvosEkdilwshs * neosKomvos = (KomvosEkdilwshs *)malloc(sizeof(KomvosEkdilwshs ));
    if (neosKomvos == NULL) {
        perror("Αποτυχία δέσμευσης μνήμης");
        exit(EXIT_FAILURE);
    }
    neosKomvos->ekdilwsh = ekdilwsh;
    neosKomvos->epomenos = lista->kefali;
    lista->kefali = neosKomvos;
}

void diagrafiOlisthismenisEkdilwshs(ListaEkdilwsewn * lista) {
    if (lista->kefali != NULL) {
        KomvosEkdilwshs * proigoumenosKefali = lista->kefali;
        lista->kefali = lista->kefali->epomenos;
        free(proigoumenosKefali);
    }
}


int main() {
    Ekdilwsh ekdilosi1, ekdilosi2, ekdilosi3,ekdilosi4,ekdilosi5;
    strcpy(ekdilosi1.onoma, "Συναυλία ΠυξΛαξ");
    strcpy(ekdilosi1.ora, "20:00");
    strcpy(ekdilosi1.topothesia, "Π.Ε.Λ.");

    strcpy(ekdilosi2.onoma, "Παρουσιαση Δισκου Airmax");
    strcpy(ekdilosi2.ora, "22:00");
    strcpy(ekdilosi2.topothesia, "Π.Ε.Λ.");

    strcpy(ekdilosi3.onoma, "Το Τάβλι");
    strcpy(ekdilosi3.ora, "20:15");
    strcpy(ekdilosi3.topothesia, "Β. Θεατρική Σκηνή Λαμίας");

    strcpy(ekdilosi4.onoma, "Συναυλία ThraxPunks");
    strcpy(ekdilosi4.ora, "23:00");
    strcpy(ekdilosi4.topothesia, "Λουτρά Υπάτης");

    strcpy(ekdilosi5.onoma, "Χρυσά Κουπιά");
    strcpy(ekdilosi5.ora, "18:30");
    strcpy(ekdilosi5.topothesia, "Α. Θεατρική Σκηνή Λαμίας");

    // Αρχικοποίηση στοίβας εικόνων
    StoivaEkdilwsewn stoivaEkdilwsewn;
    arxikopoiisiStoivas(&stoivaEkdilwsewn);

    // Προσθήκη εικόνων στη στοίβα
    pushEkdilwsh(&stoivaEkdilwsewn, ekdilosi1);
    pushEkdilwsh(&stoivaEkdilwsewn, ekdilosi2);
    pushEkdilwsh(&stoivaEkdilwsewn, ekdilosi3);
    pushEkdilwsh(&stoivaEkdilwsewn, ekdilosi4);
    pushEkdilwsh(&stoivaEkdilwsewn, ekdilosi5);

    emfanisiStivasEkdiloseon(&stoivaEkdilwsewn);
    // Δημιουργία εισιτηρίων για τις εικόνες
    Eisitirio eisitirio1, eisitirio2, eisitirio3, eisitirio4, eisitirio5;
    eisitirio1.indexEkdilwshs = 1;
    eisitirio2.indexEkdilwshs = 2;
    eisitirio3.indexEkdilwshs = 3;
    eisitirio4.indexEkdilwshs = 4;
    eisitirio5.indexEkdilwshs = 5;

    OuraEisitiriwn ouraEisitiriwn;
    arxikopoiisiOurasEisitiriwn(&ouraEisitiriwn);

    // Εισαγωγή διαθέσιμων εισιτηρίων
    eisagogiEisitiriou(&ouraEisitiriwn, eisitirio1);
    eisagogiEisitiriou(&ouraEisitiriwn, eisitirio2);
    eisagogiEisitiriou(&ouraEisitiriwn, eisitirio3);
    eisagogiEisitiriou(&ouraEisitiriwn, eisitirio4);
    eisagogiEisitiriou(&ouraEisitiriwn, eisitirio5);

    // Δημηουργία χρηστών
    OuraXriston ouraXriston;
    arxikopoiisiOurasXriston(&ouraXriston);

    // Εισαγωγή χρηστών που αγόρασαν εισιτήριο
    eisagogiXristi(&ouraXriston, 1);
    eisagogiXristi(&ouraXriston, 2);
    eisagogiXristi(&ouraXriston, 3);
    eisagogiXristi(&ouraXriston, 4);
    eisagogiXristi(&ouraXriston, 5);

    // Εμφάνιση χρηστών που αγόρασαν εισιτήρια
    while (!einaiKeniOuraXriston(&ouraXriston)) {
        int dequeuedUserId = eksagogiXristi(&ouraXriston);
        printf("Ο χρήστης--->%d αγόρασε ειστήριο!\n", dequeuedUserId);
    }

    // Εμφάνιση αγορασμένων εισιτηρίων
    while (!einaiKeniOuraEisitiriwn(&ouraEisitiriwn)) {
        Eisitirio dequeuedTicket = eksagogiEisitiriou(&ouraEisitiriwn);
        printf("Εισιτήριο για την εκδήλωση %d.\n", dequeuedTicket.indexEkdilwshs);
    }

    // Παράδειγμα αφαίρεσης εκδήλωσης
    popEkdilwsh((&stoivaEkdilwsewn));
    popEkdilwsh((&stoivaEkdilwsewn));

    return 0;
}
