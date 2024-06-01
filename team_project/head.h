#pragma once
#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include <malloc.h>
#include <locale.h>
#define START 3
#define FINISH 4
#define PLAYER 20
#define WALL 1
#define SPACE 0
#define RMS 25
#define pause system("pause > nul") //프로그램 종료후 뜨는 문구 제거
#define cls system("cls") //화면 초기화 함수 
#define delay Sleep(500) //지연
#define full_time 300 //게임 제한 시간

void SetColor(int color); // 색 설정
void CursorView(char show); //커서 존재 유무 조정
void gotoxy(int x, int y);  // 커서 위치 이동
void mainPtr(void); //시작창
void game(void); //게임 전반적인 구성
void level(void); //단계 창
void GameOver(void); // 게임 오버 창
//void displayMazeWithLimitedView();
void GamePlay(void);
int main(void);
void setMap(void);
int** RollingArray(int MapArr[RMS][RMS], int num, int block);
int initFlag();
int makeFlag();
void judgeFlag(void);
void judgeMove(int x, int y);


typedef struct Flag {		//깃발마다 멤버의 값을 음,양으로 줘서 계산하자 ex) life = 0, sec = -10 인경우 시간10초 감소 깃발~
	int life;
	int sec;
	int clear;		//0 == 클리어깃발x, 1 == 클리어깃발o
	int eyeSight;
}Flag;

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

//시간 제약 부분 변수
time_t Start_time; //게임 시작 시간
time_t Stop_time; //일시정지 시간

int lev;
