#include <stdio.h>

int main(int argc, char const *argv[]){
	int testCases, i, trash, sal1, sal2, sal3;
	trash = scanf("%d\n",&testCases);
	for (i = 0; i < testCases; i++){
		trash = scanf("%d %d %d\n",&sal1,&sal2,&sal3);
		if ((sal1 < sal2 && sal1 >= sal3) || (sal1 >= sal2 && sal1 < sal3)) 
			printf("Case %d: %d\n",(i+1),sal1);
		else if ((sal2 < sal1 && sal2 >= sal3) || (sal2 >= sal1 && sal2 < sal3))
			printf("Case %d: %d\n",(i+1),sal2);
		else if ((sal3 < sal1 && sal3 >= sal2) || (sal3 >= sal1 && sal3 < sal2))
			printf("Case %d: %d\n",(i+1),sal3);
	}
	return 0;
}