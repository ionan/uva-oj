#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int coinValues[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000}, coinTypes = 11;
  long memo[6001];
  double value;
  memset(memo, 0, sizeof memo);
  memo[0] = 1;
  for(int i = 0; i < coinTypes; i++){
    int coinValue = coinValues[i];
    for(int j = coinValue; j <= 6000; j++){
      memo[j] += memo[j - coinValue];
    }
  }

  while (scanf("%lf", &value) == 1 && value > 0.0){
    int index = (int)(value * 20);
    printf("%6.2lf%17ld\n", value, memo[index]);
  }

  return 0;
}
