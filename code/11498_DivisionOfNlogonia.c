#include <stdio.h>

int main(int argc, char *argv){
	int test_cases, n, m, r, x, y, i;
	while(scanf("%d\n",&test_cases) != EOF && test_cases > 0){
		r = scanf("%d %d\n",&n,&m);
		for (i = 0; i < test_cases; i++){
			r = scanf("%d %d\n",&x, &y);
			if (x == n || y == m) printf("divisa\n");
			else if (x < n){
				if (y < m) printf("SO\n");
				else  printf("NO\n");
			} else {
				if (y < m) printf("SE\n");
				else  printf("NE\n");
			}
		}
	}
	return 0;
}