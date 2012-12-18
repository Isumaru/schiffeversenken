#include "spielfeld.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clearScreen.h"
#include "schiff.h"
#include "spieler.h"
#include <ctype.h>
int main(){
	//Deklaration der benötigten Variablen
	char p1[2],p2[1],input[2],sp1name[20],sp2name[20];
	struct spieler *sp1,*sp2,*sp3;
	struct spielfeld c;
	struct spielfeld *sp1feld,*sp2feld,*sp3feld,*fieldbackup;
	struct schiff **sp1schlacht,**sp2schlacht,**sp1kreuzer,**sp2kreuzer,**sp1zerstoerer,**sp2zerstoerer,**sp1uboot,**sp2uboot;
	struct schiff **sp3schlacht,**sp3kreuzer,**sp3zerstoerer,**sp3uboot;
	int input2,game=1,zaehler=1,z,id,i,fieldsize,run=1,run2,run3,schlachta,schlachtg,kreuzera,kreuzerg,zerstoerera,zerstoererg,ubootg,uboota;
	// "GUI" 
	while(game==1){
	printf("1. Spiel starten -> 1 eintippen\n2. Highscore anzeigen -> 2 eintippen \n3. Programm beenden  -> 3 eintippen\n");
	while(run==1){
	while(scanf("%d",&input2)!=1){
		while (getchar() != '\n');
	}
	if(input2==1)
		run=0;	
	if(input2==2);
	if(input2==3)
		return 0;
	}
	run=1,run2=1,run3=1;
	//Abfrage wie sp1/2 heißen + erzeugen 
 	printf("\t\tSchiffeversenken\n\n");
	printf("Spieler 1 geben Sie Ihren Namen ein: ");
	scanf("%s",sp1name);
	sp1=makeSpieler(sp1name,0,0);
	printf("Spieler 2 geben Sie Ihren Namen ein: ");
	scanf("%s",sp2name);
	sp2=makeSpieler(sp2name,0,0);
	//Abfrage der Feldgroeße , erzeugen des Felds
	while(run==1){
	printf("Wie gross wollen Sie ihr Feld haben?\nMinimum : 5 , Maximum 26\n");
	while(scanf("%d",&fieldsize)!=1){
		while (getchar() != '\n');
	}
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
	//Abfrage der Schiffsgroeßen und Anzahl , erzeugen der schiffe
	printf("Vergfuegbare Schiffe:\n\tSchlachtschiff\n\tKreuzer\n\tZerstoerer\n\tU-Boote\n");
	printf("\nAnzahl der Schlachtschiffe :");
	while(scanf("%d",&schlachta)!=1||schlachta<1){
		while (getchar() != '\n');
	}
	sp1schlacht= malloc(schlachta * sizeof(int *));
	sp2schlacht= malloc(schlachta * sizeof(int *));
	printf("Groesse der Schlachtschiffe?: ");
	while(scanf("%d",&schlachtg)!=1||schlachtg<1){
		while (getchar() != '\n');
	}
	for(i=0;i<schlachta;i++){
		sp1schlacht[i]=makeSchiff(schlachtg,schlachtg);
		sp2schlacht[i]=makeSchiff(schlachtg,schlachtg);
		zaehler = zaehler+i;
		sp1schlacht[i]->ID=zaehler;
		sp2schlacht[i]->ID=zaehler;
		
	}
	zaehler+=1;
	//Abfrage der Schiffsgroeßen und Anzahl , erzeugen der schiffe setzen der ID
	printf("Anzahl der Kreuzer: ");
	while(scanf("%d",&kreuzera)!=1||kreuzera==0){
		while (getchar() != '\n');
	}
	sp1kreuzer= malloc(kreuzera * sizeof(int *));
	sp2kreuzer= malloc(kreuzera * sizeof(int *));
	printf("Groesse der Kreuzer?: ");
	while(scanf("%d",&kreuzerg)!=1||kreuzerg==0){
		while (getchar() != '\n');
	}
	for(i=0;i<kreuzera;i++){
		sp1kreuzer[i]=makeSchiff(kreuzerg,kreuzerg);
		sp2kreuzer[i]=makeSchiff(kreuzerg,kreuzerg);
		zaehler = zaehler+i;
		sp1kreuzer[i]->ID=zaehler;
		sp2kreuzer[i]->ID=zaehler;
	}
	zaehler+=1;
	//Abfrage der Schiffsgroeßen und Anzahl , erzeugen der schiffe setzen der ID
	printf("Anzahl der Zerstoerer: ");
	while(scanf("%d",&zerstoerera)!=1||zerstoerera<1){
		while (getchar() != '\n');
	}
	sp1zerstoerer= malloc(zerstoerera * sizeof(int *));
	sp2zerstoerer= malloc(zerstoerera * sizeof(int *));
	printf("Groesse der Zerstoerer?: ");
	while(scanf("%d",&zerstoererg)!=1||zerstoererg<1){
		while (getchar() != '\n');
	}
	for(i=0;i<zerstoerera;i++){
		sp1zerstoerer[i]=makeSchiff(zerstoererg,zerstoererg);
		sp2zerstoerer[i]=makeSchiff(zerstoererg,zerstoererg);
		zaehler = zaehler+i;
		sp1zerstoerer[i]->ID=zaehler;
		sp2zerstoerer[i]->ID=zaehler;
	}
	zaehler+=1;
	//Abfrage der Schiffsgroeßen und Anzahl , erzeugen der schiffe setzen der ID
	printf("Anzahl der U-Boote: ");
	while(scanf("%d",&uboota)!=1||uboota<1){
		while (getchar() != '\n');
	}
	sp1uboot= malloc(uboota * sizeof(int *));
	sp2uboot= malloc(uboota * sizeof(int *));
	printf("Groesse der U-Boote?: ");
	while(scanf("%d",&ubootg)!=1||ubootg<1){
		while (getchar() != '\n');
	}
	for(i=0;i<uboota;i++){
		sp1uboot[i]=makeSchiff(ubootg,ubootg);
		sp2uboot[i]=makeSchiff(ubootg,ubootg);
		zaehler = zaehler+i;
		sp1uboot[i]->ID=zaehler;
		sp2uboot[i]->ID=zaehler;
	}
	CLEAR;
	//Schleife für das Setzen der Schiffe für sp1/2
	for(z=0;z<2;z++){
		if(z==0){
			sp3=sp1;
			sp3feld=sp1feld;
			sp3schlacht=sp1schlacht;
			sp3kreuzer=sp1kreuzer;
			sp3zerstoerer=sp1zerstoerer;
			sp3uboot=sp1uboot;
		}else{
			sp3=sp2;
			sp3feld=sp2feld;
			sp3schlacht=sp2schlacht;
			sp3kreuzer=sp2kreuzer;
			sp3zerstoerer=sp2zerstoerer;
			sp3uboot=sp2uboot;
		}	
	printf("Schiffe Platzieren fuer %s \nBsp. Eingabe :\n\tStartpunkt? A5\n\tSenkrecht(s)/Waagrecht(w)? w \n\nSetzen der %d Schlachtschiffe:\n",sp3->name,schlachta);
	showSpielfeld(fieldsize,sp3feld->meinFeld);
	//Abfragen der Koordinaten
	for(i=0;i<schlachta;i++){
		printf("%d.Schiff setzen\nStartpunkt ? ",i+1);
		scanf("%s",p1);
		while(isalpha(p1[0])==0||isalpha(p1[1])!=0){
			scanf("%s",p1);
		}
		printf("Senkrecht(s)/Waagrecht(w)? ");
		scanf("%s",p2);
		c=*sp3feld;
		fieldbackup=&c;
		sp3feld=setSchiff(sp3feld,sp3schlacht[i],p1,p2);
		//Ueberpruefen ob Koordinaten außerhalb des Feldes bzw auf andern Schiff liegt
		if(sp3feld==NULL){
			sp3feld=fieldbackup;
			printf("Schiffe koennen nicht uebereinander liegen bzw außerhalb des Spielfeldes \n");
			i=i-1;
		}
		showSpielfeld(fieldsize,sp3feld->meinFeld);
	}
	//Abfragen der Koordinaten
	printf("Schiffe Platzieren fuer %s\nSetzen der %d Kreuzer :\n",sp3->name,kreuzera);
	showSpielfeld(fieldsize,sp3feld->meinFeld);
	for(i=0;i<kreuzera;i++){
		printf("%d.Schiff setzen\nStartpunkt ? ",i+1);
		scanf("%s",p1);
		while(isalpha(p1[0])==0||isalpha(p1[1])!=0){
			scanf("%s",p1);
		}
		printf("Senkrecht(s)/Waagrecht(w)? ");
		scanf("%s",p2);
		c=*sp3feld;
		fieldbackup=&c;
		sp3feld=setSchiff(sp3feld,sp3kreuzer[i],p1,p2);
		//Ueberpruefen ob Koordinaten außerhalb des Feldes bzw auf andern Schiff liegt
		if(sp3feld==NULL){
			sp3feld=fieldbackup;
			printf("Sie koennen nicht Schiffe ueber andere Schiffe legen\n");
			i=i-1;
		}
		showSpielfeld(fieldsize,sp3feld->meinFeld);
	}
	//Abfragen der Koordinaten
	printf("Schiffe Platzieren fuer %s\nSetzen der %d Zerstoerer :\n",sp3->name,zerstoerera);
	showSpielfeld(fieldsize,sp3feld->meinFeld);
	for(i=0;i<zerstoerera;i++){
		printf("%d.Schiff setzen\nStartpunkt ? ",i+1);
		scanf("%s",p1);
		while(isalpha(p1[0])==0||isalpha(p1[1])!=0){
			scanf("%s",p1);
		}
		printf("Senkrecht(s)/Waagrecht(w)? ");
		scanf("%s",p2);
		c=*sp3feld;
		fieldbackup=&c;
		sp3feld=setSchiff(sp3feld,sp3zerstoerer[i],p1,p2);
		//Ueberpruefen ob Koordinaten außerhalb des Feldes bzw auf andern Schiff liegt
		if(sp3feld==NULL){
			sp3feld=fieldbackup;
			printf("Sie koennen nicht Schiffe ueber andere Schiffe legen\n");
			i=i-1;
		}
		showSpielfeld(fieldsize,sp3feld->meinFeld);
	}
	//Abfragen der Koordinaten
	printf("Schiffe Platzieren fuer %s\nSetzen der %d Uboot :\n",sp3->name,uboota);
	showSpielfeld(fieldsize,sp3feld->meinFeld);
	for(i=0;i<uboota;i++){
		printf("%d.Schiff setzen\nStartpunkt ? ",i+1);
		scanf("%s",p1);
		while(isalpha(p1[0])==0||isalpha(p1[1])!=0){
			scanf("%s",p1);
		}
		printf("Senkrecht(s)/Waagrecht(w)? ");
		scanf("%s",p2);
		c=*sp3feld;
		fieldbackup=&c;
		sp3feld=setSchiff(sp3feld,sp3uboot[i],p1,p2);
		//Ueberpruefen ob Koordinaten außerhalb des Feldes bzw auf andern Schiff liegt
		if(sp3feld==NULL){
			sp3feld=fieldbackup;
			printf("Sie koennen nicht Schiffe ueber andere Schiffe legen\n");
			i=i-1;
		}
		showSpielfeld(fieldsize,sp3feld->meinFeld);
	}
	CLEAR;
	}
	run=1;
	printf("DAS SPIEL BEGINNT\n");
	while(run==1){
		run2=1;
		run3=1;
		//Schleife für Spieler 1
		while(run2==1){
			printf("%s ist an der Reihe\n",sp1->name);
			showSpielfeld(fieldsize,sp1feld->seinFeld);
			//Abfrage der Schuss Koordinaten
			printf("Wo wollen Sie hinschiessen? Bsp A5\n");
			scanf("%s",p1);
			CLEAR;
			//Ueberpruefen ob ein Schiff getroffen wurde
			if(trifftSchuss(sp2feld,p1)==0){
				sp1->wTreffer+=1;
				printf("Sie haben leider nicht getroffen\n");
				run2=0;
			}else{
				sp1feld=shootSchiff(sp1feld,sp2feld,p1,sp2schlacht,sp2kreuzer,sp2uboot,sp2zerstoerer);
				if(sp1feld->a->life==0){
					printf("Sie haben das Schiff zerstoert\n");
					//Ueberpruefen ob alle Schiffe zerstoert sind
					if(checkWin(sp2schlacht,sp2kreuzer,sp2uboot,sp2zerstoerer)==1){
						CLEAR;
						printf("Glueckwunsch %s Sie haben Gewonnen !\n",sp2->name);
						sp1->gewonnen=1;
						sp2->verloren=1;
						run=0,run2=0,run3=0;
					}else printf("Sie duerfen erneut schiessen\n");
				}else{
					printf("Sie haben getroffen\n");
					printf("Sie duerfen erneut schiessen\n");
				}
				sp1->sTreffer+=1;
			}
	   }
		//Schleife für Spieler 2
		while(run3==1){
			CLEAR;
			printf("%s ist an der Reihe\n",sp2->name);
			showSpielfeld(fieldsize,sp2feld->seinFeld);
			//Abfrage der Schuss Koordinaten
			printf("Wo wollen Sie hinschiessen? Bsp A5\n");
			scanf("%s",p1);
			CLEAR;
			//Ueberpruefen ob ein Schiff getroffen wurde
			if((trifftSchuss(sp1feld,p1))==0){
				sp2->wTreffer+=1;
				printf("Sie haben leider nicht getroffen\n");
				run3=0;
			}else{
				sp2feld=shootSchiff(sp2feld,sp1feld,p1,sp1schlacht,sp1kreuzer,sp1uboot,sp1zerstoerer);
				if(sp2feld->a->life==0){
					printf("Sie haben das Schiff zerstört\n");
					//Ueberpruefen ob alle Schiffe zerstoert sind
					if(checkWin(sp1schlacht,sp1kreuzer,sp1uboot,sp1zerstoerer)==1){
						CLEAR;
						printf("Glueckwunsch %s Sie haben Gewonnen !\n",sp2->name);
						sp2->gewonnen=1;
						sp1->verloren=1;
						run=0,run2=0,run3=0;
					}
					else printf("Sie duerfen erneut schiessen\n");
				}
				else{
					printf("Sie haben getroffen\n");
					printf("Sie duerfen erneut schiessen\n");
				}
				sp2->sTreffer+=1;
			}
	   }
	}
	run=1;
	printf("1. Spielfelder anzeigen -> 1 eintippen\n2. Highscore anzeigen -> 2 eintippen \n3. Neues Spiel starten -> 3 eintippen\n4.Programm beenden -> 4 eintippen\n");
	while(run==1){
	printf("\n1,2,3 oder 4?\n");
	while(scanf("%d",&input2)!=1){
		while (getchar() != '\n');
	}
	if(input2==1){
		printf("\tSpielfeld von %s\n",sp1->name);
		showSpielfeld(fieldsize,sp1feld->meinFeld);
		printf("\tSpielfeld von %s\n",sp2->name);
		showSpielfeld(fieldsize,sp2feld->meinFeld);
	}
	if(input2==2);
	if(input2==3)
		run=0;
	
	if(input2==4)
		return 0;
	}
	}
	return 0;
}