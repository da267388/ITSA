#include <stdio.h>
#include <string.h>

int main(){
    char req[1000];
    int length;
    char isPalindrome;
    while(scanf("%s", req) != EOF){
        length = strlen(req);
        isPalindrome = 1;
        for (int i = 0; i < length / 2; i++){
            if (req[i] != req[length - i - 1]){
                printf("NO\n");
                isPalindrome = 0;
                break;
            }
        }
        if (isPalindrome){
            printf("YES\n");
        }
    }
}
