/*
	Given a string of 0’s and 1’s up to 1000000 characters long and indices i and j, you are to answer
	a question whether all characters between position min(i, j) and position max(i, j) (inclusive) are the
	same.

	INPUT

	There are multiple cases on input. The first line of each case gives a string of 0’s and 1’s. The next
	line contains a positive integer n giving the number of queries for this case. The next n lines contain
	queries, one per line. Each query is given by two non-negative integers, i and j. For each query, you
	are to print ‘Yes’ if all characters in the string between position min(i, j) and position max(i, j) are the
	same, and ‘No’ otherwise.

	OUTPUT

	Each case on output should start with a heading as in the sample below. The input ends with an empty
	string that is a line containing only the new line character, this string should not be processed. The
	input may also with end of file. So keep check for both.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	char line[1000001];
	int trash, runningCount[1000001], currentLength, idx, i, j, n, caseNumber = 0;
	while(scanf("%s", line) != EOF){
		caseNumber++;
		printf("Case %d:\n", caseNumber);
		currentLength = strlen(line);
		runningCount[0] = line[0] == '1' ? 1 : 0;
		for (idx = 1; idx < currentLength; idx++){
			runningCount[idx] = runningCount[idx - 1] + (line[idx] == '1' ? 1 : 0);
		}
		if (scanf("%d", &n) != EOF){
			while (n--){
				trash = scanf("%d %d", &i, &j);
				if (
					i == j || 
					(runningCount[max(i, j)] == runningCount[min(i, j)] && line[min(i, j)] != '1') || 
					(runningCount[max(i, j)] - runningCount[min(i, j)] == abs(i - j) && line[min(i, j)] != '0')
				){
					printf("Yes\n");
				} else {
					printf("No\n");
				}
			}
		}
	}
	return 0;
}