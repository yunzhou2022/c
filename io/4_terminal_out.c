/**
 * @author      : yz
 * @file        : 4_terminal_out
 * @created     : Thursday Aug 01, 2024 17:42:40 UTC
 */

#include <stdio.h>

int main(){
   freopen("/dev/pts/4", "w", stdout) ;
   char s[100];
   while((scanf("%[^\n]", s)!=EOF)){
       getchar();
       printf("from tty0: %s\n", s);
   }

    return 0;
}

