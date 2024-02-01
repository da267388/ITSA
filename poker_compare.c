#include <stdio.h>
#include <string.h>

typedef struct card{
    char suit;
    int number;
}
Card;

char reqLine[5000];
char reqWord[6];
Card cards[1000];

void swap(Card *a, Card *b){
    char tempSuit = a->suit;
    a->suit = b->suit;
    b->suit = tempSuit;
    int tempNum = a->number;
    a->number = b->number;
    b->number = tempNum;
}


void sortPoker(int amount){
    for (int i = 0; i < amount - 1; i++){
        for (int j = 0; j < amount - i - 1; j++){
            if (cards[j].suit < cards[j + 1].suit){//compare suit
                swap(&(cards[j]), &(cards[j + 1]));
            }
            else if (cards[j].suit == cards[j + 1].suit && cards[j].number < cards[j + 1].number){
                swap(&(cards[j]), &(cards[j + 1]));
            }
        }
    }
}

int main(){
    int reqNum, cardCounter, offset;
    scanf("%d", &reqNum);
    for (int i = 0; i < reqNum; i++){
        cardCounter = 0;
        offset = 0;
        scanf(" %[^\n]", reqLine);
        //printf("%s\n", reqLine);
        while(sscanf(reqLine + offset, "%s", reqWord) != EOF){
            sscanf(reqWord, "%c%d", &cards[cardCounter].suit, &cards[cardCounter].number);
            offset += strlen(reqWord) + ((cardCounter >= 1) ? 1 : 0);
            //printf("%c %d\n", cards[cardCounter].suit, cards[cardCounter].number);
            cardCounter++;
        }
        sortPoker(cardCounter);
        for (int j = 0; j < cardCounter; j++){
            printf("%c%d%c", cards[j].suit, cards[j].number, (j + 1 == cardCounter) ? '\n' : ' ');
        }
    }
}
