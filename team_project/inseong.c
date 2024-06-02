#include "head.h"

extern int X, Y, mapSize, eyesight;
extern int** map;
Flag Flages[9];

int initFlag() {				// 2�� Ż����, 3: life +1, 4: life -1, 5: sec + 10, 6: sec -10, 7: eyeSight +1, 8: eyeSight -1; 
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

	//������ for���� �ٸ� �������� ��ġ, �� �ٸ� ȿ���� ��� ��ġ�Ѵ�. (0�� ��,1�� ��, 2�� Ż����, 3���� ȿ�� ��� ���ʴ��..

	while (1)									//2�����(Ż��) ��ġ
	{
		x = rand() % (mapSize - 1) + 1;				//���ʿ� x,y���� ������ �ȵǰ� �����ص�����
		y = rand() % (mapSize - 1) + 1;
		if (map[x][y] == 0)				//Ż�� ��� ��ġ ������ ���� �־ �������� ex) ���� �߾ӿ��� 50x50�ȿ��� ����� �Ѵ� ��~~
		{
			//map[x][y]�� ��� ��ġ
			map[x][y] = 2;
			break;
		}
		else
		{
			continue;
		}
	}

	for (int i = 0; i < 5; i++)				//3����� ��ġ
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]�� ��� ��ġ
				map[x][y] = 3;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//4����� ��ġ
	{
		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]�� ��� ��ġ
				map[x][y] = 4;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//5����� ��ġ
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]�� ��� ��ġ
				map[x][y] = 5;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//6����� ��ġ
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]�� ��� ��ġ
				map[x][y] = 6;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//7����� ��ġ
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]�� ��� ��ġ
				map[x][y] = 7;
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 0; i < 5; i++)				//8����� ��ġ
	{

		while (1)
		{
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			if (map[x][y] == 0)
			{
				//map[x][y]�� ��� ��ġ
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

	//	����� 2~8�������ۿ�����. �������� �� �Լ����� �Ǵ�����.
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

	//Flag[index].~~ó�� �� Ȱ��~
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
				printf("��");
				continue;
			}
			else
			{
				if (map[temp_y + i][temp_x + j] == 1)
					printf("��");
				else if (map[temp_y + i][temp_x + j] == 0)
					printf("  ");
				else
					printf("��");
			}
		}
		printf("\n");
	}

	return;
}