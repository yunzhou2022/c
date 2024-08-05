/**
 * @author      : yz
 * @file        : fwrite_fread
 * @created     : Saturday Aug 03, 2024 02:38:31 UTC
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 10
#define filename "data.dat"

void output(int *arr){
    for(int i=0;i<MAX_N;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() { 
    int arr[MAX_N];

    srand(time(0));
    for(int i=0;i<MAX_N;i++){
        arr[i] = rand()%(int)1e5;
    }

    output(arr);
    FILE *fp = fopen(filename, "wb");
    fwrite(arr, sizeof(int), MAX_N, fp);
    fclose(fp);


    int arr2[MAX_N];
    FILE *fp2 = fopen(filename, "rb");
    fread(arr2, sizeof(int), MAX_N, fp2);
    output(arr2);
    fclose(fp2);
    
    return 0;
}
