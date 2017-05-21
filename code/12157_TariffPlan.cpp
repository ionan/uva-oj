#include <cstdio>
using namespace std;

int main(){
    int testCases, mileCost, juiceCost, duration, calls;
	int trash = scanf("%d", &testCases);
	for (int i = 1; i <= testCases; i++){
		trash = scanf("%d", &calls);
		mileCost = juiceCost = 0;
		while (calls--){
			trash = scanf("%d", &duration);
			mileCost += ((duration/30) + 1) * 10;
			juiceCost += ((duration/60) + 1) * 15;
		}
		if (mileCost < juiceCost){
			printf("Case %d: Mile %d\n", i, mileCost);
		} else if (mileCost > juiceCost){
			printf("Case %d: Juice %d\n", i, juiceCost);
		} else {
			printf("Case %d: Mile Juice %d\n", i, juiceCost);
		}
	}
    return 0;
}
