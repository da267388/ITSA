#include <stdio.h>

int matrix[100][100];

int main(){
    int row, col;

    while(scanf("%d%d", &row, &col) != EOF){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                scanf("%d", &matrix[i][j]);
            }
        }
        for (int i = 0; i < col; i++){
            for (int j = 0; j < row; j++){
                printf("%d%c", matrix[j][i], j + 1 >= row ? '\n' : ' ');
            }
        }
    }
}
