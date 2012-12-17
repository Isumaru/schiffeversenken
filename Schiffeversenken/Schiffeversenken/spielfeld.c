#include "spielfeld.h"
#include <stdio.h>
#include <stdlib.h>

//Deklaration
void setTreffer(int x,int y);
int ** letsMalloc(int size){
	int i,j;
	int ** matrix;
	/* Speicher reservieren f�r die int-Zeiger (=zeile) */
	 matrix = malloc(size * sizeof(int *));
	 if(NULL == matrix) {
		printf("Kein virtueller RAM mehr vorhanden ... !");
		return NULL;
	 }
	  /* jetzt noch Speicher reservieren f�r die einzelnen Spalten
	   * der i-ten Zeile */
	  for(i = 0; i < size; i++) {
		 matrix[i] = malloc(size * sizeof(int));
         if(NULL == matrix[i]) {
            printf("Kein Speicher mehr fuer Zeile %d\n",i);
            return NULL;
         }
	  }
	  //Bef�llen des Arrays mit 0en
	  for (i = 0; i <size; i++)
		for (j = 0; j <size; j++)
			matrix[i][j] = 0; 
	  return matrix;
}
const char alp[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int getZufall(){
	return (rand() % 100 + 1);
}
int ** start(int size){
	int** myArray=letsMalloc(size);
	return myArray; 
}
int ** addSchiff(int **myArray,int schiffg,int schiffa){
	char a[2];
	char e[2];
		
							
		        
}
void createSpielfeld(int length,int **myArray){
	int i,z,x;
	//schleife f�r y achse 
	for(z=0;z<length+2;z++){
		//schleife f�r x achse
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
						if(z==0&&i<9)
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
					if(z<length+1&&i<length-1)
					printf("| %d",myArray[z-1][i-1]);
					else
						if(z<length+1&&i<length)
							printf("| %d|",myArray[z-1][i-1]);
			}
			//Ausgabe der untersten Zeile
			if(z==length+1){
					for(x=0;x<length+1;x++){
						if(x==0)
							printf("\n--");
						if(x>0&&x<length-1)
							printf("---");
					}
					if(length<9)
						printf("---");
					printf("--'\n");
			}
	}
}
