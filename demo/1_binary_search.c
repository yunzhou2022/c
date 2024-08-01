/**
 * @author      : yz
 * @file        : 1_binary_search
 * @created     : Wednesday Jul 31, 2024 17:32:23 UTC
 */

#include <stdio.h>
#include <math.h>

typedef  double (*Func_T)(double);

double f1(double x){
    return x*x;
}
double f2(double x){
    return 3*x*x+2*x-5;
}
double f3(double x){
    return pow(1.2, x);
}
double binary_search(Func_T fn, double y){
    double l=0,r=1000,mid;

    while(r-l>1e-5){
        mid = (l+r)/2;
        double val = fn(mid);
        if(val>y){
            r = mid;
        }else{
            l = mid;
        }
    }

    return l;
}

int main(){
    double y;
    while(scanf("%lf", &y)!=EOF){
        double x1 = binary_search(f1, y);
        double x2= binary_search(f2, y);
        double x3= binary_search(f3, y);

        printf("y=%.3lf  f1(%.3lf)=%.3lf\n", x1, x1, f1(x1));
        printf("y=%.3lf  f2(%.3lf)=%.3lf\n", x2, x2, f2(x2));
        printf("y=%.3lf  f3(%.3lf)=%.3lf\n", x3, x3, f3(x3));
    }

    return 0;
}

