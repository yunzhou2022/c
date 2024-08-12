#include <stdio.h>

int single[] = {
    0, // 0
    3, // One
    3, // Two
    5, // Three
    4, // Four
    4, // Five
    3, // Six
    5, // Seven
    5, // Eight
    4, // Nine
    3, // Ten
    6, // Eleven
    6, // Twelve
    8, // Thirteen
    8, // Fourteen
    7, // Fifteen
    7, // Sixteen
    9, // Seventeen
    8, // Eighteen
    8, // Nineteen

};

int ten[] = {
    0, 0,
    6, // Twenty
    6, // Thirty
    5, // Forty
    5, // Fifty
    5, // Sixty
    7, // Seventy
    6, // Eighty
    6, // Ninety
};

int getLen(int x) {
  if (x < 20)
    return single[x];
  if (x < 100)
    return ten[x / 10] + getLen(x % 10);
  if (x < 1000) {
    if (x % 100 == 0)
      return single[x / 100] + 7;
    return single[x / 100] + 10 + getLen(x % 100);
  }
  return 11;
}
int main() {
  int sum = 0;
  for (int i = 1; i <= 1000; i++) {
    sum += getLen(i);
  }

  printf("%d\n", sum);

  return 0;
}
