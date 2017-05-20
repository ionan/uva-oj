#include <stdio.h>

int main(int argc, char *argv){
	int test_cases, i, r, width, length, height;
	r = scanf("%d\n",&test_cases);
	for (i = 0; i < test_cases; i++){
		r = scanf("%d %d %d\n",&length, &width, &height);
		if (length > 20 || width > 20 || height > 20) printf("Case %d: bad\n", (i+1));
		else printf("Case %d: good\n", (i+1));
	}
	return 0;
}