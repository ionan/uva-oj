#include <cstdio>
using namespace std;

int main(){
    int participants, budget, hotels, weeks;
	int price;
	int beds;
	int best;
	int trash;
    while(scanf("%d %d %d %d", &participants, &budget, &hotels, &weeks) == 4){
		best = budget + 1;
		for (int i = 0; i < hotels; i++){
			trash = scanf("%d", &price);
			for (int j = 0; j < weeks; j++){
				trash = scanf("%d", &beds);
				if (beds >= participants && price * participants < best){
					best = price * participants;
				}
			}
		}
		if (best > budget){ 
			printf("stay home\n");
        } else {
			printf("%d\n", best);
		}	
	}
    return 0;
}
