#include <cstdio>
#include <cstring>
using namespace std;

int coinValue[5] = {1, 5, 10, 25, 50}, memo[6][7500], coinTypes = 5;

int ways(int type, int value) {
  if (value == 0) return 1;
  if (value < 0 || type == coinTypes) return 0;
  if (memo[type][value] != -1) return memo[type][value];
  int val = ways(type + 1, value) + ways(type, value - coinValue[type]);
  memo[type][value] = val;
  return val;
}

int main() {
  int value;
  memset(memo, -1, sizeof memo);
  while (scanf("%d", &value) == 1){
    printf("%d\n", ways(0, value));
  }
  return 0;
}
