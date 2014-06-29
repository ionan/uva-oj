#include <stdio.h>
#include <stack>

using namespace std;

bool isOperator(char elem){
	return (elem == '+' || elem == '-' || elem == '*' || elem == '/');
}

bool hasGreaterOrEqualPrecedence(char op1, char op2){
	return (op1 == '*' || op1 == '/' || ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')));
}

int main(int argc, char** argv){
	int testCases;
	int trash = scanf("%d\n\n",&testCases);
	char elem;
	stack <char> elems;
	while (testCases > 0){
		elem = getchar();
		while (true){
			if (elem == '\n'){
				elem = getchar();
				if (elem == '\n' || elem == EOF) break;
			} else if (elem == EOF){
				break;
			}
			if (isOperator(elem)){
				while (!elems.empty() && elems.top() != '(' && hasGreaterOrEqualPrecedence(elems.top(), elem)){
					printf("%c",elems.top());
					elems.pop();
				}
				elems.push(elem);
			} else if (elem == '('){
				elems.push(elem);
			} else if (elem == ')'){
				while (!elems.empty() && elems.top() != '('){
					printf("%c",elems.top());
					elems.pop();
				} 
				if (elems.top() == '(')
					elems.pop();
			} else {
				printf("%c",elem);
			}
			elem = getchar();
		}
		while (!elems.empty()){
			if (isOperator(elems.top()))
				printf("%c",elems.top());
			elems.pop();
		}
		testCases--;
		printf("\n");
		if (testCases > 0) 
			printf("\n");
	}
	return 0;
}