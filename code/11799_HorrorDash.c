#include <stdio.h>

int main(int argc, char *argv){
	int testCases, runners, maxSpeed, currentSpeed, i, j, trash;
	trash = scanf("%d\n",&testCases);
	for (i = 0; i < testCases; i++){
		trash = scanf("%d",&runners);
		maxSpeed = 0;
		for (j = 0; j < runners; j++){
			trash = scanf(" %d",&currentSpeed);
			if (currentSpeed > maxSpeed) 
				maxSpeed = currentSpeed;
		}
		trash = scanf("\n");
		printf("Case %d: %d\n",(i+1),maxSpeed);
	} 
	return 0;
}
