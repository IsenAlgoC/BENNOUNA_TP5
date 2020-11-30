#include"tab2.h"
#define TAILLEINITIALE 100
TABLEAU newArray() {
    TABLEAU tab;
    tab.elt = (int*)malloc(TAILLEINITIALE * sizeof(int));
    tab.eltsCount = 0;
    tab.size = TAILLEINITIALE;
    if (tab.elt != NULL) {
        for (int i = 0; i < TAILLEINITIALE; ++i) {
            tab.elt[i] = 0;
        }
        return tab;
    }
    else {
        tab.elt = NULL;
        return tab;
    }
}
int incrementArraySize(TABLEAU* tab, int incrementValue) {
    if ((*tab).elt == NULL || ((*tab).size + incrementValue) <= 0) {         // test de validité
        return -1;
    }

    int* save;
    save = (int)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int));       // on alloue la nouvelle mémoire

    if (save == NULL) {                                                                   // on vérifie que la mémoire est bien allouée
                                                                            // si ça n'est pas le cas, on annule la réallocation
        return -1;
    }
    (*tab).elt = save;
    for (int i = (*tab).size; i < (*tab).size + incrementValue; i++) {                      // initialisation à 0 de toutes les nouvelles valeurs
        (*tab).elt[i] = 0;
    }
    (*tab).size += incrementValue;                          // on augmente la taille du tableau
    return (*tab).size;
}
int setElement(TABLEAU* tab, int pos, int element) {
    if (pos - 1 < tab->size) {

        (*tab).elt[pos - 1] = element;
        return pos;
    }
    else {
        if (incrementArraySize(tab, pos - tab->size) != -1) {
            (*tab).elt[pos - 1] = element;
            return pos;
        }
        else
        {
            return 0;
        }


    }
}
int displayElements(TABLEAU* tab, int startPos, int endPos) {
    for (int i = startPos - 1; i < endPos; i++)
    {
        printf("%u ", (*tab).elt[i]);
    }
}
int deleteElements(TABLEAU* tab, int startPos, int endPos) {
    int temp = 0;
    if (startPos<1 || endPos<1 || startPos>(*tab).size || endPos>(*tab).size) {       // test de validité
        return -1;
    }
    if (startPos > endPos) {
        temp = startPos;
        startPos = endPos;                                                             // de meme cas où l'utilisateur a échanger les bornes
        endPos = temp;
    }
    if (startPos == endPos) {                                                        // si startpos egale endpos on eneleve qu'un seul element 
        if (startPos == (*tab).size) {
            incrementArraySize(tab, -1);    // si c'est le dernier element alors on a juste a réduire la taille du tableau de 1 cela va juste supprimer le dernier element
            return (*tab).size;
        }
        for (int i = 0; i < (*tab).size - startPos; ++i) {
            (*tab).elt[startPos + i - 1] = (*tab).elt[startPos + i];   //sinon on décale tout vers la gauche puis on enleve le dernier element grace a incrementarraysize
        }
        if (incrementArraySize(tab, -1) == -1) {
            return -1;
        }
        return (*tab).size;
    }
    for (int c = 0; c < (endPos - startPos) + 1; ++c) {               // on repete l'action au dessus où startpos=endpos (end-startpos) fois afin d'enelever (endpos-startpos)elements
        for (int i = 0; i < (*tab).size - startPos; ++i) {
            (*tab).elt[startPos + i - 1] = (*tab).elt[startPos + i];;
        }
        incrementArraySize(tab, -1);
    }
    return (*tab).size;
};