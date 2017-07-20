#include <stdio.h>
using namespace std;

int main(){
  int testCases, trash = scanf("%d\n", &testCases);
  int A, B, C;
  while (testCases--){
    trash = scanf("%d %d %d\n", &A, &B, &C);
    bool solved = false;
    int x, y, z;
    for (int x = -100; x <= 100 && !solved; x++){
      for (int y = -100; y <= 100 && !solved; y++){
        if (x != y && x*x + y*y <= C){
          for (int z = -100; z <= 100 && !solved; z++){
            if (x != z && y != z &&
                x + y + z == A &&
                x * y * z == B &&
                x*x + y*y + z*z == C
              ){
              printf("%d %d %d\n", x, y, z);
              solved = true;
            }
          }
        }
      }
    }
    if (!solved){
      printf("No solution.\n");
    }
  }
  return 0;
}
