#include "head.h"

/*
typedef struct Flag {		//��߸��� ����� ���� ��,������ �༭ ������� ex) life = 0, sec = -10 �ΰ�� �ð�10�� ���� ���~
	int life;
	int sec;		
	int clear;		//0 == Ŭ������x, 1 == Ŭ������o
	int eyeSight;	
}Flag;
*/


/*	player ����ü �ӽ� ���� �� ���������� �÷��̾� ���� ����.....
typedef struct Player {
	int x;
	int y;
	int life;
	int sec;
	int eyeSight;
	//int clear;
}Player;

Player player;
*/

extern int x, y, mapSize;
extern** map;

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
		x = rand() % ? ;				//���ʿ� x,y���� ������ �ȵǰ� �����ص�����
		y = rand() % ? ;
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

	for (int i = 0; i < ? ; i++)				//3����� ��ġ
	{

		while (1)
		{
			x = rand() % ?;
			y = rand() % ?;
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

	for (int i = 0; i < ? ; i++)				//4����� ��ġ
	{
		while (1)
		{
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

	for (int i = 0; i < ? ; i++)				//5����� ��ġ
	{

		while (1)
		{
			x = rand() % ? ;
			y = rand() % ? ;
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

	for (int i = 0; i < ? ; i++)				//6����� ��ġ
	{

		while (1)
		{
			x = rand() % ? ;
			y = rand() % ? ;
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

	for (int i = 0; i < ? ; i++)				//7����� ��ġ
	{

		while (1)
		{
			x = rand() % ? ;
			y = rand() % ? ;
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

	for (int i = 0; i < ? ; i++)				//8����� ��ġ
	{

		while (1)
		{
			x = rand() % ? ;
			y = rand() % ? ;
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

	/*	����� 2~8�������ۿ�����. �������� �� �Լ����� �Ǵ�����.
	if (a < 2 || a > 8)
		return -1;
	*/
	
	//Flag[index].~~ó�� �� Ȱ��~
}

void judgeMove(int x, int y)
{
	if (x >= 0 && x < mapSize && y >= 0 && y < mapSize)
	{
		if (map[x][y] != WALL)
		{
			X = x;
			Y = y;
		}
		judgeFlag();
	}

	return;
}