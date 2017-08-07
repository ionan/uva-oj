#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_VALUE 5 * 20 * 2

int coins[6] = {1, 2, 4, 10, 20, 40};

int makeChange(int amount){
  for (int i = 5; i >= 0; i--){
    if (amount >= coins[i]){
      return 1 + makeChange(amount - coins[i]);
    }
  }
  return 0;
}

int main(){
  double value;
  int amounts[6];
  int possibleAmounts[MAX_VALUE];
  while (scanf("%d %d %d %d %d %d %lf", amounts, amounts + 1, amounts + 2, amounts + 3, amounts + 4, amounts + 5, &value) > 6){
    int totalCoins = amounts[0] + amounts[1] + amounts[2] + amounts[3] + amounts[4] + amounts[5];
    for (int i = 0; i < MAX_VALUE; i++){
      possibleAmounts[i] = totalCoins + 1;
    }
    int maxSoFar = 0;
    // This array will hold all values that can be made by adding the availableCoins
    possibleAmounts[0] = 0;
    for (int i = 0; i < 6; i++){
      for (int j = 0; j < amounts[i]; j++){
        int start = min(MAX_VALUE - 1, maxSoFar + coins[i]);
        for (int k = start; k >= coins[i]; k--){
          if (possibleAmounts[k - coins[i]] < totalCoins + 1){
            possibleAmounts[k] = min(possibleAmounts[k - coins[i]] + 1, possibleAmounts[k]);
            maxSoFar = max(maxSoFar, k + 1);
          }
        }
      }
    }

    int amount = (int)(value * 20);
    int minimum = 9999;
    for (int i = amount; i < min(maxSoFar, MAX_VALUE); i++){
      if (possibleAmounts[i] <= totalCoins){
        minimum = min(minimum, possibleAmounts[i] + makeChange(i - amount));
      }
    }
    printf("%3d\n", minimum);
  }
  return 0;
}
