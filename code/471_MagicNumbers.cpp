#include <cstdio>
#include <cmath>
using namespace std;

bool toggleDigit(int digit, int *used){
  int posToCheck = (1 << digit);
  if ((*used & posToCheck) == posToCheck){
    return false;
  }
  *used |= posToCheck;
  return true;
}

bool toggleDigits(unsigned long number, int *used){
  bool result = true;
  while (number){
    result &= toggleDigit(number % 10, used);
    number /= 10;
  }
  return result;
}

bool uniqueDigits(unsigned long number){
  int temp = 0;
  return toggleDigits(number, &temp);
}

int main(){
  int testCases, used;
  unsigned long n;
  scanf("%d\n", &testCases);
  while (testCases--){
    scanf("%lu\n", &n);
    unsigned long limit = 9876543210L / n;
    for (unsigned long s2 = 1; s2 <= limit; s2++){
      if (uniqueDigits(s2)){
        unsigned long s1 = s2 * n;
        used = 0;
        if (uniqueDigits(s1)){
          printf("%lu / %lu = %lu\n", s1, s2, n);
        }
      }
    }
    if (testCases > 0){
      printf("\n");
    }
  }
  return 0;
}
