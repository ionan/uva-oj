#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_SIZE 11
#define MAX_VALUE 2000000000

int beepers, dist[MAX_SIZE][MAX_SIZE], memo[MAX_SIZE][1 << MAX_SIZE];

int travelingSalesman(int pos, int bitmask) {
  if (bitmask == (1 << (beepers + 1)) - 1)
    return dist[pos][0];
  if (memo[pos][bitmask] != -1)
    return memo[pos][bitmask];

  int ans = MAX_VALUE;
  for (int i = 0; i <= beepers; i++){
    if (i != pos && !(bitmask & (1 << i))){
      ans = min(ans, dist[pos][i] + travelingSalesman(i, bitmask | (1 << i)));
    }
  }
  return memo[pos][bitmask] = ans;
}

int main() {
  int testCases, worldSize[2], x[MAX_SIZE], y[MAX_SIZE];
  scanf("%d", &testCases);
  while (testCases--) {
    scanf("%d %d", worldSize, worldSize + 1);
    scanf("%d %d", x, y);
    scanf("%d", &beepers);
    for (int i = 1; i <= beepers; i++){
      scanf("%d %d", x + i, y + i);
    }

    for (int i = 0; i <= beepers; i++){
      for (int j = 0; j <= beepers; j++){
        dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
      }
    }
    memset(memo, -1, sizeof memo);
    printf("The shortest path has length %d\n", travelingSalesman(0, 1));
  }

  return 0;
}
