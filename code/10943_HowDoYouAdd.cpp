#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_INT 110

int N, K, memo[MAX_INT][MAX_INT];

int ways(int N, int K) {
  if (K == 1){
    return 1;
  } else if (memo[N][K] != -1){
    return memo[N][K];
  }
  int ans = 0;
  for (int split = 0; split <= N; split++){
    ans = (ans + ways(N - split, K - 1)) % 1000000;
  }
  return memo[N][K] = ans;
}

int main() {
  memset(memo, -1, sizeof memo);
  while (scanf("%d %d", &N, &K) == 2 && N != 0 && K != 0){
    printf("%d\n", ways(N, K));
  }
  return 0;
}
