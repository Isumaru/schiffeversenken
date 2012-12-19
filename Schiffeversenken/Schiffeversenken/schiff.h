#ifndef _SCHIFF_H_
#define _SCHIFF_H_
struct schiff{
	int ID;
	int size;		
	int life;
	int anzahl;
};
struct schiff* makeSchiff(int size,int life);
#endif