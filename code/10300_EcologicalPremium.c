#include <stdio.h>

int main(int argc, char *argv){
	int test_cases, farmers,i,j,r;
	unsigned long size,animals,friendliness,sum;
	while(scanf("%d\n",&test_cases) != EOF){
		for (i = 0; i < test_cases; i++){
			r = scanf("%d\n",&farmers);
			sum = 0;
			for (j = 0; j < farmers; j++){
				r = scanf("%lu %lu %lu\n",&size,&animals,&friendliness);
				sum += size * friendliness;
			}
			printf("%lu\n",sum);
		}
	}
	return 0;
}
