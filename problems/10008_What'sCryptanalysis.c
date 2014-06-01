#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct CharAndFreq {
	char c;
	int freq;
} CharAndFreq;

CharAndFreq freqs[26];

int cmp(const void * a, const void * b);

int main(int argc, char const *argv[]){
	int trash, testCases, i, upper;
	char c;

	for (i = 0; i < 27; i++){
		freqs[i].c = (char)(i+65);
		freqs[i].freq = 0;
	}

	trash = scanf("%d\n",&testCases);
	for (i = 0; i < testCases; i++){
		while ((c = getchar()) != '\n' && c != EOF){
			upper = toupper((int)c);
			if (upper < 91 && upper > 64){
				freqs[upper - 65].freq++;
			}
		}
	}

	qsort(freqs, 26, sizeof(CharAndFreq), cmp);

	for (i = 0; i < 27; i++){
		if (freqs[i].freq > 0) printf("%c %d\n",freqs[i].c,freqs[i].freq);
	}

	return 0;
}

int cmp(const void * a, const void * b){
   return ( ((CharAndFreq*)b)->freq - ((CharAndFreq*)a)->freq );
}