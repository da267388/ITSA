#include <stdio.h>

int main(){
    int reqNum, realPartA, imaginaryPartA, realPartB, imaginaryPartB, realPartC, imaginaryPartC;
    char operation;
    char req[15];
    scanf("%d", &reqNum);
    for (int i = 0; i < reqNum; i++){
        getchar();
        scanf("%[^\n]", req);
        printf("%s", req);
        sscanf(req, "%c%d%d%d%d", &operation, &realPartA, &imaginaryPartA, &realPartB, &imaginaryPartB);
        switch(operation)
        {
        case '+':
            realPartC = realPartA + realPartB;
            imaginaryPartC = imaginaryPartA + imaginaryPartB;
            break;
        case '-':
            realPartC = realPartA - realPartB;
            imaginaryPartC = imaginaryPartA - imaginaryPartB;
            break;
        case '*':
            realPartC = realPartA * realPartB - imaginaryPartA * imaginaryPartB;
            imaginaryPartC = realPartA * imaginaryPartB + realPartB * imaginaryPartA;
            break;
        }
        printf("%d %d\n", realPartC, imaginaryPartC);
    }
}
