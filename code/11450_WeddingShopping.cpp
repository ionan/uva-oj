#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;

#define NUMBER_OF_MODELS 0

int money, garments, price[21][21];
int memo[201][21];

int shop(int currentMoney, int currentGarment) {
  if (currentMoney < 0){
    return INT_MIN;
  }
  if (currentGarment == garments){
    return money - currentMoney;
  }
  if (memo[currentMoney][currentGarment] != -1){
    return memo[currentMoney][currentGarment];
  }
  int best = -1;
  for (int model = 1; model <= price[currentGarment][NUMBER_OF_MODELS]; model++){
      best = max(best, shop(currentMoney - price[currentGarment][model], currentGarment + 1));
  }
  memo[currentMoney][currentGarment] = best;
  return best;
}

int main() {
  int testCases, best, trash = scanf("%d", &testCases);
  while (testCases--) {
    trash = scanf("%d %d", &money, &garments);
    for (int i = 0; i < garments; i++) {
      trash = scanf("%d", &price[i][NUMBER_OF_MODELS]);
      for (int j = 1; j <= price[i][NUMBER_OF_MODELS]; j++){
        trash = scanf("%d", &price[i][j]);
      }
    }
    memset(memo, -1, sizeof memo);
    best = shop(money, 0);
    if (best < 0){
      printf("no solution\n");
    } else {
      printf("%d\n", best);
    }
  }
  return 0;
}
