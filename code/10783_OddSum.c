#include <stdio.h>

int naiveSum(int l, int u);

int main(int argc, char* argv){
	int testCases, trash, i, lowerBound, upperBound, j, sum;
	trash = scanf("%d\n",&testCases);
	for (i = 0; i < testCases; i++){
		trash = scanf("%d\n%d\n",&lowerBound,&upperBound);
		if (lowerBound % 2 == 0) lowerBound++;
		if (upperBound % 2 == 0) upperBound--;
		sum = naiveSum(lowerBound,upperBound);
		printf("Case %d: %d\n",(i+1),sum);
	}
	return 0;
}

int naiveSum(int l, int u){
	int sum = l, j;
	for (j = l + 2; j <= u; j = j+2) sum+= j;
	return sum;
}