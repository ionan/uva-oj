#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<pair<int, int>> blocks;
  vector<int> lds;
  int val, l, m, best = 1, test = 1;
  while (scanf("%d", &val) == 1 && val != 0){
    for (int i = 0; i < val; i++){
      scanf("%d %d", &l, &m);
      blocks.push_back(make_pair(l, m));
    }
    sort(blocks.begin(), blocks.end());

    lds.push_back(1);
    for (int i = 1; i < blocks.size(); i++){
      int bestJ = -1;
      for (int j = i - 1; j >= 0; j--){
        if (blocks[j].first <= blocks[i].first &&
            blocks[j].second <= blocks[i].second &&
            (bestJ == -1 || lds[bestJ] < lds[j])){
          bestJ = j;
        }
      }
      lds.push_back(bestJ == -1 ? 1 : lds[bestJ] + 1);
      if (lds[i] > best){
        best = lds[i];
      }
    }
    printf("%d\n", best);
    blocks.clear();
    lds.clear();
    best = 1;
  }
  printf("*\n");
  return 0;
}
