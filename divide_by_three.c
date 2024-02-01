#include <stdio.h>

int main(){
    int req, sum;

    while(scanf("%d", &req) != EOF){
        sum = 0;
        for (int i = 3; i <= req; i += 3){
            if (i % 3 == 0){
                sum += i;
            }
        }
        printf("%d\n", sum);
    }
}
