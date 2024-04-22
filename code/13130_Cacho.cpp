/*
	In Bolivia there is a very popular game called “Cacho”. The game consists rolling five dices (a1, a2, a3,
	a4, a5) and then annotate the result according to certain rules. This time we will focus on one case in
	particular: “escala”. A “escala” is the scene in which the dices form a sequence of consecutive numbers.
	More formally a “escala” meets the property:

		ai + 1 = ai+1, 1 ≤ i ≤ 4
	
	There are two types of “escala”: a ordinary “escala” (it satisfy the property described above), and
	a “Escala Real” (when the scenery is 1, 3, 4, 5, 6. In the game this case is also a valid “scala”).
	
	Cael is a boy who is learning to play and wants you to help develop a program to check when five
	dices are forming a “escala”. Note that the “Escala Real” is not a valid “escala” for Cael.
	
	INPUT

	The input begins with a number T ≤ 100, the number of test cases. Below are T lines, each with five
	numbers ai (1 ≤ ai ≤ 6) in no-decreasing order.

	OUTPUT

	In each case, if the five dices form a scale print in one line ‘Y’. Otherwise print in one line ‘N’ (quotes
	for clarity).
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, T, a1, a2, a3, a4, a5;
	trash = scanf("%d", &T);
	while (T--){
		trash = scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
		if (
			(a1 + 1 == a2) &&
			(a2 + 1 == a3) &&
			(a3 + 1 == a4) &&
			(a4 + 1 == a5)
		){
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}
	return 0;
}