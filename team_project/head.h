#pragma once
#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#include <malloc.h>
#include <locale.h>
#include<stdbool.h>
#pragma comment(lib, "winmm.lib")

#define START 3
#define FINISH 4
#define PLAYER 20
#define PAST_PATH 30
#define WALL 1
#define SPACE 0
#define RMS 25
#define pause system("pause > nul") //���α׷� ������ �ߴ� ���� ����
#define cls system("cls") //ȭ�� �ʱ�ȭ �Լ� 
#define delay Sleep(500) //����
#define full_time 3 //���� ���� �ð�
void claer(void);
void SetColor(int color); // �� ����
void CursorView(char show); //Ŀ�� ���� ���� ����
void gotoxy(int x, int y);  // Ŀ�� ��ġ �̵�
void mainPtr(void); //����â
void level(void); //�ܰ� â
void GameOver(void); // ���� ���� â
void GamePlay(void);
int initFlag();
int makeFlag();
void judgeMove(int x, int y);
void printMap();
void pause_item(time_t* );
void itemtime(time_t* );
void explain(void);
void Past_path(int** n, int X, int Y);
void bs(void);
void bss(void);
void cl(void);
void ov(void);
void tp(void);
void fl(void);
//void displayMazeWithLimitedView();


typedef struct Flag {		//��߸��� ����� ���� ��,������ �༭ ������� ex) life = 0, sec = -10 �ΰ�� �ð�10�� ���� ���~
	int life;
	int sec;
	int clear;		//0 == Ŭ������x, 1 == Ŭ������o
	int eyeSight;
}Flag;

struct condition {
	time_t sight_p;
	time_t sight_m;
	time_t mushroom;
};


/*
typedef struct Player {
	int x;
	int y;
	int life;
	int sec;
	int eyeSight;
	//int clear;
}Player;
*/

//�ð� ���� �κ� ����
time_t Start_time; //���� ���� �ð�
time_t Stop_time; //�Ͻ����� �ð�

int lev;				//1 == ����, 2 ==... 3==...
int bomb_num;
time_t a;