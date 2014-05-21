#include <stdio.h>

int main(int argc, char *argv){
	unsigned long a = 1,b = 1;
	while(scanf("%lu %lu\n",&a,&b) != EOF && a != 0 && b != 0){
		int carryOps = 0;
		int carry = 0;
		while(a > 10 && b > 10){
			if (a % 10 + b % 10 + carry > 9){
				carryOps++;
				carry = 1;
			}
			a /= 10;
			b /= 10;
		}
		if (carry + a + b > 9) carryOps++;
		if (carryOps == 0) printf("No carry operation.\n");
		else if (carryOps == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n",carryOps);
	}
	return 0;
}
