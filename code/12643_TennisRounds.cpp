/*
	In an N-rounds tennis tournament a group of 2N players is seeded defining the first round to be played.
	Seeding means that each player is assigned a number between 1 and 2N , and this assignment defines
	the round’s draw as it establishes the matches that will be played among the players. In particular, the
	first round matches are numbered 1, 2, . . . , 2N−1: match k will have player 2 · k − 1 vs. player 2 · k, 
	for 1 ≤ k ≤ 2N−1.
	
	The winner of a match in the first round advances to the second round and the loser is eliminated.
	Consequently, the second round has exactly half the players of the first round. Moreover, if the winner
	of the first round match k would be reassigned the number k, then the second round’s draw may be
	defined exactly as already explained for the first round. This assignment process could be repeated
	over and over again until there is exactly one player remaining, who happens to be the tournament’s
	champion:

	It is clear that the seeding process and the subsequent draws make it possible for any two players
	to eventually face each other in some round. For example, for N = 3, players 2 and 5 could play at
	round 3 (the final), and players 5 and 7 could play at round 2 (one of the semifinals).
	
	The tennis tournament organization is developing an online portal featuring many services. You
	have been hired to implement one of such services: given the seeding numbers of two players (i.e., their
	place in the first round ordering), the service should compute the round number in which these two
	players could eventually have a match against other.

	INPUT

	The input consists of several test cases, each one defined by a line containing three blank-separated
	integers N, i, and j, where N indicates the total number of rounds in the tournament (1 ≤ N ≤ 20),
	and i, j represent two seeding numbers at the first round (1 ≤ i ≤ 2N , 1 ≤ j ≤ 2N , i ̸= j).

	OUTPUT

	For each test case, output a line with one integer indicating the round number in which players i and
	j may have a match in a tournament with N rounds.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int trash, N, i, j, roundNumber;
    while (scanf("%d %d %d", &N, &i, &j) != EOF){
    	i--;
    	j--;
    	roundNumber = 0;
    	do {
    		roundNumber++;
    		i /= 2;
    		j /= 2;
    	} while (i != j);
    	printf("%d\n", roundNumber);
    }
    return 0;
}