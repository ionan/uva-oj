#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_OBJECTS 1001
#define MAX_WEIGHT 40
#define MAX_PEOPLE

int memoTable[MAX_OBJECTS][MAX_WEIGHT], prices[MAX_OBJECTS], weights[MAX_OBJECTS], objects;

int value(int index, int weight) {
  if (index == objects || weight == 0) return 0;
  if (memoTable[index][weight] != -1) return memoTable[index][weight];
  if (weights[index] > weight){
    // Weight of current object is bigger than weight left
    // Skip this element
    int val = value(index + 1, weight);
    memoTable[index][weight] = val;
    return val;
  }
  int val = max(value(index + 1, weight), prices[index] + value(index + 1, weight - weights[index]));
  memoTable[index][weight] = val;
  return val;
}

int main() {
  int testCases, ans, people, maxWeight;
  scanf("%d", &testCases);
  while (testCases--) {
    memset(memoTable, -1, sizeof memoTable);

    scanf("%d", &objects);
    for (int i = 0; i < objects; i++){
      scanf("%d %d", &prices[i], &weights[i]);
    }

    ans = 0;
    scanf("%d", &people);
    while (people--) {
      scanf("%d", &maxWeight);
      ans += value(0, maxWeight);
    }

    printf("%d\n", ans);
  }

  return 0;
}
