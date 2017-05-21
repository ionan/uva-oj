#include <cstdio>
using namespace std;

int main(){
    int testCases, last, current;
	int trash = scanf("%d", &testCases);
	printf("Lumberjacks:\n");
	while (testCases--){
		bool ordered(true);
		trash = scanf("%d %d", &last, &current);
		bool incrementing = current > last;
		for (int i = 3; i <= 10; i++){
			last = current;
			trash = scanf("%d", &current);
			if (ordered && (incrementing && last > current) || (!incrementing && last < current)){
				ordered = false;
			}
		}
		if (ordered){
			printf("Ordered\n");
		} else {
			printf("Unordered\n");
		}
	}
    return 0;
}
