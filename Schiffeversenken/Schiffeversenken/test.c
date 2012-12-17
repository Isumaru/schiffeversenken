#include "spielfeld.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clearScreen.h"
#include "schiff.h"
#include "spieler.h"
int main(){
	//Deklaration der benötigten Variablen
	char p1[2],p2[1],input[2],sp1name[20],sp2name[20];
	struct spieler *sp1,*sp2;
	struct spielfeld c;
	struct spielfeld *sp1feld,*sp2feld,*fieldbackup;
	struct schiff **sp1schlacht,**sp2schlacht,**sp1kreuzer,**sp2kreuzer,**sp1zerstoerer,**sp2zerstoerer,**sp1uboot,**sp2uboot;
	int id,i,fieldsize,run=1,schlachta,schlachtg,kreuzera,kreuzerg,zerstoerera,zerstoererg,ubootg,uboota;
	// "GUI" 
	printf("\t\tSchiffeversenken\n\n");
	printf("Spieler 1 geben Sie Ihren Namen ein: ");
	scanf("%s",sp1name);
	sp1=makeSpieler(sp1name,0,0);
	printf("Spieler 2 geben Sie Ihren Namen ein: ");
	scanf("%s",sp2name);
	sp2=makeSpieler(sp2name,0,0);
	while(run==1){
	printf("Wie gross wollen Sie ihr Feld haben?\nMinimum : 5 , Maximum 26\n");
	scanf("%d",&fieldsize);
	sp1feld=makeSpielfeld(fieldsize);
	showSpielfeld(fieldsize,sp1feld->meinFeld);
	printf("Feld uebernehme ? J/N\n");
	scanf("%s",input);
	if((strcmp(input,"J")==0)||((strcmp(input,"j"))==0)){
		CLEAR;
		run=0;
		sp2feld=makeSpielfeld(fieldsize);
	}
	}
	printf("Vergfuegbare Schiffe:\n\tSchlachtschiff\n\tKreuzer\n\tZerstoerer\n\tU-Boote\n");
	printf("\nAnzahl der Schlachtschiffe :");
	scanf("%d",&schlachta);
	sp1schlacht= malloc(schlachta * sizeof(int *));
	sp2schlacht= malloc(schlachta * sizeof(int *));
	printf("Groesse der Schlachtschiffe?: ");
	scanf("%d",&schlachtg);
	for(i=0;i<schlachta;i++){
		sp1schlacht[i]=makeSchiff(schlachtg,schlachtg);
		sp2schlacht[i]=makeSchiff(schlachtg,schlachtg);
		sp1schlacht[i]->ID=schlachtg;
		sp2schlacht[i]->ID=schlachtg;
	}
	printf("Anzahl der Kreuzer: ");
	scanf("%d",&kreuzera);
	sp1kreuzer= malloc(kreuzera * sizeof(int *));
	sp2kreuzer= malloc(kreuzera * sizeof(int *));
	printf("Groesse der Kreuzer?: ");
	scanf("%d",&kreuzerg);
	for(i=0;i<kreuzera;i++){
		sp1kreuzer[i]=makeSchiff(kreuzerg,kreuzerg);
		sp2kreuzer[i]=makeSchiff(kreuzerg,kreuzerg);
		sp1kreuzer[i]->ID=kreuzerg;
		sp2kreuzer[i]->ID=kreuzerg;
	}
	printf("Anzahl der Zerstoerer: ");
	scanf("%d",&zerstoerera);
	sp1zerstoerer= malloc(zerstoerera * sizeof(int *));
	sp2zerstoerer= malloc(zerstoerera * sizeof(int *));
	printf("Groesse der Zerstoerer?: ");
	scanf("%d",&zerstoererg);
	for(i=0;i<zerstoerera;i++){
		sp1zerstoerer[i]=makeSchiff(zerstoererg,zerstoererg);
		sp2zerstoerer[i]=makeSchiff(zerstoererg,zerstoererg);
		sp1zerstoerer[i]->ID=zerstoererg;
		sp2zerstoerer[i]->ID=zerstoererg;
	}
	printf("Anzahl der U-Boote: ");
	scanf("%d",&uboota);
	sp1uboot= malloc(uboota * sizeof(int *));
	sp2uboot= malloc(uboota * sizeof(int *));
	printf("Groesse der U-Boote?: ");
	scanf("%d",&ubootg);
	for(i=0;i<uboota;i++){
		sp1uboot[i]=makeSchiff(ubootg,ubootg);
		sp2uboot[i]=makeSchiff(ubootg,ubootg);
			sp1uboot[i]->ID=ubootg;
			sp2uboot[i]->ID=ubootg;
	}
	CLEAR;
	printf("Schiffe Platzieren fuer %s \nBsp. Eingabe :\n\tStartpunkt? A5\n\tSenkrecht(s)/Waagrecht(w)? w \n\nSetzen der %d Schlachtschiffe:\n",sp1->name,schlachta);
	showSpielfeld(fieldsize,sp1feld->meinFeld);
	for(i=0;i<schlachta;i++){
		printf("%d.Schiff setzen\nStartpunkt ? ",i+1);
		scanf("%s",p1);
		printf("Senkrecht(s)/Waagrecht(w)? ");
		scanf("%s",p2);
		c=*sp1feld;
		fieldbackup=&c;
		sp1feld=setSchiff(sp1feld,sp1schlacht[i],p1,p2);
		if(sp1feld==NULL){
			sp1feld=fieldbackup;
			printf("Sie koennen nicht Schiffe ueber andere Schiffe legen\n");
			i=i-1;
		}
		showSpielfeld(fieldsize,sp1feld->meinFeld);
	}
	printf("Schiffe Platzieren fuer %s\nSetzen der %d Kreuzer :\n",sp1->name,kreuzera);
	showSpielfeld(fieldsize,sp1feld->meinFeld);
	for(i=0;i<kreuzera;i++){
		printf("%d.Schiff setzen\nStartpunkt ? ",i+1);
		scanf("%s",p1);
		printf("Senkrecht(s)/Waagrecht(w)? ");
		scanf("%s",p2);
		c=*sp1feld;
		fieldbackup=&c;
		sp1feld=setSchiff(sp1feld,sp1kreuzer[i],p1,p2);
		if(sp1feld==NULL){
			sp1feld=fieldbackup;
			printf("Sie koennen nicht Schiffe ueber andere Schiffe legen\n");
			i=i-1;
		}
		showSpielfeld(fieldsize,sp1feld->meinFeld);
	}
	printf("Schiffe Platzieren fuer %s\nSetzen der %d Zerstoerer :\n",sp1->name,zerstoerera);
	showSpielfeld(fieldsize,sp1feld->meinFeld);
	for(i=0;i<zerstoerera;i++){
		printf("%d.Schiff setzen\nStartpunkt ? ",i+1);
		scanf("%s",p1);
		printf("Senkrecht(s)/Waagrecht(w)? ");
		scanf("%s",p2);
		c=*sp1feld;
		fieldbackup=&c;
		sp1feld=setSchiff(sp1feld,sp1zerstoerer[i],p1,p2);
		if(sp1feld==NULL){
			sp1feld=fieldbackup;
			printf("Sie koennen nicht Schiffe ueber andere Schiffe legen\n");
			i=i-1;
		}
		showSpielfeld(fieldsize,sp1feld->meinFeld);
	}
	printf("Schiffe Platzieren fuer %s\nSetzen der %d Uboot :\n",sp1->name,uboota);
	showSpielfeld(fieldsize,sp1feld->meinFeld);
	for(i=0;i<uboota;i++){
		printf("%d.Schiff setzen\nStartpunkt ? ",i+1);
		scanf("%s",p1);
		printf("Senkrecht(s)/Waagrecht(w)? ");
		scanf("%s",p2);
		c=*sp1feld;
		fieldbackup=&c;
		sp1feld=setSchiff(sp1feld,sp1uboot[i],p1,p2);
		if(sp1feld==NULL){
			sp1feld=fieldbackup;
			printf("Sie koennen nicht Schiffe ueber andere Schiffe legen\n");
			i=i-1;
		}
		showSpielfeld(fieldsize,sp1feld->meinFeld);
	}
	getchar();
	getchar();
	return 0;
}