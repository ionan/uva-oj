#include <stdio.h>

int main(){
	long long a,b;
	while (scanf("%lli %lli\n",&a,&b) != EOF){
		if (a < b) {
			printf("%lli\n",(b-a));
		} else {
			printf("%lli\n",(a-b));
		}
	}
	return 0;
}