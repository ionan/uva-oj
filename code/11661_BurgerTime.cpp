/*
	Everybody knows that along the more important highways there are countless fast food restaurants.
	One can find easily hamburgers, hot dogs, pizzas, sandwiches ... food everywhere.
	
	Many times the problem isn’t to find a restaurant but a drugstore. After a big lunch with fast food
	it’s normal that we need a drugstore because our stomach begins to feel pain.
	
	Given the locations of the restaurants and drugstores on a highway, you want to determine the
	minimum distance between a restaurant and a drugstore.
	
	INPUT

	The first line of each test case gives an integer L (1 ≤ L ≤ 2000000) indicating the length of the
	highway.

	The second line of each test case contains a string S of length L, showing the positions of the
	restaurants and drugstores along the highway in the following manner:

		• The character ‘R’ represents a place with a restaurant.
		• The character ‘D’ represents a place with a drugstore.
		• The character ‘Z’ represents a place with a restaurant and a drugstore.
		• The character ‘.’ represents an empty place.

	You can suppose that every test case has at least one restaurant and at least one drugstore.
	The end of the input is indicated when L = 0.
	
	OUTPUT

	For each case in the input, print one line with the minimum distance between a restaurant and a
	drugstore.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int L, lastRestaurantPosition, lastDrugstorePosition, minDistance, currentPosition;
	char s;
	while (scanf("%d\n", &L) != EOF && L != 0){
		lastRestaurantPosition = -1;
		lastDrugstorePosition = -1;
		minDistance = INT_MAX;
		currentPosition = 0;
		while (scanf("%c", &s) != EOF && currentPosition < L){
			currentPosition++;		
			if (s == 'R' || s == 'Z'){
				lastRestaurantPosition = currentPosition;
			}
			if (s == 'D' || s == 'Z'){
				lastDrugstorePosition = currentPosition;
			}
			if (lastRestaurantPosition > -1 && lastDrugstorePosition > -1){
				minDistance = min(minDistance, abs(lastRestaurantPosition - lastDrugstorePosition));
			}
		}
		printf("%d\n", minDistance);
	}
	return 0;
}