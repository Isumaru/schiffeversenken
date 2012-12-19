#ifndef _SPIELFELD_H_
#define _SPIELFELD_H_
struct spielfeld{
	int **meinFeld;
	int **seinFeld;
	int size;
	struct schiff* a;
};
struct spielfeld* deleteSchiff(int size,struct spielfeld*my,char pos[2],struct schiff**a,struct schiff**b,struct schiff**c,struct schiff**d);
int checkWin(struct schiff**a,struct schiff**b,struct schiff**c,struct schiff**d);
struct spielfeld* shootSchiff(struct spielfeld*my,struct spielfeld*his,char schuss[2],struct schiff**a,struct schiff**b,struct schiff**c,struct schiff**d);
int trifftSchuss(struct spielfeld*his,char schuss[2]);
struct spielfeld* setSchiff(struct spielfeld*a,struct schiff*b,char start[2],char ws[1]);
struct spielfeld *makeSpielfeld(int size);
void testMe(struct schiff**a);
void showSpielfeld(int length,int **myArray);
#endif