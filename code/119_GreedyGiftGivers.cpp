/*
	This problem involves determining, for a group of gift-giving friends, how much more each person gives
	than they receive (and vice versa for those that view gift-giving with cynicism).

	In this problem each person sets aside some money for gift-giving and divides this money evenly
	among all those to whom gifts are given.

	However, in any group of friends, some people are more giving than others (or at least may have
	more acquaintances) and some people have more money than others.

	Given a group of friends, the money each person in the group spends on gifts, and a (sub)list of
	friends to whom each person gives gifts; you are to write a program that determines how much more
	(or less) each person in the group gives than they receive.

	INPUT

	The input is a sequence of gift-giving groups. A group consists of several lines:

		• the number of people in the group,
		• a list of the names of each person in the group,
		• a line for each person in the group consisting of the name of the person, the amount of money
		spent on gifts, the number of people to whom gifts are given, and the names of those to whom
		gifts are given.

	All names are lower-case letters, there are no more than 10 people in a group, and no name is more
	than 12 characters in length. Money is a non-negative integer less than 2000.

	The input consists of one or more groups and is terminated by end-of-file.
	
	OUTPUT
	
	For each group of gift-givers, the name of each person in the group should be printed on a line followed
	by the net gain (or loss) received (or spent) by the person. Names in a group should be printed in the
	same order in which they first appear in the input.

	The output for each group should be separated from other groups by a blank line. All gifts are
	integers. Each person gives the same integer amount of money to each friend to whom any money is
	given, and gives as much as possible. Any money not given is kept and is part of a person’s “net worth”
	printed in the output.

*/
#include <bits/stdc++.h>
using namespace std;

int getNameIndex(vector<string> names, char* name){
	int i = 0, vsize = names.size();
	for (i = 0; i < vsize; i++){
		if (names.at(i).compare(name) == 0){
			return i;
		}
	}
	return -1;
}

int main() {
	int groupSize, trash, i, j, amount, numberOfPeople, amountPerPerson, netResult[10], testCase = 0; 
	size_t personIndex;
	vector<string> names;
	char name[13];
	while (scanf("%d", &groupSize) != EOF && groupSize > 0){
		testCase++;
		if (testCase > 1){
			printf("\n");
		}
		names.clear();
		for (i = 0; i < groupSize; i++){
			trash = scanf("%s", name);
			names.push_back(name);
			netResult[i] = 0;
		}
		for (i = 0; i < groupSize; i++){
			trash = scanf("%s", name);
			trash = scanf("%d %d", &amount, &numberOfPeople);
			amountPerPerson = numberOfPeople > 0 ? (int) (amount / numberOfPeople) : 0;
			personIndex = getNameIndex(names, name);
			netResult[personIndex] -= (amountPerPerson * numberOfPeople);
			for (j = 0; j < numberOfPeople; j++){
				trash = scanf("%s", name);
				personIndex = getNameIndex(names, name);
				netResult[personIndex] += amountPerPerson;
			}
		}
		for (i = 0; i < groupSize; i++){
			printf("%s %d\n", names.at(i).c_str(), netResult[i]);
		}
	}
	return 0;
}