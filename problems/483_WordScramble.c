#include <stdio.h>
#include <stdlib.h>

void reverseWord(char* word, int length){
	int i;
	for (i = length - 1; i >= 0; i--){
		printf("%c",word[i]);	
	}
}

int main(int argc, char *argv){
	char* word = (char *)malloc(sizeof(char)*50);
	char c;
	int allocated = 50;
	int currentPos = 0;
	while ((c = getchar()) != EOF){
		if (c == ' '){
			reverseWord(word,currentPos);
			currentPos = 0;
			printf(" ");
		} else if (c == '\n'){
			reverseWord(word,currentPos);
			currentPos = 0;
			printf("\n");
		} else {
			if (currentPos == allocated){
				word = realloc(word,allocated+50);
				allocated += 50;
			}
			word[currentPos] = c;
			currentPos++;
		}
	}
	return 0;
}
