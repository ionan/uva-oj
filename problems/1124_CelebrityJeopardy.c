#include <stdio.h>

int main(int argc, char* argv){
	int c;
	while((c = getchar()) != EOF){
		printf("%c",c);
	}
	return 0;
}
