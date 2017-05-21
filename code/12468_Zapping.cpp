#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
    int from, to, minPresses;
    while (scanf("%d %d", &from, &to) == 2 && from >= 0 && to >= 0){
    	if (to < from){
    		minPresses = to;
    		to = from;
    		from = minPresses;
    	}
    	minPresses = min(abs(to - from), abs(from + 100 - to));
    	printf("%d\n", minPresses);
    }
    return 0;
}
