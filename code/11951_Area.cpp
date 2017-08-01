#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
  int N, M, testCases, testCase = 0;
  long long A[100][100], K;
  scanf("%d", &testCases);
  while(testCase++ < testCases){
    scanf("%d %d %lld", &N, &M, &K);
    for (int row = 0; row < N; row++){
        for (int column = 0; column < M; column++){
          scanf("%lld", &A[row][column]);
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
    int maxArea = 0;
    long long price = LONG_MAX;
    long long sum = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < M; j++){
        for (int k = i; k < N; k++){
          bool budgetExceeded = false;
          for (int l = j; l < M && !budgetExceeded; l++){
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
            int area = (k - i + 1) * (l - j + 1);
            if (sum > K){
              budgetExceeded = true;
            } else if (area > maxArea || (area == maxArea && sum < price)){
              maxArea = area;
              price = sum;
            }
          }
          budgetExceeded = false;
        }
      }
    }
    printf("Case #%d: %d %lld\n", testCase, maxArea, maxArea == 0 ? 0 : price);
  }
  return 0;
}
