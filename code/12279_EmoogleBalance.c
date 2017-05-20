#include <stdio.h>

int main(int argc, char *argv){
	int events, r, i, ncase = 1, curr, sum;
	while(scanf("%d\n",&events) != EOF && events > 0){
		r = scanf("%d",&curr);
		sum = curr == 0 ? -1 : 1;
		for (i = 1; i < events; i++){
			r = scanf(" %d",&curr);
			curr == 0 ? sum-- : sum++;
		}
		r = scanf("\n");
		printf("Case %d: %d\n",ncase,sum);
		ncase++;
	}
	return 0;
}