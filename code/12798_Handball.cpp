/*
	Frustrated and disappointed with the results of its football team, the Super Brazilian Club (SBC)
	decided to invest in the handball team. In order to better rate the players, the coaches would like to
	analyse their regularity. Specifically, they are interested in knowing how many players scored goals in
	all matches.

	As the data volume is very big, they would like to have a computer program to do this counting.
	
	INPUT

	The input contains several test cases. The first line of a test case contains two integers N and M
	(1 ≤ N ≤ 100 and 1 ≤ M ≤ 100) indicating, respectively, the number of players and the number of
	matches. Each one of the next N lines describes the performance of one player: the i-th line contains
	M integers Xj (0 ≤ Xj ≤ 100, for 1 ≤ j ≤ M), giving the number of goals that the i-th player scored
	in each match.

	OUTPUT

	For each test case in the input your program must output one line, containing one integer, the number
	of players that scored goals in all matches!
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, N, M, X, i, playersWithGoals, matchesWithZeroGoals;
	while (scanf("%d %d", &N, &M) != EOF){
		playersWithGoals = 0;
		while (N--){
			matchesWithZeroGoals = 0;
			for (i = 0; i < M; i++){
				trash = scanf("%d", &X);			
				if (X == 0){
					matchesWithZeroGoals++;
				}
			}
			playersWithGoals += (matchesWithZeroGoals == 0 ? 1 : 0);
		}
		printf("%d\n", playersWithGoals);
	}
	return 0;
}