/**
 * @author      : yz
 * @file        : 4_max
 * @created     : Thursday Aug 01, 2024 04:41:58 UTC
 */

#include <stdio.h>

#define P(a){ \
    printf("%s = %d\n", #a, a); \
}

#define MAX(a,b) ({ \
    int _a = (a); \
    int _b = (b); \
    _a>_b?_a:_b; \
})

int main(){
   P(MAX(1,2));

    return 0;
}

