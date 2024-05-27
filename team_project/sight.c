/*#include"head.h"
#define SIGHT 3 //시야 범위
//Map_SIZE는 미로 크기,player X,Y는 플레이어 좌표,map[i][j]는 맵 배열 
void displayMazeWithLimitedView() {
    cls; // 화면 지우기 (Windows)
    for (int i = 0; i < Map_SIZE; i++) {
        for (int j = 0; j < Map_SIZE; j++) {
            if (abs(playerX - i) <= SIGHT && abs(playerY - j) <= SIGHT) {
                printf("%c ", map[i][j]);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}*/