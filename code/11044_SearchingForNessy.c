#include <stdio.h>

int main(int argc, char *argv){
	int test_cases,x,y,r, i;
	while(scanf("%d\n",&test_cases) != EOF){
		for (i = 0; i < test_cases; i++){
			r = scanf("%d %d\n",&x,&y);
			r = (x/3)*(y/3);
			printf("%d\n",r);
		}
	}
	return 0;
}