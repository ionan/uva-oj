#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

int main(){
	int ch;
	bool open = false;
	while ((ch = getchar()) != EOF){
		if (ch == '"'){
			if (open){
				printf("''");
				open = false;
			} else {
				printf("``");
				open = true;
			}
		} else {
			printf("%c",ch);
		}
	}
	return 0;
}