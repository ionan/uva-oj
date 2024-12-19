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
	int C, trash, currentLength, i, caseNumber, minMoves, oneAndZeroes, zeroAndOnes, questionMarks;
	int zeroesOnS, onesOnS, questionMarksOnS, zeroesOnT, onesOnT;
	char S[101], T[101];
	trash = scanf("%d", &C);
	for (caseNumber = 1; caseNumber <= C; caseNumber++){
		trash = scanf("%s", S);
		trash = scanf("%s", T);
		currentLength = strlen(S);
		minMoves = 0;
		oneAndZeroes = 0;
		zeroAndOnes = 0;
		questionMarks = 0;
		zeroesOnS = 0;
		onesOnS = 0;
		questionMarksOnS = 0;
		zeroesOnT = 0;
		onesOnT = 0;
		for (int i = 0; i < currentLength; i++){
			if (S[i] == '0'){
				zeroesOnS++;
			} else if (S[i] == '1'){
				onesOnS++;
			} else {
				questionMarksOnS++;
			}
			if (T[i] == '0'){
				zeroesOnT++;
			} else if (T[i] == '1'){
				onesOnT++;
			}

			if (S[i] == '0' && T[i] == '1'){
				zeroAndOnes++;
			} else if (S[i] == '1' && T[i] == '0'){
				oneAndZeroes++;
			} else if (S[i] == '?'){
				questionMarks++;
			}
		}
		if (zeroesOnT > zeroesOnS + questionMarksOnS){
			minMoves = -1;
		} else {
			minMoves = min(zeroAndOnes, oneAndZeroes) + // swaps between 1 and 0
					   max(zeroAndOnes - oneAndZeroes, 0) + // convert 0's to 1's
				   	   min(questionMarks, max(oneAndZeroes - zeroAndOnes, 0)) +  // swaps between 1 and ?
				   	   questionMarks; // ? conversion
		}
		printf("Case %d: %d\n", caseNumber, minMoves);
	}
	return 0;
}