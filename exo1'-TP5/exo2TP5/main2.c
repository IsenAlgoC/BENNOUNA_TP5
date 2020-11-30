#include"tab2.h"
int main() {

	TABLEAU tab = newArray();
	setElement(&tab, 1, 6);

	setElement(&tab, 23, 7);
	displayElements(&tab, 1, 23);
	deleteElements(&tab, 15, 1);
}