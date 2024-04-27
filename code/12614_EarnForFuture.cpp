/*
	In a lazy afternoon the great Froogrammer came to realize that, to make his future plans successful he
	needs a lot of money. To make some quick cash he decided to go to the casino to play a game. The
	rule of the game is the following:

		• The player is given N cards. Each card has a non-negative integer printed in it.
		• The player will choose some cards from the given cards.
		• The bitwise AND value of the chosen cards will be calculated and the player will be given the
		  same amount of money. (i.e. equal to the bitwise AND value of the chosen cards).
	
	After getting N cards Froogrammer was in a fix as usual. He could not decide which of the cards to
	choose. So he called you to help him. Please tell him the maximum amount he can win from these
	set of cards. If you are confused about bitwise AND operation see the notes section below.
	
	INPUT

	The first line of input will contain the number of test cases T (T < 101). Then there will be T test
	cases. Each of the test cases will start with an integer N (0 < N < 31) denoting the number of cards.
	Then the following line will contain N non-negative integers Ci (0 ≤ Ci < 2
	31) separated by space,
	denoting the numbers printed on each of the cards.
	
	OUTPUT

	For each test case print one line of output denoting the case number and the maximum amount
	Froogrammer can win. See sample output for exact format.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, N, trash, i, maxNumber, currentNumber;
	trash = scanf("%d", &T);
	for (i = 1; i <= T; i++){
		maxNumber = -1;
		trash = scanf("%d", &N);
		while (N--){
			trash = scanf("%d", &currentNumber);
			maxNumber = max(maxNumber, currentNumber);
		}
		printf("Case %d: %d\n", i, maxNumber);
	}
	return 0;
}