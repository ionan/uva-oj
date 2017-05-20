#include <stdio.h>

typedef struct Proposal {
	char name[81];
	double price;
	int requirementsMet;
} Proposal;

void flushInput(int lines);

void readName(char* name);

int getBestIndex(Proposal* props, int current);

int main(int argc, char const *argv[]){
	int n, p, best = 0, currentIndex = 0, trash, j, rfp = 0;;
	Proposal proposals[2];
	while (scanf("%d %d\n",&n,&p) != EOF 
			&& (n != 0 || p != 0)){
		rfp++;
		if (rfp > 1) printf("\n");
		flushInput(n);
		best = 0;
		currentIndex = 0;
		for (j = 0; j < p; j++){
			readName(proposals[currentIndex].name);
			trash = scanf("%lf %d\n",
					&(proposals[currentIndex].price),
					&(proposals[currentIndex].requirementsMet));
			flushInput(proposals[currentIndex].requirementsMet);
			if (j > 0){
				best = getBestIndex(&(proposals[0]),best);
			}
			currentIndex = best == 0 ? 1 : 0;
		}
		printf("RFP #%d\n",rfp);
		j = 0;
		while (proposals[best].name[j] != '\0') {
			printf("%c",proposals[best].name[j]);
			j++;
		}
		printf("\n");
	}
	return 0;
}

void flushInput(int lines){
	int soFar = 0;
	char c;
	while (soFar < lines){
		c = getchar();
		if (c == '\n') soFar++;
	}
}

void readName(char* name){
	int i = 0;
	char c;
	while ((c = getchar()) != '\n'){
		name[i++] = c;
	}
	name[i] = '\0';
}

int getBestIndex(Proposal* props, int current){
	int idx = current;

	if (props[0].requirementsMet > props[1].requirementsMet){
		idx = 0;
	} else if (props[1].requirementsMet > props[0].requirementsMet){
		idx = 1;
	} else {
		if (props[0].price < props[1].price){
			idx = 0;
		} else if (props[1].price < props[0].price){
			idx = 1;
		}
	}

	return idx;
}