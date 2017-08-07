#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int coinValues[5] = {1, 5, 10, 25, 50}, value;
  long memo[30001];
  memset(memo, 0, sizeof(memo));
  memo[0] = 1;
  for (int i = 0; i < 5; i++){
    int coinValue = coinValues[i];
    for (int j = coinValue; j <= 30000; j++){
      memo[j] += memo[j - coinValue];
    }
  }
  while (scanf("%d", &value) > 0){
    if (memo[value] == 1){
      printf("There is only 1 way to produce %d cents change.\n", value);
    } else {
      printf("There are %ld ways to produce %d cents change.\n", memo[value], value);
    }
  }
  return 0;
}
