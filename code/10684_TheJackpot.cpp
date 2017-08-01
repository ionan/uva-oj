#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int N, value;
  while(scanf("%d\n", &N) > 0 && N > 0){
    int sum = 0, ans = 0;
    for (int i = 0; i < N; i++){
      scanf("%d", &value);
      sum += value;
      ans = max(ans, sum);
      if (sum < 0){
        sum = 0;
      }
    }
    if (ans > 0){
      printf("The maximum winning streak is %d.\n", ans);
    } else {
      printf("Losing streak.\n");
    }
  }
  return 0;
}
