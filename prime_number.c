#include <stdio.h>
#include <stdbool.h>

int main(){
    int req;
    bool isPrime;
    while(scanf("%d", &req) != EOF){
        isPrime = true;
        if (req == 2){
            printf("YES\n");
            continue;
        }
        if (req % 2 == 0){
            printf("NO\n");
            continue;
        }
        for (int i = 3; i * i <= req; i += 2){
            if (req % i == 0){
                isPrime = false;
                break;
            }
        }
        printf("%s\n", isPrime ? "YES" : "NO");
    }
}
