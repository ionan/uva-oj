#include <stdio.h>

int main(int argc, char *argv){
	int test_cases,r, i;
	long number;
	while(scanf("%d\n",&test_cases) != EOF){
		for (i = 0; i < test_cases; i++){
			r = scanf("%ld\n",&number);
			number = (number * 63 + 7492) * 5 - 498;
			number = (number / 10) % 10;
			number = number < 0 ? number * -1 : number;
			printf("%ld\n",number);
		}
	}
	return 0;
}