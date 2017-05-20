#include <stdio.h>

int bin1[3], bin2[3], bin3[3];

#define BCG 0
#define BGC 1
#define CBG 2
#define CGB 3
#define GBC 4
#define GCB 5

#define BROWN 0
#define GREEN 1
#define CLEAR 2

int main(){
	int moves[6],min, disposition,i;
	while (readInput() > 0){
		moves[BCG] = bin1[GREEN] + bin1[CLEAR] + bin2[BROWN] + bin2[GREEN] + bin3[BROWN] + bin3[CLEAR];
        moves[BGC] = bin1[GREEN] + bin1[CLEAR] + bin2[BROWN] + bin2[CLEAR] + bin3[BROWN] + bin3[GREEN];
        moves[CBG] = bin1[BROWN] + bin1[GREEN] + bin2[GREEN] + bin2[CLEAR] + bin3[BROWN] + bin3[CLEAR];
        moves[CGB] = bin1[BROWN] + bin1[GREEN] + bin2[BROWN] + bin2[CLEAR] + bin3[GREEN] + bin3[CLEAR];
        moves[GBC] = bin1[BROWN] + bin1[CLEAR] + bin2[GREEN] + bin2[CLEAR] + bin3[BROWN] + bin3[GREEN];
        moves[GCB] = bin1[BROWN] + bin1[CLEAR] + bin2[BROWN] + bin2[GREEN] + bin3[GREEN] + bin3[CLEAR];
        
        min = moves[BCG];
        disposition = BCG;
        for (i = 1; i < 6;i++){
            if (moves[i] < min) {
            	min = moves[i]; 
            	disposition = i;
            }
        }
        
        printResult(disposition,min);
	}
	return 0;
}

int printResult(int best, int min){
	switch (best){
        case 0:
            printf("BCG %d\n",min);
            break;
        case 1:
            printf("BGC %d\n",min);
            break;
        case 2:
            printf("CBG %d\n",min);
            break;
        case 3:
            printf("CGB %d\n",min);
            break;
        case 4:
            printf("GBC %d\n",min);
            break;
        default:
            printf("GCB %d\n",min);
            break;
	}
	return 0;
}

int readInput(){
	if(scanf("%d %d %d %d %d %d %d %d %d\n",&bin1[BROWN],&bin1[GREEN],&bin1[CLEAR],&bin2[BROWN],&bin2[GREEN],&bin2[CLEAR],&bin3[BROWN],&bin3[GREEN],&bin3[CLEAR]) != EOF) return 1;
	else return 0;
}
