/*
	Daedalus is playing the game of “Don’t be greedy”, in which N players sit around a table having each
	of them five cards labelled 1, 10, 100, 1000 and 10000 points. In “Don’t be greedy’ the players may not
	talk to each other once the game starts, and there are M rounds. In each round, the bank announces a
	budget B. Then each player chooses one of the cards and places it, face down, on the table. The bank
	then turns the cards, so that all players can see all N cards. If the sum of the points in the chosen
	cards is less than or equal to B, then the bank gives to each player exactly the amount of points in the
	card he or she chose. Otherwise, no one gets anything. Each player gets his or her card back before the
	next round. The players are very rational and would like to maximize their points and minimize their
	regrets! What would you do in this situation? Cooperate or defect?

	Take the following table as an example. Daedalus won a total of 10 points, in the end, because
	only the first round was successful. But, looking back on the game, he sees that he could have won
	110 points, if he had chosen 100 points in the first round and 10 points in the third round. That is,
	Daedalus could have won 100 extra points! This holds only, of course, assuming the cards chosen by
	the other players remain unchanged.

		round 	budget B 	Daedalus 	Iapyx 	Icarus 	Ariadne 	Minos 	sum 	result
		1 		300 		10 			100 	10 		1			10 		131 	success
		2 		1100 		100 		10 		100 	1 			1000	1211 	fail
		3 		1200 		100 		100 	10 		1 			1000	1211 	fail

	Given the budget and the cards chosen in each round, we need to compute the maximum total
	number of extra points Daedalus could have won, in the end, if he had chosen the best possible card in
	each round, assuming the cards chosen by the other players remain unchanged.

	INPUT

	The input contains several test cases; each test case is formatted as follows. The first line contains
	two integers N and M, representing respectively the number of players and the number of rounds
	(1 ≤ N ≤ 20 and 1 ≤ M ≤ 50). Each of the next M lines describes a round with an integer B
	indicating the budget (1 ≤ B ≤ 106), followed by N integers C1, C2, …, CN representing that the
	i-th player chose the card labelled with Ci points during that round (Ci ∈ {1, 10, 100, 1000, 10000} for
	i = 1, 2, . . . , N). Daedalus is the first player.
	
	OUTPUT

	For each test case in the input, output a line with an integer representing the maximum total number of
	extra points Daedalus could have won, if he had chosen the best possible card in each round, assuming
	the cards chosen by the other players remain unchanged.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, N, M, B, daedalusCard, currentCard, totalSum, bestCard, i, currentExtraPoints;
	while (scanf("%d %d", &N, &M) != EOF && M > 0){
		currentExtraPoints = 0;
		while (M--){
			trash = scanf("%d", &B);
			trash = scanf("%d", &daedalusCard);
			totalSum = 0;
			bestCard = 0;
			for (i = 1; i < N; i++){
				trash = scanf("%d", &currentCard);
				totalSum += currentCard;
			}
			for (i = 4; i >= 0; i--){
				if (B - totalSum >= pow(10, i)){
					bestCard = pow(10, i);
					break;
				}
			}
			if (bestCard > daedalusCard){
				currentExtraPoints += bestCard - daedalusCard;
			} else if (bestCard < daedalusCard){
				currentExtraPoints += bestCard;
			}
		}
		printf("%d\n", currentExtraPoints);
	}
	return 0;
}