#include <cstdio>
#include <climits>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define MIN_VALUE -25*25

int main(){
  int testCases, row, N;
  string line;
  int A[25][25];
  scanf("%d\n\n", &testCases);
  while(testCases--){
    cin >> line;
    N = line.length();
    row = 0;
    do {
      for (int column = 0; column < N; column++){
        if (line[column] == '1'){
          A[row][column] = 1;
        } else {
          A[row][column] = MIN_VALUE;
        }
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
      row++;
      if (row < N)
        cin >> line;
    } while (row < N);
    int maxResult = 0;
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
    if (testCases > 0) printf("\n");
  }
  return 0;
}
