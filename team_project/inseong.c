#include "head.h"

extern int X, Y, mapSize, eyesight;
extern int** map;
Flag Flages[9];

int initFlag() {				// 2는 탈출깃발, 3: life +1, 4: life -1, 5: sec + 10, 6: sec -10, 7: eyeSight +1, 8: eyeSight -1; 
	Flages[2].life = 0;
	Flages[2].sec = 0;
	Flages[2].clear = 1;
	Flages[2].eyeSight = 0;

	Flages[3].life = 1;
	Flages[3].sec = 0;
	Flages[3].clear = 0;
	Flages[3].eyeSight = 0;

	Flages[4].life = -1;
	Flages[4].sec = 0;
	Flages[4].clear = 0;
	Flages[4].eyeSight = 0;

	Flages[5].life = 0;
	Flages[5].sec = 10;
	Flages[5].clear = 0;
	Flages[5].eyeSight = 0;

	Flages[6].life = 0;
	Flages[6].sec = -10;
	Flages[6].clear = 0;
	Flages[6].eyeSight = 0;

	Flages[7].life = 0;
	Flages[7].sec = 0;
	Flages[7].clear = 0;
	Flages[7].eyeSight = 1;

	Flages[8].life = 0;
	Flages[8].sec = 0;
	Flages[8].clear = 0;
	Flages[8].eyeSight = -1;
}

int makeFlag()
{
	int x, y;

	//각각의 for문은 다른 정수값을 배치, 즉 다른 효과의 깃발 배치한다. (0은 길,1은 벽, 2는 탈출깃발, 3부터 효과 깃발 차례대로..

	while (1)									//2번깃발(탈출) 배치
	{
		x = rand() % (mapSize - 1) + 1;				//애초에 x,y값을 벽포함 안되게 설정해도ㄱㅊ
		y = rand() % (mapSize - 1) + 1;
		if (map[x][y] == 0)				//탈출 깃발 배치 조건은 좀더 있어도 괜찮을듯 ex) 맵의 중앙에서 50x50안에는 없어야 한다 등~~
		{
			//map[x][y]에 깃발 배치
			map[x][y] = 2;
			break;
		}
		else
		{
			continue;
		}
	}

	for (int i = 0; i < 5; i++)				//3번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 3;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//4번깃발 배치
	{
		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 4;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//5번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 5;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//6번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 6;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//7번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 7;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//8번깃발 배치
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]에 깃발 배치
				map[x][y] = 8;
				break;
			}
			else
			{
				continue;
			}
		}
	}
}


void judgeFlag()
{
	int temp = map[X][Y];

	//	깃발은 2~8번까지밖에없다. 이조건은 이 함수에서 판단하자.
	if (temp < 2 || temp > 8)
	{
		return 0;
	}
	else
	{
		if (map[X][Y] == 2)
		{
			return 1;
		}
		else
		{

		}
	}

	//Flag[index].~~처럼 값 활용~
}

void judgeMove(int x, int y)
{
	if (x >= 0 && x < mapSize && y >= 0 && y < mapSize)
	{
		if (map[y][x] != WALL)
		{
			X = x;
			Y = y;
		}
		judgeFlag();
	}

	return;
}

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
				if (map[temp_y + i][temp_x + j] == 1)
					printf("■");
				else if (map[temp_y + i][temp_x + j] == 0)
					printf("  ");
				else
					printf("□");
			}
		}
		printf("\n");
	}

	return;
}