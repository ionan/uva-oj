#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
  int testCases, N;
  scanf("%d", &testCases);
  int A[150][150];
  while(testCases--){
    scanf("%d", &N);
    for (int row = 0; row < N; row++){
        for (int column = 0; column < N; column++){
          scanf("%d", &A[row][column]);
          A[row][column + N] = A[row + N][column] = A[row + N][column + N] = A[row][column];
        }
    }
    for (int row = 0; row < 2 * N; row++){
        for (int column = 0; column < 2 * N; column++){
          int sum = A[row][column];
          if (row > 0){
            sum += A[row - 1][column];
          }
          if (column > 0){
            sum += A[row][column - 1];
          }
          if (row > 0 && column > 0){
            sum -= A[row - 1][column - 1];
          }
          A[row][column] = sum;
        }
    }
    int maxResult = INT_MIN;
    int sum;
    for (int i = 0; i < 2 * N; i++){
      for (int j = 0; j < 2 * N; j++){
        for (int k = i; k - i < N && k < 2 * N; k++){
          for (int l = j; l - j < N && l < 2 * N; l++){
            sum = A[k][l];
            if (i > 0){
              sum -= A[i - 1][l];
            }
            if (j > 0){
              sum -= A[k][j - 1];
            }
            if (i > 0 && j > 0){
              sum += A[i - 1][j - 1];
            }
            if (sum >= maxResult){
              maxResult = sum;
            }
          }
        }
      }
    }
    printf("%d\n", maxResult);
  }
  return 0;
}
