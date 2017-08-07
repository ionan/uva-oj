#include <cstdio>
#include <vector>
using namespace std;

int main(){
  vector<int> v;
  vector<int> lds;
  int val, best = 1, test = 1;
  while (scanf("%d", &val) == 1){
    if (val != -1){
      v.push_back(val);
    } else if (v.size() > 0) {
      lds.push_back(1);
      for (int i = 1; i < v.size(); i++){
        int bestJ = -1;
        for (int j = i - 1; j >= 0; j--){
          if (v[j] >= v[i] && (bestJ == -1 || lds[bestJ] < lds[j])){
            bestJ = j;
          }
        }
        val = bestJ == -1 ? 1 : lds[bestJ] + 1;
        lds.push_back(val);
        if (lds[i] > best){
          best = lds[i];
        }
      }
      if (test > 1){
        printf("\n");
      }
      printf("Test #%d:\n  maximum possible interceptions: %d\n", test++, best);
      v.clear();
      lds.clear();
      best = 1;
    }
  }
  return 0;
}
