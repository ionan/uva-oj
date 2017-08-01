#include <cstdio>
using namespace std;

int main(){
  int b; // route descriptions
  int s; // stops
  int n; // niceness
  scanf("%d\n", &b);
  for (int r = 1; r <= b; r++){
    scanf("%d\n", &s);
    int sum = 0, ans = 0, bestStart = -1, bestEnd = 0, currentStart = 1;
    for (int i = 2; i <= s; i++){
      scanf("%d\n", &n);
      sum += n;
      if (sum > ans || (sum == ans && (i - currentStart) > (bestEnd - bestStart))){
        bestStart = currentStart;
        bestEnd = i;
        ans = sum;
      }
      if (sum < 0){
        currentStart = i;
        sum = 0;
      }
    }
    if (ans > 0){
      printf("The nicest part of route %d is between stops %d and %d\n", r, bestStart, bestEnd);
    } else {
      printf("Route %d has no nice parts\n", r);
    }
  }
  return 0;
}
