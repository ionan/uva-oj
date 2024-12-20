/*
	In recent ACM ICPC World Finals (2015), there were 13 problems and each of those were solved by at
	least one team. Well, we will not discuss about how it happened or who did that.
	
	In this contest, SIUPC’2015, we are expecting to have at most 128 teams onsite. Three cheers for
	you for becoming one of the participating teams!
	
	Now, we will discuss what we wanted to prepare for you. From the World Finals 2015, we are just
	inspired to have a set of 13 problems each of which can be solved by at least one participating team.
	
	Luckily, we have come to know about an artificial intelligence system named “PAUL”. Given a set
	of problems, for each individual problem, it can foretell the number of teams that are going to solve
	that problem.
	
	Now, we need your help. We are going to give you the predictions of PAUL for some problemsets.
	For each of the problemsets (with 13 problems), we request you to tell us whether we can consider the
	set so that each problem from that set can be solved by at least one team.
	
	INPUT
	
	First line of input consists of an integer S (≤ 23), the number of problemsets with 13 problems. Each
	of next S lines consists of 13 space separated integers, the predicted number of teams to solve each
	problem.
	
	OUTPUT

	For each problem set, output a line formatted as ‘Set #N: Ans’. Here N is an integer which is the
	serial number of set. And Ans is your answer which is either ‘Yes’ or ‘No’ (without quotes).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, S, caseNumber, solverTeams, i, validProblemSet;
	trash = scanf("%d", &S);
	for (caseNumber = 1; caseNumber <= S; caseNumber++){
		validProblemSet = 1;
		for (i = 0; i < 13; i++){
			trash = scanf("%d", &solverTeams);
			if (solverTeams == 0){
				validProblemSet = 0;
			}
		}
		if (validProblemSet == 0){
			printf("Set #%d: No\n", caseNumber);
		} else {
			printf("Set #%d: Yes\n", caseNumber);
		}
	}
	return 0;
}