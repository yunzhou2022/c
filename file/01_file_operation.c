/**
 * @author      : yz
 * @file        : 01_file_operation
 * @created     : Friday Aug 02, 2024 04:56:43 UTC
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char * filename = "test.txt";

void clearfile(){
    FILE * fp = fopen(filename, "w");
    fclose(fp);
}

int output_to_file(int *arr, int n){
    FILE *fp = fopen(filename, "a");
    int i=0;
    if(fp==NULL){
        return 0;
    }
    for(;i<n;i++){
        fprintf(fp,"%d", arr[i]);
    }
    fclose(fp);
    return i;
}

void output_arr(int *arr, int n){
    for(int i=0;i<n;i++) {
        printf("%d",arr[i]);
    }
}

int main() {
  srand(time(0));
  int n;
  int arr[1000];
  for (n = 0; n < 10; n++) {
    arr[n] = rand() % 100;
  }
  output_arr(arr, n);
  output_to_file(arr, n);
  clearfile();
  return 0;
}
