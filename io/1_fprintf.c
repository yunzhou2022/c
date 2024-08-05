/**
 * @author      : yz
 * @file        : 1_fprintf
 * @created     : Thursday Aug 01, 2024 17:12:57 UTC
 */

#include <stdio.h>

int main(){
   fprintf(stdout, "hello world\n");
   int n;
   fscanf(stdin, "%d", &n);
   fprintf(stderr, "%d\n", n);
    return 0;
}

