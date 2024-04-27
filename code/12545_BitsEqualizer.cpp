/*
	You are given two non-empty strings S and T of equal lengths. S contains the characters ‘0’, ‘1’ and
	‘?’, whereas T contains ‘0’ and ‘1’ only. Your task is to convert S into T in minimum number of moves.
	
	In each move, you can
		1. change a ‘0’ in S to ‘1’
		2. change a ‘?’ in S to ‘0’ or ‘1’
		3. swap any two characters in S
	
	As an example, suppose S = ”01??00” and T = ”001010”. We can transform S into T in 3 moves:
	
		• Initially S = ”01??00”
		• – Move 1: change S[2] to ‘1’. S becomes ”011?00”
		• – Move 2: change S[3] to ‘0’. S becomes ”011000”
		• – Move 3: swap S[1] with S[4]. S becomes ”001010”
		• S is now equal to T

	INPUT

	The first line of input is an integer C (C ≤ 200) that indicates the number of test cases. Each case
	consists of two lines. The first line is the string S consisting of ‘0’, ‘1’ and ‘?’. The second line is the
	string T consisting of ‘0’ and ‘1’. The lengths of the strings won’t be larger than 100.

	OUTPUT

	For each case, output the case number first followed by the minimum number of moves required to
	convert S into T. If the transition is impossible,output ‘-1’ instead.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int C, trash, currentLength, i, caseNumber, minMoves;
	char S[101], T[101];
	trash = scanf("%d", &C);
	for (caseNumber = 1; caseNumber <= C; caseNumber++){
		trash = scanf("%s", S);
		trash = scanf("%s", T);
printf("Strings are %s and %s\n", S, T);
		currentLength = strlen(S);
		minMoves = 0;
		for (int i = 0; i < currentLength; i++){
			if (S[i] != T[i]){
printf("Character %d is not the same: %c / %c\n", i, S[i], T[i]);
				if (i < currentLength - 1 && S[i] == T[i + 1] && S[i + 1] == T[i]){
printf("	Swap with next character (%c%c / %c%c)!\n", S[i], S[i + 1], T[i], T[i + 1]);					
					minMoves++;
					i++;
				} else if (i < currentLength - 1 && S[i] == T[i + 1] && S[i + 1] == '?'){
printf("	Swap with next character and change to %c!\n", T[i]);					
					minMoves++;
					i++;
				} else if ((S[i] == '0' || S[i] == '?') && T[i] == '1'){
printf("	Change to 1!\n");					
					minMoves++;
				} else if (S[i] == '?'){
printf("	Change to %c!\n", T[i]);					
					minMoves++;
				} else {
printf("	impossible to convert!\n");	
					minMoves = -1;
					break;
				}
			}
		}
		printf("Case %d: %d\n", caseNumber, minMoves);
	}
	return 0;
}