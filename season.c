#include <stdio.h>

int main(){
    int month;

    while(scanf("%d", &month) != EOF){
        switch (month)
        {
        case 3:
        case 4:
        case 5:
            printf("Spring\n");
            break;
        case 6:
        case 7:
        case 8:
            printf("Summer\n");
            break;
        case 9:
        case 10:
        case 11:
            printf("Autumn\n");
            break;
        case 12:
        case 1:
        case 2:
            printf("Winter\n");
            break;
        default:
            return 1;
        }
    }
    return 0;
}
