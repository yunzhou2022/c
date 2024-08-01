/**
 * @author      : yz
 * @file        : 18_144
 * @created     : Tuesday Jul 30, 2024 17:06:51 UTC
 */

#include <stdio.h>
#include<string.h>

int main(){
   char s[105];
  scanf("%s", s);
  int count = 0;
  for(int i=0;s[i];i++){
count += (s[i] =='A');
  } 

  printf("%d\n", count);
    return 0;
}

