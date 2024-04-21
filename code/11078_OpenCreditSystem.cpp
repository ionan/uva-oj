/*
	In an open credit system, the students can choose any course they like, but there is a problem. Some
	of the students are more senior than other students. The professor of such a course has found quite a
	number of such students who came from senior classes (as if they came to attend the pre requisite course
	after passing an advanced course). But he wants to do justice to the new students. So, he is going to
	take a placement test (basically an IQ test) to assess the level of difference among the students. He
	wants to know the maximum amount of score that a senior student gets more than any junior student.
	For example, if a senior student gets 80 and a junior student gets 70, then this amount is 10. Be careful
	that we don’t want the absolute value. Help the professor to figure out a solution.

	INPUT

	Input consists of a number of test cases T (less than 20). Each case starts with an integer n which is
	the number of students in the course. This value can be as large as 100,000 and as low as 2. Next n
	lines contain n integers where the i’th integer is the score of the i’th student. All these integers have
	absolute values less than 150000. If i < j, then i’th student is senior to the j’th student.
	
	OUTPUT

	For each test case, output the desired number in a new line. Follow the format shown in sample
	input-output section.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n, trash, scores[100001];
	trash = scanf("%d", &T);
	while (T--) {
		trash = scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			trash = scanf("%d", &scores[i]);
		}
		int max_value = scores[0];
		int min_value = scores[0];
		int max_difference = INT_MIN;
		for (int i = 1; i < n; i++) {
			max_difference = max(max_difference, max(max_value - scores[i], min_value - scores[i]));
			max_value = max(max_value, scores[i]);
			min_value = min(min_value, scores[i]);
		}
		printf("%d\n", max_difference);
	}

	return 0;
}