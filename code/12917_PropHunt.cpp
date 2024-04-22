/*
	Prop hunt is a game modification (or simply a mod), similar
	to the famous hide and seek, where two teams play against
	each other. One team are the props, they are players that
	can choose any object of the scenario to disguise themselves
	as, so they could be a table, a book, a barrel, a paper,
	whatever they want. They must be completely calm or
	the other team, the hunters, will kill them. As a hunter,
	you must be careful: if you shoot something that is not a
	disguised player, you start losing life. At the end, if any
	prop survives they will win, otherwise the hunters will win.
	
	Your mission is to determine who is going to be the winner of the game, but thankfully, with a
	couple of simplifications. You will get three numbers: P — the quantity of players in the props team,
	H — the number of hunters and O — the objects to disguise as. Assume that all the hunters are bots
	(that is, controlled by the computer) and they’re pretty bad: the hunters will shoot everything in the
	scenario, starting by the less suspicious objects and ending with the disguised players. If every hunter
	has 1 point of life, what team will win?

	INPUT

	The input consists of several test cases, each one on a single line that contains 3 integers P (1 ≤ P ≤ 5),
	H (1 ≤ H ≤ 5) and O (1 ≤ P ≤ O ≤ 10).
	
	OUTPUT

	Print on a single line the text ‘Props win!’ if the props survive, otherwise print ‘Hunters win!’.
	
	Explanation: On the first case, there are 2 props and 2 hunters, but 3 objects to disguise as. The
	first hunter dies trying to kill the object that is not a player, but the second hunter shoots to the other
	objects that are the disguised players.
	
	In the second case, the first hunter shoots a non-player object, and the second one does the same,
	so the props survive.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, P, H, O;
	while (scanf("%d %d %d", &P, &H, &O) != EOF){
		if (O - P < H){
			printf("Hunters win!\n");
		} else {
			printf("Props win!\n");
		}
	}
	return 0;
}