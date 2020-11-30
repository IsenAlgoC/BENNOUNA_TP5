#include"tab.h"
#define TAB2SIZE 100
#define TAILLEAJOUT 50
int initTab(int* tab, int size) {
	for (int i = 0; i < size; i++)
	{
		tab[i] = 0;
	}
	if (tab = 0 || size < 0)
	{
		return -1;

	}

};

int afficheTab(int* tab, int size, int nbElts) {
	if (tab == NULL) {
		return -1;
	}
	if (size < 0) {
		return -1;
	}
	if (size < nbElts) {
		return -1;
	}
	else {
		for (int i = 0; i < nbElts; ++i) {
			printf("%u ", tab[i]);
		}
		return 0;
	}
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (*nbElts == *size) {
		int* tabnew = (int*)realloc(tab, (TAB2SIZE + TAILLEAJOUT) * sizeof(int)); // on crée un tableau tampon auquel on ajoute la mémoire
		if (tabnew == NULL) {
			return NULL;
		}//si ça ne marche pas on renvoie -1
		else { // sinon on remplace tab par tabnew et on change les valeurs.
			tab = tabnew;
			tab[*nbElts] = element;
			*nbElts = *nbElts + 1;
		}
	}
	else {
		tab[*nbElts] = element;
		*nbElts = *nbElts + 1;
	}
	return tab;
}