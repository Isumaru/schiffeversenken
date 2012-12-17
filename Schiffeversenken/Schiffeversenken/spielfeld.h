#ifndef _SPIELFELD_H_
#define _SPIELFELD_H_
struct spielfeld{
	int **meinFeld;
	int **seinFeld;
	int size;
};
struct spielfeld* setSchiff(struct spielfeld*a,struct schiff*b,char start[2],char ws[1]);
struct spielfeld *makeSpielfeld(int size);
void showSpielfeld(int length,int **myArray);
#endif