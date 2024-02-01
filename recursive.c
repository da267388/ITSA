#include <stdio.h>

int dp[1000] = {0};

int f(int n){
    if (n <= 1){
        return n + 1;
    }
    if (dp[n] != 0){
        return dp[n];
    }
    return (dp[n - 1] = f(n - 1)) + (dp[n / 2] = f(n / 2));
}

int main(){
    int req;

    scanf("%d", &req);
    printf("%d\n", f(req));
    /*for (int i = 0; i < req; i++){
        printf("%d %d\n", i, dp[i]);
    }*/
}
