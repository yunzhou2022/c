/**
 * @author      : yz
 * @file        : 02_fseek
 * @created     : Friday Aug 02, 2024 14:38:35 UTC
 */

#include <stdio.h>

const char *filename = "fseek.txt";
int main() {
  FILE *fp = fopen(filename, "w");
  printf("fseek = %ld\n", ftell(fp));
  fprintf(fp, "0123456789");
  printf("fseek = %ld\n", ftell(fp));
  fseek(fp, 2, SEEK_SET);
  printf("fseek = %ld\n", ftell(fp));
  fprintf(fp, "abc");
  fclose(fp);


  FILE*fp2 = fopen(filename, "r");
  fseek(fp2, 5, SEEK_SET);
  int n;
  fscanf(fp2,"%d", &n);
  printf("%d\n", n);
  fclose(fp2);
  return 0;
}
