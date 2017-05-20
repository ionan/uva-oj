#include <stdio.h>
#include <limits.h>

typedef int bool;
#define true 1
#define false 0

char line[512];
char maxInt[12];
int maxIntSize = 0;
int fsdIdx = -1, lsdIdx = -1, ssdIdx = -1, lssdIdx = -1, opIdx = -1, end = 0, trash;
bool opFound = false, fsdFound = false, ssdFound = false;
	
void initMaxInt(){
	maxIntSize = 1;
	int n = INT_MAX;
	while (n >= 10){
		maxInt[maxIntSize - 1] = (char)(((int)'0')+(n % 10));
		n = n / 10;
		maxIntSize++;
	}
	maxInt[maxIntSize - 1] = (char)(((int)'0')+n);
	maxInt[maxIntSize] = '\0';
}

bool isBigger(int start, int end){
	if (end - start > maxIntSize) return true;
	else if (end - start < maxIntSize){
		return false;
	} else {
		int i = 0, j = maxIntSize-1;
		bool result = true;
		for (i = start; i = end; i++,j--){
			if (maxInt[j] > line[i]){
				result = false;
				break;
			} else if (maxInt[j] < line[i]){
				result = true;
				break;
			}
		}
		return result;
	}
}

bool isNumber(int c){
	return (c < 58 && c > 47);
}

bool isZero(int c){
	return c == 48;
}

bool isOperator(char c){
	return (c == '*' || c == '+');
}

void printResult(int size){
	line[size] = '\0';
	printf("%s\n",line);
	bool resultBigger = false;
	if (isBigger(fsdIdx,lsdIdx)){
		printf("first number too big\n");
		resultBigger = true;
	}
	if (isBigger(ssdIdx,lssdIdx)){
		printf("second number too big\n");
		resultBigger = true;
	}
	if (!resultBigger){
		line[lsdIdx + 1] = '\0';
		line[lssdIdx + 1] = '\0';
		int i, j;
		sscanf(line, "%d", &i);
		sscanf(&(line[ssdIdx]), "%d", &j);
		if (line[opIdx] == '+')
			resultBigger = (INT_MAX - i < j);
		else
			resultBigger = (INT_MAX / i < j);
	}
	if (resultBigger){
		printf("result too big\n");
	}
	fsdIdx = -1;
	lsdIdx = -1;
	ssdIdx = -1;
	lssdIdx = -1;
	opIdx = -1; 
	end = 0;
	opFound = false;
	fsdFound = false;
	ssdFound = false;
}

int main(int argc, char* argv){
	initMaxInt();
	while ((trash = scanf("%c", &(line[end]))) != EOF){
		if (line[end] == '\n'){
			printResult(end);
			continue;
		} else if (isNumber(line[end])){
			bool isz = isZero(line[end]);
			if (!opFound){
				if (!fsdFound && !isz) {
					fsdIdx = end;
					fsdFound = true;
					lsdIdx = end;
				} else if (fsdFound){
					lsdIdx++;
				}
			} else {
				if (!ssdFound && !isz) {
					ssdIdx = end;
					ssdFound = true;
					lssdIdx = end;
				} else if (ssdFound){
					lssdIdx++;
				}
			}
		} else if (isOperator(line[end])){
			opFound = true;
			opIdx = end;
		}
		end++;
	} 
	printResult(end);
	return 0;
}