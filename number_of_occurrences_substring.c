#include <stdio.h>
#include <string.h>

int fail[1000];
char string[5000];
char substring[1000];

void buildFail(int lenght){
    int temp = -1;
    fail[0] = -1;
    for (int i = 1; i < lenght; i++){
        temp = fail[i - 1];
        while(substring[temp + 1] != substring[i] && temp >= 0){
            temp = fail[temp];
        }
        if (substring[temp + 1] == substring[i]){
            fail[i] = temp + 1;
        }
        else{
            fail[i] = -1;
        }
    }
}

int main(){
    int stringLength;
    int substringLenght;
    int counter = 0;
    scanf(" %s", substring);
    scanf(" %s", string);
    stringLength = strlen(string);
    substringLenght = strlen(substring);
    buildFail(substringLenght);
    int i = 0, j = 0;
    while (i < stringLength && j < substringLenght){
        if (string[i] == substring[j]){
            if (j + 1 == substringLenght){
                counter++;
                if (j == 0)
                    i++;
                else
                    j = fail[j - 1] + 1;
            }
            else{
                i++;
                j++;
            }
        }
        else if (j == 0){
            i++;
        }
        else{
            j = fail[j - 1] + 1;
        }
    }
    printf("%d\n", counter);
}
