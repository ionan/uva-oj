/*
	There is an objective test result such as “OOXXOXXOOO”. An ‘O’ means a correct answer of a problem
	and an ‘X’ means a wrong answer. The score of each problem of this test is calculated by itself and
	its just previous consecutive ‘O’s only when the answer is correct. For example, the score of the 10th
	problem is 3 that is obtained by itself and its two previous consecutive ‘O’s.

	Therefore, the score of “OOXXOXXOOO” is 10 which is calculated by “1+2+0+0+1+0+0+1+2+3”.

	You are to write a program calculating the scores of test results.

	INPUT

	Your program is to read from standard input. The input consists of T test cases. The number of test
	cases T is given in the first line of the input. Each test case starts with a line containing a string
	composed by ‘O’ and ‘X’ and the length of the string is more than 0 and less than 80. There is no spaces
	between ‘O’ and ‘X’.

	OUTPUT

	Your program is to write to standard output. Print exactly one line for each test case. The line is to
	contain the score of the test case.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, trash, consecutiveCorrects, currLength, score;
	char line[81];
	trash = scanf("%d\n", &T);
	while (T--){
		trash = scanf("%s", line);
		currLength = (int) strlen(line);
		consecutiveCorrects = 0;
		score = 0;
		for (int i = 0; i < currLength; i++){
			if (line[i] == 'O'){
				consecutiveCorrects++;
				score += consecutiveCorrects;
			} else {
				consecutiveCorrects = 0;
			}
		}
		printf("%d\n", score);
	}
	return 0;
}