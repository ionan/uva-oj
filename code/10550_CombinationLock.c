#include <stdio.h>

#define bool int
#define TRUE 1
#define FALSE 0

int main(int argc, char *arg){
	int pos, comb1, comb2, comb3;
	while (scanf("%d %d %d %d\n",&pos,&comb1,&comb2,&comb3) != EOF){
		if (finish(pos,comb2,comb3)) break;
		int totalDegrees = 360*3;
		int posD = getDegrees(pos);
		int comb1D = getDegrees(comb1);
		int comb2D = getDegrees(comb2);
		int comb3D = getDegrees(comb3);
		totalDegrees += getDifference(posD,comb1D,TRUE);
		totalDegrees += getDifference(comb1D,comb2D,FALSE);
		totalDegrees += getDifference(comb2D,comb3D,TRUE);
		printf("%d\n",totalDegrees);
	}
	return 0;
}

int getDegrees(int number){
	return (360 - number * 9) % 360;
}

int getDifference(int start, int end, bool clockwise){
	if (clockwise){
		if (start > end) return 360 - start + end;
		else return end - start;
	} else {
		return getDifference(end, start, TRUE);
	}
}

bool finish(int a, int b, int c, int d){
	return (a == 0) && (b == 0) && (c == 0) && (d == 0);
}
