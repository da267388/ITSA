#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int numA, numB, temp;
    scanf("%d%d", &numA, &numB);
    if (numB > numA){
        swap(&numA, &numB);
    }
    while(numA % numB != 0){
        numA = numA - numB;
        if (numB > numA){
            swap(&numA, &numB);
        }
    }
    printf("%d\n", numB);
}
