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
#include "head.h"
extern int X, Y, eyesight, mapSize, ** map;


void printMap()
{
	int temp_x, temp_y;
	int x = 53 - eyesight * 2;
	int y = 15 - eyesight;
	if (X - eyesight < 0)
	{
		temp_x = 0;
	}
	else if (X + eyesight >= mapSize)
	{
		temp_x = mapSize - (2 * eyesight + 1);
	}
	else
	{
		temp_x = X - eyesight;
	}
	if (Y - eyesight < 0)
	{
		temp_y = 0;
	}
	else if (Y + eyesight >= mapSize)
	{
		temp_y = mapSize - (2 * eyesight + 1);
	}
	else
	{
		temp_y = Y - eyesight;
	}
	for (int i = 0; i < eyesight * 2 + 1; i++)
	{
		gotoxy(x, y);
		for (int j = 0; j < eyesight * 2 + 1; j++)
		{
			if (temp_y + i == Y && temp_x + j == X)
			{
				printf("��");
				continue;
			}
			else
			{
				if (map[temp_y + i][temp_x + j] == WALL)
					printf("��");
				else if (map[temp_y + i][temp_x + j] == SPACE)
					printf("  ");
				else if (map[temp_y + i][temp_x + j] == PAST_PATH) {
					SetColor(9);
					printf("��");
					SetColor(15);
				}
				else
					printf("��");
			}
		}
		y++;
	}

	return;
}