#include <cstdio>
using namespace std;

int main(){
    int banks, debentures, debtor, creditor, debenture;
    int reserves[20];
	int trash;
	while (scanf("%d %d", &banks, &debentures) == 2 && banks > 0 && debentures > 0){
		for (int i = 0; i < banks; i++){
			int trash = scanf("%d", &reserves[i]);
		}
		for (int i = 0; i < debentures; i++){
			int trash = scanf("%d %d %d", &debtor, &creditor, &debenture);
			reserves[debtor - 1] = reserves[debtor - 1] - debenture;
			reserves[creditor - 1] = reserves[creditor - 1] + debenture;
		}
		bool possible(true);
		for (int i = 0; i < banks && possible; i++){
			possible = reserves[i] >= 0;
		}
		if (possible){
			printf("S\n");
		} else {
			printf("N\n");
		}
	}
    return 0;
}
