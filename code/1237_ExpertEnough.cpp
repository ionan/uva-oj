/*
	Auto-mobile Charting & Manufacturing (ACM) is a company that specializes in manufacturing automobile 
	spare parts. Being one of the leading automotive companies in the world, ACM are sure to keep
	up the latest information in that world. In the 100-year anniversary of the company, ACM compiled a
	huge list of range of prices of any automobiles ever recorded in the history. ACM then wants to develop
	a program that they called Automobile Expert System or AES for short.

	The program receives a price P as an input, and searches through the database for a car maker in
	which P falls in their range of lowest price L and highest price H of car they ever made. The program
	then output the car maker name. If the database contains no or more than one car maker that satisfies
	the query, the program produce output ‘UNDETERMINED’ (without quotes). Not so expert, huh? You are
	about to develop that program for ACM.

	INPUT

	The input begins with a line containing an integer T (T ≤ 10), the number of test cases follow. Each
	case begins with the size of the database D (D < 10000). The next each of D lines contains M, L
	and H (0 < L < H < 1000000) which are the name of the maker (contains no whitespace and will
	never exceeds 20 characters), the car’s lowest price the maker ever made, and the car’s highest price
	the maker ever made respectively. Then there is the number of query Q (Q < 1000) follows. Each of
	the next Q lines contains an integer P (0 < P < 1000000), the query price.
	
	OUTPUT

	Output for each query should be one line containing the name of the maker, or the string ‘UNDETERMINED’
	(without quotes) if there is no maker or more than one maker that satisfies the query. You should
	separate output for different case by one empty line.
*/
#include <bits/stdc++.h>
using namespace std;

// VERSION 1 (SLOWER)
/* int main() {
	int trash, T, D, L, H, Q, P, i, j, testCaseNumber;
	char M[21];
	vector<string> makerNames;
	int makerPriceRanges[1000001];
	trash = scanf("%d", &T);
	for (testCaseNumber = 0; testCaseNumber < T; testCaseNumber++){
		if (testCaseNumber > 0){
			printf("\n");
		}
		trash = scanf("%d", &D);
		for (i = 0; i < 1000001; i++){
			makerPriceRanges[i] = -99;
		}
		makerNames.clear();
		for (i = 0; i < D; i++){
			trash = scanf("%s %d %d", M, &L, &H);
			makerNames.push_back(M);
			for (j = L; j <= H; j++){
				makerPriceRanges[j] = (makerPriceRanges[j] == -99 ? i : -1);
			}
		}
		trash = scanf("%d", &Q);
		for (i = 1; i <= Q; i++){
			trash = scanf("%d", &P);
			if (makerPriceRanges[P] > -1){
				printf("%s\n", makerNames.at(makerPriceRanges[P]).c_str());
			} else {
				printf("UNDETERMINED\n");
			}
		}
	}
	return 0;
}*/

int main() {
    int trash, T, D, L[10001], H[10001], Q, P, i, j, testCaseNumber, makerNumber, totalMatches;
    char M[10001][25];
	trash = scanf("%d", &T);
	for (testCaseNumber = 0; testCaseNumber < T; testCaseNumber++){
		if (testCaseNumber > 0){
			printf("\n");
		}
		trash = scanf("%d", &D);		
		for (i = 0; i < D; i++){
			trash = scanf("%s %d %d", M[i], &L[i], &H[i]);
		}
		trash = scanf("%d", &Q);
		for (i = 1; i <= Q; i++){
			trash = scanf("%d", &P);
			totalMatches = 0;
			makerNumber = -1;
			for (j = 0; j < D; j++){
				if (L[j] <= P && H[j] >= P){
					totalMatches++;
					makerNumber = j;
					if (totalMatches > 1){
						makerNumber = -1;
						break;
					}
				}
			}
			if (makerNumber > -1){
				printf("%s\n", M[makerNumber]);
			} else {
				printf("UNDETERMINED\n");
			}
		}
    }
    return 0;
}