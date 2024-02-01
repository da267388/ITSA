#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char req[5000];
    int table[26] = {0};
    int lenght, wordCounter = 1;
    scanf("%[^\n]", req);
    lenght = strlen(req);
    for (int i = 0; i < lenght; i++){
        req[i] = tolower(req[i]);
        if (req[i] <= 'z' && req[i] >= 'a'){
            table[req[i] - 97]++;
        }
        else if (req[i] == ' ') wordCounter++;
    }
    printf("%d\n", wordCounter);
    for (int i = 0; i < 26; i++){
        if (table[i] != 0)
            printf("%c : %d\n", i + 97, table[i]);
    }
}
