#include <stdio.h>
#include <string.h>

int heights[100];

int maxValue(int v1, int v2);

int minValue(int v1, int v2);

int main(int argc, char* argv){
	int n, max, min, totalSum, i, trash, current, avg, moves, setNum = 0;
	trash = scanf("%d\n",&n);
	while(n != 0){
		setNum++;
		memset(heights,0,sizeof(heights));
		max = 0, min = 99, totalSum = 0;
		for (i = 0; i < n; i++){
			if (i == 0) trash = scanf("%d",&current);
			else trash = scanf(" %d",&current);
			totalSum += current;
			if (current < min) min = current;
			if (current > max) max = current;
			heights[current-1]++;
		}
		avg = totalSum / n;	
		moves = 0;
		for (i = maxValue(avg,min); i < minValue(max,99); i++){
			moves += heights[i] * (i+1-avg);
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",setNum,moves);
		trash = scanf("\n%d\n",&n);
	}
	return 0;
}

int maxValue(int v1, int v2){
	if (v1 > v2) return v1;
	return v2;
}

int minValue(int v1, int v2){
	if (v1 < v2) return v1;
	return v2;
}