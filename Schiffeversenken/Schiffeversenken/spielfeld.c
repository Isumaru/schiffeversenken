#include "spielfeld.h"
#include <stdio.h>
#include <stdlib.h>
#include "schiff.h"
#include <string.h>
#include <ctype.h>
const char alp[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int trifftSchuss(struct spielfeld*his,char schuss[2]){
	int xo,i,y=atoi(&schuss[1])-1;
	for(i=0;i<sizeof(alp);i++){
		if(alp[i]==toupper(schuss[0])){
			xo=i;
			i=sizeof(alp);
		}
	}
	//Uebrpruefen ob das Feld Wasser ist
	if(his->meinFeld[xo][y]==0)
		return 0;
	return 1;
}
int checkWin(struct schiff**a,struct schiff**b,struct schiff**c,struct schiff**d){
	int i,a1,b1,c1,d1;
	a1=a[0]->size;
	b1=b[0]->size;
	c1=c[0]->size;
	d1=d[0]->size;

	for(i=0;i<a1;i++)
		if(a[i]->life!=0)
			return 0;
	for(i=0;i<b1;i++)
		if(b[i]->life!=0)
			return 0;
	for(i=0;i<c1;i++)
		if(c[i]->life!=0)
			return 0;
	for(i=0;i<d1;i++)
		if(d[i]->life!=0)
			return 0;
	return 1;
}
struct spielfeld* shootSchiff(struct spielfeld*my,struct spielfeld*his,char schuss[2],struct schiff**a,struct schiff**b,struct schiff**c,struct schiff**d){
	struct schiff* e;
	int a1,b1,c1,d1,p,xo,i,y=atoi(&schuss[1])-1;
	a1=a[0]->size;
	b1=b[0]->size;
	c1=c[0]->size;
	d1=d[0]->size;
	for(i=0;i<sizeof(alp);i++){
		if(alp[i]==schuss[0]){
			xo=i;
			i=sizeof(alp);
		}
	}
	if(trifftSchuss(his,schuss)==0){
		return NULL;
	}
	p=his->meinFeld[xo][y];
	//Ueberpruefen ob ein Schiff getroffen wurde
	for(i=0;i<a1;i++)
		if(p==a[i]->ID){
			e=a[i];
			i=a1;
		}
	else for(i=0;i<b1;i++)
		if(p==b[i]->ID){
			e=b[i];
			i=b1;
		}
	else for(i=0;i<c1;i++)
		if(p==c[i]->ID){
			e=c[i];
			i=c1;
		}
	else for(i=0;i<d1;i++)
		if(p==d[i]->ID){
			e=d[i];
			i=d1;
		}
	e->life-=1;

	my->a=e;
	my->seinFeld[xo][y]=1;
	return my;
}
struct spielfeld* setSchiff(struct spielfeld*a,struct schiff*b,char start[2],char ws[1]){
	int xo,i,y=atoi(&start[1])-1;
	//c=*a;
	//d=&c;
	for(i=0;i<sizeof(alp);i++){
		if(alp[i]==toupper(start[0])){
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
	//Code Teils von Galileo Computing C von A bis Z
	int i,j;
	int ** matrix;
	/* Speicher reservieren für die int-Zeiger */
	 matrix = malloc(size * sizeof(int *));
	 if(NULL == matrix) {
		 printf("Falsche Eingabe\n");
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
						if(myArray[z-1][i-1]>0)
							printf("| %d",1);
						else
							printf("| %d",0);
					else
						if((z<length+1&&i<length+1))
							if(myArray[z-1][i-1]>0)
								printf("| %d|",1);
							else
								printf("| %d|",0);
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