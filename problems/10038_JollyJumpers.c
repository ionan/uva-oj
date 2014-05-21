#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv){
	int *diffs;
	int n,numb,prevnumb,i,z;
	while (scanf("%d",&n) != EOF){
		diffs = (int *)malloc(sizeof(int)*(n));
		for (i = 0; i < n; i++){
			diffs[i] = 0;
		}
		
		prevnumb = 0;
		bool jolly = TRUE;
		for (i = 0; i < n; i++){
			z = scanf(" %d",&numb);
			if (jolly && i > 0){
				int difference = abs(numb - prevnumb);
				if (jolly && difference > 0 && difference < n && diffs[difference-1] == 0){
					diffs[difference-1] = 1;
				} else {
					jolly = FALSE;
				}
			}
			prevnumb = numb;
		}
		
		if (jolly) printf("Jolly\n");
		else printf("Not jolly\n");
		
		free(diffs);
	}
}

int abs(int val){
	if (val < 0) return -val;
	return val;
}
