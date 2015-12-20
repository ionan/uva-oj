#include <stdio.h>
#include <string.h>

#define MAX_N 15

int magicSquare[MAX_N][MAX_N];

void getNextCoord(int *col,int *row, int n){
	int c,r;
	c = (*col == n-1) ? 0 : *col + 1;
	r = (*row == 0) ? n-1 : *row - 1;
	if (magicSquare[r][c] > 0){
		c = *col;
		r = (*row == n-1) ? 0 : *row + 1;
		if (magicSquare[r][c] > 0){
			c = -1;
			r = -1;
		}
	}
	*col = c;
	*row = r;
}

int getSizeInChars(int n){
	int size = 1;
	while (n / 10 > 0){
		n = n % 10;
		size++;
	}
	return size;
}

void printMagicSquare(int n, int sum){
	printf("n=%d, sum=%d\n",n,sum);
	int i,j, k, maxSize = getSizeInChars(n*n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			int currSize = getSizeInChars(magicSquare[i][j]);
			for (k = 0; k < maxSize + 1 - currSize; k++) printf(" ");
			printf("%d",magicSquare[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv){
	int n, val, sum;
	int trash = scanf("%d\n",&n);
	int count = 0;
	while (trash > 0){
		if (count > 0){
			printf("\n");
		}
		memset(magicSquare, 0, sizeof(magicSquare));
		val = 1;
		sum = 1;
		int col = (n/2), row = 0;
		magicSquare[row][col] = val++;
		getNextCoord(&col,&row,n);
		while (col >= 0){
			magicSquare[row][col] = val++;
			if (row == 0) sum += magicSquare[row][col];
			getNextCoord(&col,&row,n);
		}
		printMagicSquare(n,sum);
		trash = scanf("%d\n",&n);
		count++;
	}
	return 0;
}