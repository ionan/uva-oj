#include <stdio.h>

unsigned long facts[21];

unsigned long initFacts();

int comparator(const void* e1, const void* e2);

char getNthCharacter(char* chars, int n, int size);

int main(int argc, char* argv){
	initFacts();
	
	int numberOfSamples;
	unsigned long permIndex, index, left;
	int i,j,k,trash = scanf("%d\n",&numberOfSamples);
	char cList[21];
	char c;
	for (i = 0; i < numberOfSamples; i++){
		j = 0;
		c = getchar();
		while(isalpha(c)){
			cList[j++] = c;
			c = getchar();
		}
		cList[j] = '\0';
		qsort(cList, j, sizeof(char), comparator);
		trash = scanf("%lu\n",&permIndex);
		left = permIndex;
		for (k = j; (k > 0 && left > 0); k--){
			index = left / facts[k-1];
			printf("%c",getNthCharacter(cList,index,j));
			left = left % facts[k-1];
		}
		while (k > 0){
			printf("%c",getNthCharacter(cList,0,j));
			k--;
		}
		printf("\n");
	}
}

char getNthCharacter(char* chars, int n, int size){
	char nth = chars[n];
	while(nth == '\0' && n < size){
		nth = chars[++n];
	}
	chars[n] = '\0';
	return nth;
}

unsigned long initFacts(){
	facts[0] = 1;
	facts[1] = 1;
	int i;
	for (i = 2; i < 21; i++){
		facts[i] = i*facts[i-1];
	}
}

int comparator(const void* e1, const void* e2) {
   char c1 = *(char*)e1;
   char c2 = *(char*)e2;
   return c1 - c2;
}