#include <stdio.h>

int main(){
    int hourStart, minStart, hourEnd, minEnd, parkingMin, fee = 0;
    scanf("%d%d%d%d", &hourStart, &minStart, &hourEnd, &minEnd);
    parkingMin = (hourEnd - hourStart) * 60 + minEnd - minStart;
    if (parkingMin > 240){
        fee += (parkingMin - 240) / 30 * 60;
        parkingMin = 240;
    }
    if (parkingMin > 120){
        fee += (parkingMin - 120) / 30 * 40;
        parkingMin = 120;
    }
    fee += parkingMin / 30 * 30;
    printf("%d\n", fee);
}
