#ifndef _SPIELER_H_
#define _SPIELER_H_
struct spieler{
	char name[20];
	int wTreffer;
	int sTreffer;
};
struct spieler* makeSpieler(char name[],int wTreffer,int sTreffer);
#endif