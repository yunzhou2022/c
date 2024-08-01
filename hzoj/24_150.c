/**
 * @author      : yz
 * @file        : 24_150
 * @created     : Wednesday Jul 31, 2024 05:12:40 UTC
 */

#include <stdio.h>

int arr[205][205];

int main(){
   int m,n;
   scanf("%d%d", &n,&m);
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           int x;
           scanf("%d", &x);
           arr[j][n-1-i] = x;
       }
   }

   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           if(j) printf(" ");
           printf("%d", arr[i][j]);
       }
       printf("\n");
   }

    return 0;
}

