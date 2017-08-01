#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX_N 100000

int main(){
  int i = -1, lis = 0, lis_end = -1;
  int A[MAX_N], // Store values (to be able to reconstruct the solution)
      L[MAX_N], // Holds the last element of the LIS with length l (l being the index in the array)
      L_id[MAX_N], // Holds the index of the last element in LIS with length l
      P[MAX_N]; // Index of previous element in LIS
  while (scanf("%d", &A[++i]) == 1){
    int pos = lower_bound(L, L + lis, A[i]) - L;
    L[pos] = A[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if (pos + 1 > lis) {
      lis = pos + 1;
      lis_end = i;
    } else if (pos + 1 == lis){
      lis_end = i;
    }
  }
  stack<int> s;
  while (lis_end > -1){
    s.push(A[lis_end]);
    lis_end = P[lis_end];
  }
  printf("%d\n-\n", lis);
  while (!s.empty()){
    printf("%d\n", s.top());
    s.pop();
  }
  return 0;
}
