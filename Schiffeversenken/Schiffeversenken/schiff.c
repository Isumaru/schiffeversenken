#include <stdlib.h>
#include "schiff.h"
/*Methode makeSchiff erzeugt eine Struktur von Schiff und setzt
 *die uebergebenen Variablen
*/
struct schiff* makeSchiff(int size,int life){
	struct schiff *myschiff;
	myschiff = malloc (sizeof(struct schiff));
	myschiff->size=size;
	myschiff->life=life;
	return myschiff;
}