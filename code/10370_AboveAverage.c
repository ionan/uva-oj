#include <stdio.h>
#include <string.h>

int grades[101];

int main(int argc, char* argv){
	int testCases, trash, i, studNum, j, grade, sum;
	float gradeAvg;
	trash = scanf("%d\n",&testCases);
	for (i = 0; i < testCases; i++){
		memset(grades,0,sizeof(grades));
		gradeAvg = 0;
		trash = scanf("%d",&studNum);
		for (j = 0; j < studNum; j++){
			trash = scanf(" %d",&grade);
			grades[grade]++;
			gradeAvg += grade;
		}
		gradeAvg /= studNum;
		trash = scanf("\n");
		sum = 0;
		for (j = gradeAvg + 1; j < 101; j++) sum += grades[j];
		
		printf("%.3f%%\n",(float)((sum* 100) / (float)studNum));
	}
	return 0;
}