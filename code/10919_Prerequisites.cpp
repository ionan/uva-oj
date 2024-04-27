/*
	Freddie the frosh has chosen to take k courses. To meet the degree requirements, he
	must take courses from each of several categories. Can you assure Freddie that he
	will graduate, based on his course selection?
	
	INPUT
	
	Input consists of several test cases. For each case, the first line of input contains
	1 ≤ k ≤ 100, the number of courses Freddie has chosen, and 0 ≤ m ≤ 100, the
	number of categories. One or more lines follow containing k 4-digit integers follow; each
	is the number of a course selected by Freddie. Each category is represented by a line
	containing 1 ≤ c ≤ 100, the number of courses in the category, 0 ≤ r ≤ c, the minimum 
	number of courses from the category that must be taken, and the c course numbers in the 
	category. Each course number is a 4-digit integer. The same course may fulfil several 
	category requirements. Freddie’s selections, and the course numbers in any particular
	category, are distinct. A line containing ‘0’ follows the last test case.
	
	OUTPUT

	For each test case, output a line containing ‘yes’ if Freddie’s course selection meets 
	the degree requirements; otherwise output ‘no’.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, k, m, c, r, missingCourses, i;
	char course[4];
	set<string> courses = {};
	while(scanf("%d %d", &k, &m) != EOF && k != 0){
		courses.clear();
		missingCourses = 0;
		for (i = 0; i < k; i++){
			trash = scanf("%4s", course);
			courses.insert(course);
		}
		for (i = 0; i < m; i++){
			trash = scanf("%d %d ", &c, &r);
			while (c--){
				trash = scanf("%4s", course);
				if (courses.count(course) > 0){
					r--;
				}
			}
			missingCourses += max(r, 0);
		}
		if (missingCourses > 0){
			printf("no\n");
		} else {
			printf("yes\n");
		}
	}
	return 0;
}