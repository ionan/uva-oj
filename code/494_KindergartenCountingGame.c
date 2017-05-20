#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main(int argc, char* argv){
	int c, wordsSoFar = 0;
	int prevHadChar = false;
	while((c = getchar()) != EOF){
		if (isalpha(c)){
			prevHadChar = true;
		} else {
			if (prevHadChar) wordsSoFar++;
			prevHadChar = false;
			if (c == '\n'){
				printf("%d\n",wordsSoFar);
				wordsSoFar = 0;
			}
		}
	}
	return 0;
}
