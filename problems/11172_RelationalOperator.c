#include <stdio.h>

int main(int argc, char *argv){
	int test_cases,r,i;
	unsigned long a,b;
	while(scanf("%d\n",&test_cases) != EOF){
		for (i = 0; i < test_cases; i++){
			r = scanf("%lu %lu\n",&a,&b);
			if (a > b) printf(">\n");
			else if (a < b) printf("<\n");
			else printf("=\n");
		}
	}
	return 0;
}
