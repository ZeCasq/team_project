/*#include"head.h"
#define SIGHT 3 //�þ� ����
//Map_SIZE�� �̷� ũ��,player X,Y�� �÷��̾� ��ǥ,map[i][j]�� �� �迭 
void displayMazeWithLimitedView() {
    cls; // ȭ�� ����� (Windows)
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