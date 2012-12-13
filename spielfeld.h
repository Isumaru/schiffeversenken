#ifndef _SPIELFELD_H_
#define _SPIELFELD_H_
void createSpielfeld(int length,int **array);
struct array getPosition();
void schuss();
int **	start(int size);
int ** addSchiff(int **myArray,int schiffg,int schiffa);
void setSchiff(int x1,int y1,int x2,int y2);
struct array getSpielfeld();
#endif