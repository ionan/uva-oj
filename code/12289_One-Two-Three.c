#include <stdio.h>
#include <string.h>

char word[10];

int main(int argc, char *argv){
	int test_cases, i, r, one, two;
	r = scanf("%d\n",&test_cases);
	for (i = 0; i < test_cases; i++){
		r = scanf("%s",word);
		if (strlen(word) > 3){
			printf("3\n");
		} else {
			one = word[0] == 'o' ? 1 : 0;
			two = word[0] == 't' ? 1 : 0;
			one += word[1] == 'n' ? 1 : 0;
			two += word[1] == 'w' ? 1 : 0;
			one += word[2] == 'e' ? 1 : 0;
			two += word[2] == 'o' ? 1 : 0;
			if (one > two) printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}