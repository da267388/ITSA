#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[1100];
char words[1000][25];
int wordsAmount = 0;

int isInWords(char *word){
    for (int i = 0; i < wordsAmount; i++){
        if (strcmp(word, words[i]) == 0){
            return 1;
        }
    }
    return 0;
}

int main(){
    int i = 0;
    int wordLength;
    while (scanf(" %s", words[i]) != EOF){
        wordLength = strlen(words[i]);
        for (int j = 0; j < wordLength; j++){//tolower
            words[i][j] = tolower(words[i][j]);
        }

        if (!isInWords(words[i])){
            i++;
            wordsAmount++;
        }
    }
    for (int i = 0; i < wordsAmount; i++){
        printf("%s%c", words[i], i + 1 == wordsAmount ? '\n' : ' ');
    }
}
