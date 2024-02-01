#include <stdio.h>

int main(){
    double miles, kilemeters;
    while (scanf("%lf", &miles) != EOF){
        kilemeters = miles * 1.6;
        printf("%.1lf\n", kilemeters);
    }
}
