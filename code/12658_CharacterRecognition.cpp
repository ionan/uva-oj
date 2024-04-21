/*
	Write a program that recognizes characters. Don’t worry, because you only need to recognize three
	digits: 1, 2 and 3. Here they are:

		.*. *** ***
		.*. ..* ..*
		.*. *** ***
		.*. *.. ..*
		.*. *** ***

	INPUT

	The input contains only one test case, consisting of 6 lines. The first line contains n, the number of
	characters to recognize (1 ≤ n ≤ 10). Each of the next 5 lines contains 4n characters. Each character
	contains exactly 5 rows and 3 columns of characters followed by an empty column (filled with ‘.’).

	OUTPUT

	The output should contain exactly one line, the recognized digits in one line.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, trash, i;
	char lines[10 * 4 * (5 + 1)];
	char response[11];
	trash = scanf("%d\n", &n);
	trash = scanf("%*s%*s%*s%s%*s",lines);
	for (i = 0; i < n; i++){
        if (lines[4 * i + 1] == '*') response[i] = '1';
        else if (lines[4 * i] == '*') response[i] = '2';
        else response[i] = '3';
    }
    response[n] = '\0';
    printf("%s\n", response);
	return 0;
}