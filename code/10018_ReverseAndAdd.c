#include <stdio.h>
#include <string.h>

#define bool int
#define TRUE 1
#define FALSE 0

int numberDigits[10];
int length;
unsigned long reverse;

unsigned long reverseNumber(unsigned long n);

bool isPalindrome(unsigned long length);

int main(int argc, char* argv){
	int testCases, trash, i, j; 
	unsigned long n;
	trash = scanf("%d\n",&testCases);
	for (i = 0; i < testCases; i++){
		trash = scanf("%lu\n",&n);
		j = 0;
		reverse = reverseNumber(n);
		unsigned long sum = 0;
		do {
			j++;
			sum = reverse + n;
			n = sum;
		} while(j < 1000 && !isPalindrome(sum));
		printf("%d %lu\n",j,sum);
	}
	return 0;
}

unsigned long reverseNumber(unsigned long n){
	length = 0;
	unsigned long reverse = 0;
	while (n / 10 > 0){
		numberDigits[length++] = n % 10;
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}
	numberDigits[length++] = n % 10;
	reverse = reverse * 10 + n % 10;
	return reverse;
}

bool isPalindrome(unsigned long num){
	int i;
	reverse = reverseNumber(num);
	bool result = TRUE;
	for (i = 0; i < length - i; i++){
		if (numberDigits[i] != numberDigits[length-i-1]) {
			result = FALSE;
			break;
		}
	}
	return result;
}