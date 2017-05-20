#include <iostream>
#include <list>
#include <cstdio>
using namespace std;

int main(){
    list<char> l;
    list<char>::iterator it;
    char c;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            for (it = l.begin(); it != l.end(); ++it) cout << *it;
            cout << endl;
            l.clear();
        } else if (c == '['){
            it = l.begin();
        } else if (c == ']'){
            it = l.end();
        } else {
            l.insert(it,c);    
        }
    }
    for (it = l.begin(); it != l.end(); ++it) cout << *it;
    cout << endl;
    return 0;
}