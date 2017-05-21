#include <cstdio>
using namespace std;

int main(){
    int testCases, columns, north, south;
	int trash = scanf("%d", &testCases);
	while (testCases--){
		int trash = scanf("%d", &columns);
		int diff = 0;
		for (int j = 0; j < columns; j++){
			trash = scanf("%d %d", &north, &south);
			if (j == 0){
				diff = north - south;
			} else if (diff >= 0 && north - south != diff){
				diff = -1;
			}
		}
		if (diff >= 0){
			printf("yes\n");
		} else {
			printf("no\n");
		}
		if (testCases){
			printf("\n");
		}
	}
    return 0;
}
