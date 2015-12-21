#include <stdio.h>

void flushNChars(int n){
	int i, r;
	char c;
	for (i = 0; i < n; i++) r = scanf("%c",&c);
}

int main(int argc, char *argv){
	int test_cases, i, r, total = 0, current;
	char c;
	r = scanf("%d\n",&test_cases);
	for (i = 0; i < test_cases; i++){
		r = scanf("%c",&c);
		if (c == 'd') {
			flushNChars(6);
			r = scanf("%d\n",&current);
			total += current;
		} else {
			flushNChars(6);
			printf("%d\n", total);
		}
	}
	return 0;
}