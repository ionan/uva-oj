#include <stdio.h>

char keyboard[4][13] = {
			{'`','1','2','3','4','5','6','7','8','9','0','-','='},
			{'Q','W','E','R','T','Y','U','I','O','P','[',']','\\'},
			{'A','S','D','F','G','H','J','K','L',';','\'','\0','\0'},
			{'Z','X','C','V','B','N','M',',','.','/','\0','\0','\0'}
		};

char find(char c);

int main(int argc, char const *argv[]){
	char c;
	while ((c = getchar()) != EOF){
		printf("%c",find(c));
	}
	return 0;
}

char find(char c){
	char ret = c;
	if (c != ' ' && c != '\n'){
		int i,j;
		for (i = 0; i < 4; i++){
			for (j = 1; j < 13; j++){
				if (keyboard[i][j] == c) {
					ret = keyboard[i][j-1];
					break;
				}
			}
		}
	}
	return ret;
}