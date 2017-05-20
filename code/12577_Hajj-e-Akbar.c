#include <stdio.h>
#include <string.h>

char word[20];

int main(int argc, char *argv){
	int i = 1, r;
	while (1){
		r = scanf("%s\n",word);
		if (strcmp(word,"*") == 0) break;
		else if (strcmp(word,"Hajj") == 0) printf("Case %d: Hajj-e-Akbar\n",(i++));
		else printf("Case %d: Hajj-e-Asghar\n",(i++));
	}
	return 0;
}