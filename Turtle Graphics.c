#include<stdio.h>
#include<stdbool.h>

#define PEN_UP 1
#define PEN_DOWN 2
#define TURN_RIGHT 3
#define TURN_LEFT 4
#define MOVE_FORWARD 5
#define PRINT_ARRAY 6
#define END_OF_DATA 9

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3


int main(){
    int command = 0;
    bool graph[101][101] = {0};
    int height = 0, width = 0;
    int northernmost = 100, westernmost = 100, newNorthernmost, newWesternmost;
    int position[2] = {50, 50};//row, colunm
    bool penStatus = false;//up: false, down:true
    int direction = EAST;
    bool isFirst = true;

    int moveStep = 0;
    int sign = 1;

    do{
        scanf("%d", &command);
        sign = 1;
        switch(command){
            case PEN_UP:
                penStatus = false;
                break;
            case PEN_DOWN:
                penStatus = true;
                break;
            case TURN_RIGHT:
                direction = (direction + 1) % 4;
                break;
            case TURN_LEFT:
                direction = (direction - 1) >= 0 ? direction - 1 : WEST;
                break;
            case MOVE_FORWARD:
                scanf(",%d", &moveStep);
                if (penStatus == false){
                    if(direction == EAST || direction == WEST){
                        if(direction == WEST){
                            sign = -sign;
                        }
                        position[1] += sign * moveStep;
                    }
                    else{
                        if(direction == NORTH){
                            sign = -sign;
                        }
                        position[0] += sign * moveStep;
                    }
                }
                else{
                    if(direction == EAST || direction == WEST){
                        if(direction == WEST){
                            sign = -sign;
                        }
                        northernmost = northernmost > position[0] ? position[0] : northernmost;
                        newWesternmost = westernmost > (position[1] + sign * moveStep) ? position[1] + sign * moveStep : westernmost;
                        newWesternmost = newWesternmost > position[1] ? position[1] : newWesternmost;
                        height = height < (position[0] + 1 - northernmost) ? position[0] + 1 - northernmost : height;
                        for(int step = 0; step < moveStep; step++){
                            graph[position[0]][position[1]] = true;
                            position[1] += sign;
                            graph[position[0]][position[1]] = true;
                            width = width < (position[1] + 1 - newWesternmost) ? position[1] + 1 - newWesternmost : width;
                        }
                        if(isFirst){
                            isFirst = false;
                        }
                        else{
                            width += westernmost - newWesternmost;
                        }
                        westernmost = newWesternmost;
                    }
                    else{
                        if(direction == NORTH){
                            sign = -sign;
                        }
                        westernmost = westernmost > position[1] ? position[1] : westernmost;
                        newNorthernmost = northernmost > (position[0] + sign * moveStep) ? position[0] + sign * moveStep : northernmost;
                        newNorthernmost = newNorthernmost > position[0] ? position[0] : newNorthernmost;
                        //height += northernmost - newNorthernmost;
                        width = width < (position[1] + 1 - westernmost) ? position[1] + 1 - westernmost : width;
                        for(int step = 0; step < moveStep; step++){
                            graph[position[0]][position[1]] = true;//Turtle Graphics
                            position[0] += sign;
                            graph[position[0]][position[1]] = true;
                            height = height < (position[0] + 1 - newNorthernmost) ? position[0] + 1 - newNorthernmost : height;
                        }
                        if(isFirst){
                            isFirst = false;
                        }
                        else{
                            height += northernmost - newNorthernmost;
                        }
                        northernmost = newNorthernmost;
                    }
                }
                break;
            case PRINT_ARRAY:
                //printf("northernmost:%d\nwesternmost:%d\nheight:%d\nwidth:%d\n", northernmost, westernmost, height, width);
                for(int row = 0; row < height; row++){
                    for(int column = 0; column < width; column++){
                        if(graph[northernmost + row][westernmost + column]){
                            printf("*");
                        }
                        else{
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
            case END_OF_DATA:
                break;
            default:
                printf("NO SUCH COMMAND!\n");
        }


    }while(command != END_OF_DATA);

}
