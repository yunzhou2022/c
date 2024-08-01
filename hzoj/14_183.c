/**
 * @author      : yz
 * @file        : 14_183
 * @created     : Monday Jul 22, 2024 05:02:28 UTC
 */

#include <stdio.h>

long long f(int n){
    if(n<=0)return 0;
    if(n==1)return 1;
    if(n%2==0)return 3*f(n/2)-1;
    return 3*f((n+1)/2)-1;
}
int main(){
   int n;
  scanf("%d", &n);
 printf("%lld\n", f(n)); 

    return 0;
}

