/*
	The eccentric owner of Chelsea Football Club Mr. Billionaire has sacked his Manager once again and
	appointed only the 10th manager in his prolonged 9 years’ reign at the club. And to the delight of the
	rival Manchester United fan’s, it’s none other than the great entertainer named Rafa Benitez! (If you
	follow EPL, you must know what I mean. If you don’t, you can still solve the problem but you are
	missing the next best thing after Monty Python and Mr. Bean.) Rafa, obviously with his unquestionable
	talent as a football manager, has immediately lead his team to a nosedive in performance and the poor
	United fans are worried that dear Mr. Billionaire might put an end to all the fun and sack Rafa sooner
	than any rival fan can hope for. So they decide to start an extensive “Keep Rafa at Chelsea” campaign.
	And you are the score keeper of the campaign.
	
	You are given a series of match results for Chelsea denoted by ‘W’ (win), ‘L’ (Lose) or ‘D’ (Draw). If
	Chelsea do not win a game for 3 consecutive matches, Rafa will be sacked instantly and start playing this
	game (www.mousebreaker.com/games/romanswrath/playgame). Your job is to figure out how many
	games will dear Rafa last at Chelsea.

	INPUT

	The input begins with a number T (1 ≤ T ≤ 100), the number of test cases. Each of the following lines
	contains a case. A case begins with n (3 ≤ n ≤ 500), the number of games in the input. Each of the
	following n lines contains a single letter among ‘W’, ‘L’ or ‘D’. These are the results from first n games
	of Chelsea (in chronological order) under Benitez.

	OUTPUT

	For each test case produce a line of the form ‘Case X: Y ’. X is the serial number of the test case
	while Y is the number of games Rafa can keep his job in this particular case. If Rafa doesn’t lose his
	job after all the games in a case, print ‘Yay! Mighty Rafa persists!’
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, T, n, X, matchesWithoutWin, Y, i;
	char result[5];
	trash = scanf("%d", &T);
	for (X = 1; X <= T; X++){
		trash = scanf("%d", &n);
		matchesWithoutWin = 0;
		Y = -1;
		for (i = 1; i <= n; i++){
			trash = scanf("%s", result);
			if (Y < 0){
				if (result[0] != 'W'){
					matchesWithoutWin++;
					if (matchesWithoutWin == 3){
						Y = i;
					}
				} else {
					matchesWithoutWin = 0;
				}
			}
		}
		if (Y > 0){
			printf("Case %d: %d\n", X, Y);
		} else {
			printf("Case %d: Yay! Mighty Rafa persists!\n", X);
		}		
	}
	return 0;
}