#include <iostream>
using namespace std;

int main(){
    int testCases, position, movements, index;
    cin >> testCases;
    char moves[100];
    string instruction;
    while (testCases--){
        position = 0;
    	cin >> movements;
        for (int i = 0; i < movements; i++){
            cin >> instruction;
            moves[i] = instruction[0];
            if (moves[i] == 'S'){
                cin >> instruction >> index;
                moves[i] = moves[index - 1];
            }
            if (moves[i] == 'L'){
                position--;
            } else {
                position++;
            }
        }
        cout << position << endl;
    }
    return 0;
}