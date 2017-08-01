#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
  int N;
  int A[100][100];
  while(scanf("%d\n", &N) > 0){
    for (int row = 0; row < N; row++){
        for (int column = 0; column < N; column++){
          scanf("%d", &A[row][column]);
          if (row > 0){
            A[row][column] += A[row - 1][column];
          }
          if (column > 0){
            A[row][column] += A[row][column - 1];
          }
          if (row > 0 && column > 0){
            A[row][column] -= A[row - 1][column - 1];
          }
        }
    }
    int maxResult = INT_MIN;
    int sum;
    // Try all possible subarrays
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        for (int k = i; k < N; k++){
          for (int l = j; l < N; l++){
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
