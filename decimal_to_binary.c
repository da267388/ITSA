#include <stdio.h>
#include <stdbool.h>

//0 = 00000000
//-1 = 11111111

int main(){
    int decimal;
    char binary[9];
    bool postive = false;
    int carry;
    binary[8] = '\0';
    while(scanf("%d", &decimal) != EOF){
        carry = 64;
        if (decimal >= 0){
            postive = true;
            binary[0] = '0';
        }
        else{
            postive = false;
            decimal = -1 * decimal - 1;
            binary[0] = '1';
        }

        for (int i = 1; i < 8; i++){
            if (postive){
                binary[i] = decimal / carry ? '1' : '0';
            }
            else{
                binary[i] = decimal / carry ? '0' : '1';
            }
            decimal = decimal % carry;
            carry /= 2;
        }
        printf("%s\n", binary);
    }
}
