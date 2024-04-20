#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

int getNthUglyNumber(int n);

int main(int argc, char* argv){
	printf("The 1500'th ugly number is %d.\n",getNthUglyNumber(1500));
	return 0;
}

int getNthUglyNumber(int n){
	int *uglyNumbers = (int *)malloc(sizeof(int)*n);
	int nthUglyNumber = 1;
	uglyNumbers[0] = 1;
	int mult2Ptr = 0, mult3Ptr = 0, mult5Ptr = 0;
	int lastSoFar = 0;
	while ( lastSoFar < n-1 ){
		while (uglyNumbers[mult2Ptr] * 2 <= uglyNumbers[lastSoFar]) mult2Ptr++;
        while (uglyNumbers[mult3Ptr] * 3 <= uglyNumbers[lastSoFar]) mult3Ptr++;
        while (uglyNumbers[mult5Ptr] * 5 <= uglyNumbers[lastSoFar]) mult5Ptr++;
		int next2 = uglyNumbers[mult2Ptr] * 2;
		int next3 = uglyNumbers[mult3Ptr] * 3;
		int next5 = uglyNumbers[mult5Ptr] * 5;
		if (next2 < next3 && next2 < next5 ) {
            uglyNumbers[++lastSoFar] = next2;
			mult2Ptr++;
        } else if (next3 < next5) {
			uglyNumbers[++lastSoFar] = next3;
			mult3Ptr++;
		} else {
			uglyNumbers[++lastSoFar] = next5;
			mult5Ptr++;
		}
	}
	nthUglyNumber = uglyNumbers[n-1];
	free(uglyNumbers);
	return nthUglyNumber;
}