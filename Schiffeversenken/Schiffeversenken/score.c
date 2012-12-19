#include <stdio.h>
#include <conio.h>

void addScore(char name[20], int wtreffer, int strever,int gewonnen,int verloren){
	double verhelt=0.0;

	FILE*score;
	score=fopen("hallo.txt", "a");
	verhelt=(double)(wtreffer+strever)/100*strever;
	fprintf(score, "%s %i %i %.2lf \n",name,gewonnen,verloren,verhelt);
	fclose(score);


}


void showScore(){
	char ausgabe[80];
	FILE*score;
	score=fopen("hallo.txt","r");
	while(fgets(ausgabe,80,score)!= NULL){
		printf("%s\n",ausgabe);
	}
}