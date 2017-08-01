#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
  int N, M, testCase = 0;
  int A[1000][1000];
  while(scanf("%d %d\n", &N, &M) > 0){
    if (testCase > 0) printf("\n");
    testCase++;
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
    int sum;
    int totalSum = 0;
    for (int i = 0; i <= N - M; i++){
      for (int j = 0; j <= N - M; j++){
        int k = i + M - 1;
        int l = j + M - 1;
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
        totalSum += sum;
        printf("%d\n", sum);
      }
    }
    printf("%d\n", totalSum);
  }
  return 0;
}
