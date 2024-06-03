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
#include "head.h"
extern int X, Y, eyesight, mapSize, ** map;


void printMap()
{
	gotoxy(0, 0);
	int temp_x, temp_y;
	if (X - 5 < 0)
	{
		temp_x = 0;
	}
	else if (X + 5 >= mapSize)
	{
		temp_x = mapSize - 11;
	}
	else
	{
		temp_x = X - 5;
	}
	if (Y - 5 < 0)
	{
		temp_y = 0;
	}
	else if (Y + 5 >= mapSize)
	{
		temp_y = mapSize - 11;
	}
	else
	{
		temp_y = Y - 5;
	}
	for (int i = 0; i < eyesight * 2 + 1; i++)
	{
		for (int j = 0; j < eyesight * 2 + 1; j++)
		{
			if (temp_y + i == Y && temp_x + j == X)
			{
				printf("◇");
				continue;
			}
			else
			{
				if (map[temp_y + i][temp_x + j] == WALL)
					printf("■");
				else if (map[temp_y + i][temp_x + j] == SPACE)
					printf("  ");
				else
					printf("□");
			}
		}
		printf("\n");
	}

	return;
}