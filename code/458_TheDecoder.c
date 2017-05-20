#include <stdio.h>

int main(int argc, char* argv){
	int c;
	while((c = getchar()) != EOF){
		if (c == '\n') printf("\n");
		else printf("%c",(char)(c-7));
	}
	return 0;
}
