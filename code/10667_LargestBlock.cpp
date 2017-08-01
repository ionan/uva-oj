#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
  int blocks, size, testCases;
  int A[101][101];
  scanf("%d", &testCases);
  while(testCases--){
    scanf("%d", &size);
    scanf("%d", &blocks);
    int r1 = 1, c1 = 1, r2 = size, c2 = size, val = 0;
    do {
      for (int row = r1; row <= r2; row++){
          for (int column = c1; column <= c2; column++){
            A[row][column] = val;
          }
      }
      val = 1;
      if (blocks >= 1)
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    } while (blocks--);

    for (int row = 1; row <= size; row++){
      for (int column = 1; column <= size; column++){
        if (row > 1){
          A[row][column] += A[row - 1][column];
        }
        if (column > 1){
          A[row][column] += A[row][column - 1];
        }
        if (row > 1 && column > 1){
          A[row][column] -= A[row - 1][column - 1];
        }
      }
    }

    int maxResult = 0;
    int sum;
    int bi, bj, bk, bl;
    for (int i = 1; i <= size; i++){
      for (int j = 1; j <= size; j++){
        for (int k = i; k <= size; k++){
          for (int l = j; l <= size; l++){
            sum = A[k][l];
            if (i > 1){
              sum -= A[i - 1][l];
            }
            if (j > 1){
              sum -= A[k][j - 1];
            }
            if (i > 1 && j > 1){
              sum += A[i - 1][j - 1];
            }
            if (sum == 0){
              int area = (k - i + 1) * (l - j + 1);
              maxResult = max(maxResult, area);
            }
          }
        }
      }
    }
    printf("%d\n", maxResult);
  }
  return 0;
}
