#include <stdio.h>
#include <string.h>

int calculated[101];

int f91(int val);

int  main(int argc, char const *argv[]){
	memset(calculated,0,sizeof(calculated));
	int n;
	while (scanf("%d\n",&n) != EOF && n != 0){
		printf("f91(%d) = %d\n",n,f91(n));
	}
	return 0;
}

int f91(int val){
	if (val > 100) {
		return val - 10;
	} else if (calculated[val] > 0){
		return calculated[val];
	} else {
		int v = f91(f91(val + 11));
		calculated[val] = v;
		return v;
	}
}