#include "spieler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct spieler* makeSpieler(char name[],int wTreffer,int sTreffer){
	struct spieler *myspieler;
	myspieler = malloc (sizeof(struct spieler));
	strcpy(myspieler->name,name);
	myspieler->wTreffer=wTreffer;
	myspieler->sTreffer=sTreffer;
	return myspieler;
}
