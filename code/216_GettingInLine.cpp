#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_SIZE 9
#define MAX_VALUE 2000000000

int computers, parent[MAX_SIZE][1 << MAX_SIZE][2], currentParent;
double dist[MAX_SIZE][MAX_SIZE], memo[MAX_SIZE][1 << MAX_SIZE];

double travelingSalesman(int pos, int bitmask) {
  if (bitmask == (1 << (computers + 1)) - 1)
    return dist[pos][0];
  if (memo[pos][bitmask] != -1)
    return memo[pos][bitmask];

  double ans = -1;
  int next = -1;
  for (int i = 0; i < computers; i++){
    if (i != pos && !(bitmask & (1 << i))){
      double cndDist = dist[pos][i] + travelingSalesman(i, bitmask | (1 << i));
      if (cndDist < ans || ans == -1){
        ans = cndDist;
        next = i;
      }
    }
  }
  parent[pos][bitmask][currentParent] = next;
  memo[pos][bitmask] = ans;
  return memo[pos][bitmask];
}

int main() {
  int testCase = 1, x[MAX_SIZE], y[MAX_SIZE];
  while (scanf("%d", &computers) > 0 && computers > 0) {
    for (int i = 0; i < computers; i++){
      scanf("%d %d", x + i, y + i);
    }

    for (int i = 0; i <= computers; i++){
      for (int j = 0; j <= computers; j++){
        dist[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) + 16;
      }
    }
    for (int i = 0; i < MAX_SIZE; i++){
      for (int j = 0; j < (1 << MAX_SIZE); j++){
          memo[i][j] = -1;
          parent[i][j][0] = -1;
          parent[i][j][1] = -1;
      }
    }
    currentParent = 0;
    int best = -1, bestParent = 0;
    double bestL = -1;
    for (int i = 0; i <= computers; i++){
      double l = travelingSalesman(i, 1 << i);
      if (bestL == -1 || bestL > l){
        bestL = l;
        best = i;
        bestParent = currentParent;
        currentParent &= 1;
      }
    }
    double shortestLength = 0;
    printf("**********************************************************\nNetwork #%d\n", testCase++);
    int bitmask = 1 << best, index = best;
    for (int i = 0; i < computers - 1; i++) {
        int next = parent[index][bitmask][bestParent];
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
              x[index], y[index], x[next], y[next], dist[index][next]);
        bitmask |= 1 << next;
        shortestLength += dist[index][next];
        index = next;
    }
    printf("Number of feet of cable required is %.2lf.\n", shortestLength);
  }

  return 0;
}
