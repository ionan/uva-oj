#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define INFINITE 9999999

int A[55], memo[55][55];

int cutStick(int start, int end) {
  if (start + 1 == end){
    return 0;
  }
  if (memo[start][end] != -1){
    return memo[start][end];
  }
  int ans = INFINITE;
  for (int i = start + 1; i < end; i++){
    ans = min(ans, cutStick(start, i) + cutStick(i, end) + (A[end]-A[start]));
  }
  return memo[start][end] = ans;
}

int main() {
  int len, cuts;
  while (scanf("%d", &len) > 0 && len > 0) {
    A[0] = 0;
    scanf("%d", &cuts);
    for (int i = 1; i <= cuts; i++){
      scanf("%d", A + i);
    }
    A[cuts + 1] = len;
    memset(memo, -1, sizeof memo);
    printf("The minimum cutting is %d.\n", cutStick(0, cuts + 1));
  }

  return 0;
}
