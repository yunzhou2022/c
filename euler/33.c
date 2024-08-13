#include <stdio.h>

int check(int a, int b, int c, int d, int i, int j) {
  return a == c && i * d == b * j;
}

int isValid(int i, int j) {
  int a = i / 10;
  int b = i % 10;

  int c = j / 10;
  int d = j % 10;

  if (!b || !d)
    return 0;

  int flag = 0;
  flag = flag || check(a, b, c, d, i, j);
  flag = flag || check(a, b, d, c, i, j);
  flag = flag || check(b, a, c, d, i, j);
  flag = flag || check(b, a, d, c, i, j);

  return flag;
}

int gcb(int a, int b) {
  if (b == 0)
    return a;
  return gcb(b, a % b);
}

int main() {
  int fen_zi[4];
  int fen_mu[4];
  int len = 0;

  for (int i = 10; i < 99; i++) {
    for (int j = i + 1; j <= 99; j++) {
      if (!isValid(i, j))
        continue;
      printf("%d / %d\n", i, j);
      fen_zi[len] = i;
      fen_mu[len] = j;
      len++;
    }
  }

  int final_fenzi = 1;
  int final_fenmu = 1;
  for (int i = 0; i < 4; i++) {
    final_fenzi *= fen_zi[i];
    final_fenmu *= fen_mu[i];
  }

  int zui_da_gong_yue_shu = gcb(final_fenzi, final_fenmu);
  int res = final_fenmu / zui_da_gong_yue_shu;
  printf("%d\n", res);
  return 0;
}
