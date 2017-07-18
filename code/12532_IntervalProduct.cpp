#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;

#define LSOne(x) (x & (-x))
#define ZERO 0
#define NEGATIVE -1

// Use two binary indexed trees:
// One will keep the frequency of zeroes within a range and the other the frequency of negatives.
// With this data we can easily get the sign of the product for a given range:
//  - if there is at least one zero within the range, the product will be zero
//  - if there is an odd number of negative values within the range, the result will be negative
//  - if none of the above holds true, the result will be positive
vector<int> bitZero, bitNegative;

void bitAdjust(int type, int index, int value){
  for (; index < bitZero.size(); index += LSOne(index)){
    if (type == ZERO) bitZero[index] += value;
    else bitNegative[index] += value;
  }
}

int bitRangeSumQuery(int type, int upper){
  int result = 0;
  for (; upper; upper -= LSOne(upper)){
    if (type == ZERO) result += bitZero[upper];
    else result += bitNegative[upper];
  }
  return result;
}

int bitRangeSumQuery(int type, int lower, int upper){
  int segment1 = bitRangeSumQuery(type, upper);
  int segment2 = lower == 1 ? 0 : bitRangeSumQuery(type, lower - 1);
  return segment1 - segment2;
}

int main(){
  int elems, rounds, trash, a, b;
  char action;
  vector<int> items;
  while ((trash = scanf("%d %d\n", &elems, &rounds)) == 2){
    // Initialize vectors
    bitZero.assign(elems + 1, 0);
    bitNegative.assign(elems + 1, 0);
    items.assign(elems + 1, 0);
    // Build the binary indexed trees
    for (int i = 1; i <= elems; i++){
      trash = scanf("%d", &a);
      if (a == 0){
        bitAdjust(ZERO, i, 1);
      } else if (a < 0){
        bitAdjust(NEGATIVE, i, 1);
      }
      items[i] = a;
    }
    trash = scanf("\n");
    for (int i = 0; i < rounds; i++){
      trash = scanf("%c %d %d\n", &action, &a, &b);
      if (action == 'C'){
        if (b == 0){
          if (items[a] != 0) bitAdjust(ZERO, a, 1);
          if (items[a] < 0) bitAdjust(NEGATIVE, a, -1);
        } else if (b < 0){
          if (items[a] >= 0) bitAdjust(NEGATIVE, a, 1);
          if (items[a] == 0) bitAdjust(ZERO, a, -1);
        } else {
          if (items[a] == 0) bitAdjust(ZERO, a, -1);
          if (items[a] < 0) bitAdjust(NEGATIVE, a, -1);
        }
        items[a] = b;
      } else if (action == 'P'){
        int zeroes = bitRangeSumQuery(ZERO, a, b);
        if (zeroes > 0){
          printf("0");
        } else {
          int negatives = bitRangeSumQuery(NEGATIVE, a, b);
          if (negatives % 2 == 1){
            printf("-");
          } else {
            printf("+");
          }
        }
      }
    }
    printf("\n");
    bitZero.clear();
    bitNegative.clear();
    items.clear();
  }
  return 0;
}
