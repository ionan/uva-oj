#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
    int testCases, bestScore, score;
	int trash = scanf("%d", &testCases);
	vector<string> urls;
	char url[100];
	for (int i = 1; i <= testCases; i++){
		bestScore = -1;
		for (int j = 0; j < 10; j++){
			trash = scanf("%s %d", url, &score);
			if (score >= bestScore){
				if (score > bestScore){
					bestScore = score;
					urls.clear();
				}
				urls.push_back(url);
			}
		}
		printf("Case #%d:\n", i);
		for(int j = 0; j < urls.size(); j++) {
		    cout<< urls.at(j) << endl;
		}

	}
    return 0;
}
