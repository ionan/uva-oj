#include <stdio.h>

/* Assign an index to every coordinate */
const short X_PLUS = 0;
const short X_MINUS = 1;
const short Y_PLUS = 2;
const short Y_MINUS = 3;
const short Z_PLUS = 4;
const short Z_MINUS = 5;
const short NO_BEND = -1;



long L;

short getCoordinateValue(char *arr){
	if (!strcmp(arr, "+x")) return X_PLUS;
	if (!strcmp(arr, "-x")) return X_MINUS;
	if (!strcmp(arr, "+y")) return Y_PLUS;
	if (!strcmp(arr, "-y")) return Y_MINUS;
	if (!strcmp(arr, "+z")) return Z_PLUS;
	if (!strcmp(arr, "-z")) return Z_MINUS;
	return NO_BEND;
}

int main(int argc, char *argv){
	/* 
		Define outcome for every possible combination 
		(y axis = current direction, x axis = bend direction) 
	*/
	int bendMatrix[6][6] = {
					/* x+ */	/* x- */	/* y+ */	/* y- */	/* z+ */	/* z- */
		/* x+ */	NO_BEND,	NO_BEND,	Y_PLUS,		Y_MINUS,	Z_PLUS,		Z_MINUS,
		/* x- */	NO_BEND,	NO_BEND,	Y_MINUS,	Y_PLUS,		Z_MINUS,	Z_PLUS, 
		/* y+ */	NO_BEND,	NO_BEND,	X_MINUS,	X_PLUS,		Y_PLUS,		Y_PLUS,
		/* y- */	NO_BEND,	NO_BEND,	X_PLUS,		X_MINUS,	Y_MINUS,	Y_MINUS,
		/* z+ */	NO_BEND,	NO_BEND,	Z_PLUS,		Z_PLUS,		X_MINUS,	X_PLUS,
		/* z- */	NO_BEND,	NO_BEND,	Z_MINUS,	Z_MINUS,	X_PLUS,		X_MINUS
	};

	int trash;
	while(1){
		trash = scanf("%ld\n",&L);
/* printf("Wire lenght is %ld\n", L); */
		if (L == 0) break;
		short currentDir = X_PLUS;
		char command[3];
		long i;
		for(i = 0; i < L - 1; i++) {
            trash = scanf("%s", command);
            short bendDir = getCoordinateValue(command);
/* printf("Bend dir for %s is %d\n", command, bendDir); */
            if (bendDir != NO_BEND){
            	currentDir = bendMatrix[currentDir][bendDir];
            }
        }
        if (currentDir == X_PLUS) printf("+x\n");
		if (currentDir == X_MINUS) printf("-x\n");
		if (currentDir == Y_PLUS) printf("+y\n");
		if (currentDir == Y_MINUS) printf("-y\n");
		if (currentDir == Z_PLUS) printf("+z\n");
		if (currentDir == Z_MINUS) printf("-z\n");
	}
	return 0;
}