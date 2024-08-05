/**
 * @author      : yz
 * @file        : 2_freopen
 * @created     : Thursday Aug 01, 2024 17:31:17 UTC
 */

#include <stdio.h>

int main(){
   freopen("output.txt", "w", stdout);
   freopen("input.txt", "r", stdin);
   // freopen("err.txt", "w", stderr);
   char s[1000];
   while((scanf("%[^\n]", s))!=EOF){
       getchar();
       printf("%s | hello world!\n", s);
   }

    return 0;
}

