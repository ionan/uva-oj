#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

typedef struct ArrayDimension {
	unsigned long lowerBound;
	unsigned long upperBound;
} ArrayDimension;

typedef struct Array {
	char name[10];
	unsigned long baseAddress;
	unsigned long size;
	int dimensionCount;
	ArrayDimension * dimensions;
} Array;

typedef int (*compfn)(const void*, const void*);

bool getArrayName(char * name);

int compare(Array *elem1, Array *elem2);

void initArrays(Array * arrays, int N);

void freeArrays(Array* arrays, int length);

void calculateAddresses(Array * arrays, int R, int N);

int binarySearch(Array * arrays,int start, int end, char * toSearch);

void flushInput();

int main(int argc, char* argv){
	int N,R;
	int i,j,trash = scanf("%d %d\n",&N,&R);

	Array* arrays = (Array *) malloc(sizeof(Array)*N);
	initArrays(arrays,N);

	qsort((void *) arrays,N, sizeof(Array),(compfn)compare);

	calculateAddresses(arrays,R,N);

	freeArrays(arrays,N);
}

bool getArrayName(char * name){
	int i;
	bool finished = FALSE;
	for (i = 0; i < 10; i++){
		char c = getchar();
		if (c == '\n') return TRUE;
		if (!finished){ 
			if (c == ' '){
				finished = TRUE;
				name[i] = '\0';
			} else {
				name[i] = c;
			}
		}
	}
	return FALSE;
}

void initArrays(Array * arrays, int N){
	int i,j,trash;
	for (i = 0; i < N; i++){
		bool newLineConsummed = getArrayName(arrays[i].name);
		trash = scanf("%lu %lu %d ",&(arrays[i].baseAddress),&(arrays[i].size),&(arrays[i].dimensionCount));
		arrays[i].dimensions = (ArrayDimension*) malloc(sizeof(ArrayDimension)*arrays[i].dimensionCount);
		for (j = 0; j < arrays[i].dimensionCount; j++){
			trash = scanf("%lu %lu",&(arrays[i].dimensions[j].lowerBound),&(arrays[i].dimensions[j].upperBound));
		}
		if (!newLineConsummed) flushInput();
	}
}

void freeArrays(Array* arrays, int length){
	int i;
	for (i = 0; i < length; i++){
		free(arrays[i].dimensions);
	}
	free(arrays);
}

void calculateAddresses(Array * arrays, int R, int N){
	char name[10];
	int i,j;
	unsigned long address;
	for (i = 0; i < R; i++){
		bool newLineConsummed = getArrayName(name);
		int index = binarySearch(arrays,0,N,name);

		if (index > -1){			
			j = 0;
			char c = name[j];
			while (c != '\0'){
				printf("%c",c);
				c = name[++j];
			}
		
			printf("[");
			address = arrays[index].baseAddress;
			int dims = arrays[index].dimensionCount;
			unsigned long * indices = (unsigned long *) malloc(sizeof(unsigned long)*dims);
			for (j = 0; j < dims; j++){
				int trash = scanf("%lu",&(indices[j]));
				printf("%lu",indices[j]);
				if (j != dims-1) {
					printf(", ");
					trash = scanf(" ");
				}
			}

			unsigned long Cd;
			for (j = dims; j > 0; j--){
				if (j == dims) {
					Cd = arrays[index].size;
				} else {
					Cd = Cd * (arrays[index].dimensions[j].upperBound - arrays[index].dimensions[j].lowerBound + 1);
				}
				address += Cd * (indices[j-1] - arrays[index].dimensions[j-1].lowerBound);
			}
			printf("] = %lu\n",address);
			free(indices);
		}
		if (!newLineConsummed) flushInput();
	}
}

int compare(Array *elem1, Array *elem2){
	int cmp = strcmp(elem1->name,elem2->name);
	return cmp;
}

int binarySearch(Array * arrays,int start, int end, char * toSearch){
	if (start == end){
		int cmp = strcmp(arrays[start].name,toSearch);
		if (cmp == 0) return start;
		return -1;
	} else if (start > end){
		return -1;
	} else {
		int i = (end - start)/2 + start;
		int cmp = strcmp(arrays[i].name,toSearch);
		if (cmp == 0) return i;
		else if (cmp < 0) {
			if (i == start) i = start + 1;
			return binarySearch(arrays,i,end,toSearch);
		} else {
			if (i == end) i = end - 1;
			return binarySearch(arrays,start,i,toSearch);
		}
	}
}

void flushInput(){
	char c = getchar();
	while (c != '\n' && c != EOF){
		c = getchar();
	}
}
