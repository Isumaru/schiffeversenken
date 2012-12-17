#include "spielfeld.h"
#include <stdio.h>
#include <stdlib.h>
#include "schiff.h"
#include <string.h>
//struct spielfeld c;
//struct spielfeld *d;
const char alp[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int trifftSchuss(struct spielfeld*his,char schuss[2]){
	int xo,i,y=atoi(&schuss[1])-1;
	for(i=0;i<sizeof(alp);i++){
		if(alp[i]==schuss[0]){
			xo=i;
			i=sizeof(alp);
		}
	}
	//Uebrpruefen ob das Feld Wasser ist
	if(his->meinFeld[xo][y]==0)
		return 0;
	return 1;
}
struct spielfeld* shootSchiff(struct spielfeld*my,struct spielfeld*his,char schuss[2]){
	int xo,i,y=atoi(&schuss[1])-1;
	for(i=0;i<sizeof(alp);i++){
		if(alp[i]==schuss[0]){
			xo=i;
			i=sizeof(alp);
		}
	}
	if(trifftSchuss(his,schuss)==0){
		//my->seinFeld[xo][y]==x
	}
			return NULL;


}
struct spielfeld* setSchiff(struct spielfeld*a,struct schiff*b,char start[2],char ws[1]){
	int xo,i,y=atoi(&start[1])-1;
	//c=*a;
	//d=&c;
	for(i=0;i<sizeof(alp);i++){
		if(alp[i]==start[0]){
			xo=i;
			i=sizeof(alp);
		}
	}
	if(ws[0]=='w'){
		for(i=0;i<b->size;i++)
			if(a->meinFeld[xo][y+i]!=0)
				return NULL;	
		for(i=0;i<b->size;i++)
			a->meinFeld[xo][y+i]=b->ID;
	}
	if(ws[0]=='s'){
		for(i=0;i<b->size;i++)
			if(a->meinFeld[xo+i][y]!=0)
				return NULL;
		for(i=0;i<b->size;i++)
			a->meinFeld[xo+i][y]=b->ID;
	}
	return a;
}
int ** intialiseFeld(int size){
	//Code von Galileo Computing C von A bis Z
	int i,j;
	int ** matrix;
	/* Speicher reservieren für die int-Zeiger */
	 matrix = malloc(size * sizeof(int *));
	 if(NULL == matrix) {
		printf("Kein virtueller RAM mehr vorhanden ... !");
		return NULL;
	 }
	  /* jetzt noch Speicher reservieren für die einzelnen Spalten
	   * der i-ten Zeile */
	  for(i = 0; i < size; i++) {
		 matrix[i] = malloc(size * sizeof(int));
         if(NULL == matrix[i]) {
            printf("Kein Speicher mehr fuer Zeile %d\n",i);
            return NULL;
         }
	  }
	  //Befüllen des Arrays mit 0en
	  for (i = 0; i <size; i++)
		for (j = 0; j <size; j++)
			matrix[i][j] = 0; 
	  return matrix;
}
struct spielfeld *makeSpielfeld(int size){
	int** meinFeld=intialiseFeld(size);
	int** seinFeld=intialiseFeld(size);
	struct spielfeld *myspielfeld;
	myspielfeld = malloc (sizeof(struct spielfeld));
	myspielfeld->meinFeld=meinFeld;
	myspielfeld->seinFeld=seinFeld;
	myspielfeld->size=size;
	return myspielfeld;
}

//Ausgabe des Spielfeldes in der Konsole
void showSpielfeld(int length,int **myArray){
	int i,z,x;
	//schleife für y achse 
	for(z=0;z<length+2;z++){
		//schleife für x achse
		for(i=0;i<length+1;i++){
			if(z==0&&i==0){
				printf(" ");
			}else{
				//Ausgabe der Zahlen der ersten Zeile die <=9 sind	
				if(z==0&&i==length&&i<=9)
					printf("| %d|",i);
				else
					//Ausgabe der Zahlen der ersten Zeile die >9 sind
					if(z==0&&i==length&&i>9)
						printf("|%d|",i);
					else{
						if(z==0&&i<=9)
							printf("| %d",i);	
						if(z==0&&i>9)
							printf("|%d",i);
					}
			}
			if(z>0&&z<length+1)
				//Ausgabe der Buchstaben Spalte
				if(i==0)
					printf("\n%c",alp[z-1]);
				else
					//Ausgabe der Felder des Arrays
					if(z<length+1&&i<length)
					printf("| %d",myArray[z-1][i-1]);
					else
						if((z<length+1&&i<length+1))
							printf("| %d|",myArray[z-1][i-1]);
			}
			//Ausgabe der untersten Zeile
			if(z==length+1){
					for(x=0;x<length+1;x++){
						if(x==0)
							printf("\n--");
						if(x>0&&x<length)
							printf("---");
					}

					printf("--'\n");
			}
	}
}

