#include <cstdio>
using namespace std;

int main(){
    int testCases, walls, last, current;
	int trash = scanf("%d", &testCases);
	for (int i = 1; i <= testCases; i++){
		trash = scanf("%d", &walls);
		int high = 0, low = 0;
		trash = scanf("%d", &last);
		while (--walls){
			trash = scanf("%d", &current);
			if (current > last){
				high++;
			} else if (current < last){
				low++;
			}
			last = current;
		}
		printf("Case %d: %d %d\n", i, high, low);
	}
    return 0;
}
