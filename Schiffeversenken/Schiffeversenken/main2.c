/*
#include <stdio.h>
#include "spielfeld.h"
#include <string.h>
#include <stdlib.h>
#include "clearScreen.h"
int mains(){
	//Deklaration
	int fieldsize=0,z,schlacht,schlachta,schlachtg,kreuzer,kreuzera,kreuzerg,zerstoerer,zerstoerera,zerstoererg,ubootg,uboot,uboota;
	char a[1];
	int run=1;
	printf("			Schiffeversenken\n\n");
	while(run==1){
	printf("Wie gross wollen Sie ihr Feld haben?\nMinimum : 5 , Maximum 26\n");
	scanf("%d",&fieldsize);
	start(fieldsize);
	printf("Feld uebernehme ? J/N\n");
	scanf("%s",a);
	if((strcmp(a,"J")!=1)||((strcmp(a,"j"))!=1)){
		CLEAR
		run=0;
	}
	}
	printf("Vergfuegbare Schiffe:\n\tSchlachtschiff\n\tKreuzer\n\tZerstoerer\n\tU-Boote\n");
	printf("Groeﬂe der Schlachtschiffe? ");
	scanf("%d",&schlachtg);
	printf("\nAnzahl der Schlachtschiffe :");
	scanf("%d",&schlachta);
	printf("\nGroeﬂe der Kreuzer? ");
	scanf("%d",&kreuzerg);
	printf("\nAnzahl der Krzeuer :");
	scanf("%d",&kreuzera);
	printf("\nGroeﬂe der Zerstoerer? ");
	scanf("%d",&zerstoererg);
	printf("\nAnzahl der Zerstoerer :");
	scanf("%d",&zerstoerera);
	printf("\nGroeﬂe der U-Boote? ");
	scanf("%d",&ubootg);
	printf("\nAnzahl der U-Boote :");
	scanf("%d",&uboota);

	getchar();
	getchar();
	return 0;
}
*/
