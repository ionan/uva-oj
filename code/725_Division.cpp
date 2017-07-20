#include <stdio.h>

using namespace std;

void toggleDigit(int digit, int *used){
  *used |= 1 << digit;
}

void toggleDigits(int number, int *used){
  while (number){
    toggleDigit(number % 10, used);
    number /= 10;
  }
}

bool zeroToNDigitsUsed(int used, int n){
  return used == (1 << (n + 1)) - 1;
}

int main(){
  int n, rounds = 0;
  while (scanf("%d\n", &n) == 1 && n != 0){
    if (rounds > 0){
      printf("\n");
    }
    rounds++;
    int upperLimit = 98765 / n;
    int solutions = 0;
    for (int fghij = 1234; fghij <= upperLimit; fghij++){
      int abcde = fghij * n;
      int used = 0, temp;
      if (fghij < 10000) toggleDigit(0, &used);
      toggleDigits(abcde, &used);
      toggleDigits(fghij, &used);
      if (zeroToNDigitsUsed(used, 9)){
        printf("%05d / %05d = %d\n", abcde, fghij, n);
        solutions++;
      }
    }
    if (solutions == 0){
      printf("There are no solutions for %d.\n", n);
    }
  }
  return 0;
}
