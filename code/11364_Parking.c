#include <stdio.h>

int main(int argc, char *argv){
	int test_cases,shops,max, min, i, j, r, temp;
	while(scanf("%d\n",&test_cases) != EOF){
		for (i = 0; i < test_cases; i++){
			r = scanf("%d\n",&shops);
			r = scanf("%d",&max);
			min = max;
			for (j = 1; j < shops; j++) {
				r = scanf("%d",&temp);
				if (temp < min) min = temp;
				if (temp > max) max = temp;
			}
			r = (max-min)*2;
			printf("%d\n",r);
		}
	}
	return 0;
}