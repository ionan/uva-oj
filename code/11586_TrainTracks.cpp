/*
	Andy loves his set of wooden trains and railroad tracks. Each day, Daddy has to build a new track
	for him. The tracks he likes best form a simple loop with no branches or dead ends, so he can
	run his trains around and around for hours until it is time for the big crash that destroys the whole
	construction.
	
	So here is the question: Given a set of track pieces, can you form a simple loop with them,
	while using up all the pieces?

	Each piece of track is described by the connectors at both ends. A standard piece has one “male”
	and one “female” connector. But there are also track pieces with two male or two female connectors,
	as shown in the front right of the picture.

	To fit together, each male connector must be connected to a female connector. Unlike real wooden
	tracks, our pieces are assumed to be flexible, so their length or shape is not an issue here. However,
	you may not connect the two ends of the same piece together.
	
	INPUT

	Input begins with the number of test cases. Each following line contains one test case. Each test case
	consists of a list of between 1 and 50 (inclusive) train track pieces. A piece is described by two code
	letters: ‘M’ for male or ‘F’ for female connector. Pieces are separated by space characters.
	
	OUTPUT

	For each test case, output a line containing either ‘LOOP’ or ‘NO LOOP’ to indicate whether or not all
	the pieces can be joined into a single loop.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, testCases, mfConnectors, mmConnectors, ffConnectors;
	char connector[3], separator;
	trash = scanf("%d", &testCases);
	while(testCases--){
		separator = ' ';
		mfConnectors = 0;
		mmConnectors = 0;
		ffConnectors = 0;
		trash = 2;
		while (separator == ' ' && trash == 2){
			trash = scanf("%2s%c", connector, &separator);
			if (trash > 0){
				if (connector[0] == 'M' && connector[1] == 'F'){
					mfConnectors++;
				} else if (connector[0] == 'F' && connector[1] == 'M'){
					mfConnectors++;
				} else if (connector[0] == 'M' && connector[1] == 'M'){
					mmConnectors++;
				} else if (connector[0] == 'F' && connector[1] == 'F'){
					ffConnectors++;
				}
			}
		}		
		if (mfConnectors > 1 && mmConnectors == ffConnectors){
			printf("LOOP\n");
		} else if (mmConnectors == ffConnectors && mmConnectors > 0){
			printf("LOOP\n");
		} else {
			printf("NO LOOP\n");
		}		
	}
	return 0;
}