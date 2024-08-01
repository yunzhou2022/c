/**
 * @author      : yz
 * @file        : 26
 * @created     : Wednesday Jul 31, 2024 14:35:27 UTC
 */

#include <stdio.h>

int main(){
   int a,b,c,d;
   scanf("%d.%d.%d.%d",&a,&b,&c,&d);
   unsigned int n;
   char *p = (char *)&n;
   p[0] = d;
   p[1] = c;
   p[2] = b;
   p[3] = a;
   printf("%u\n", n);

    return 0;
}

