#include <stdio.h>

int main(int argc, char* argv){
	int a,b;
	while (scanf("%d %d\n",&a,&b) != EOF){
		printf("%d\n",(2*a*b));
	}
	return 0;
}
