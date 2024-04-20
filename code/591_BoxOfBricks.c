#include <stdio.h>
#include <string.h>

int stacks[50];

int main(int argc, char* argv){
	int n, sum, setNum = 0, avg, i, moves, trash;
	trash = scanf("%d\n",&n);
	while(n != 0){
		setNum++;
		memset(stacks,0,sizeof(stacks));
		sum = 0;
		for (i = 0; i < n; i++){
			if (i == 0) trash = scanf("%d",&stacks[i]);
			else trash = scanf(" %d",&stacks[i]);
			sum += stacks[i];
		}
		avg = sum / n;	
		moves = 0;
		for (i = 0; i < n; i++){
			if (stacks[i] > avg)
			moves += stacks[i] - avg;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",setNum,moves);
		trash = scanf("\n%d\n",&n);
	}
	return 0;
}