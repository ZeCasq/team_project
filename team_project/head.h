#pragma once
#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
#include <time.h>
#define pause system("pause > nul") //프로그램 종료후 뜨는 문구 제거
#define cls system("cls") //화면 초기화 함수 
#define x1  20
#define x2  47
#define x3  75


void SetColor(int color); // 색 설정
void CursorView(char show); //커서 존재 유무 조정
void gotoxy(int x, int y);  // 커서 위치 이동
void mainPtr(void); //시작창
void game(void); //게임 전반적인 구성
int level(void);

clock_t T;
clock_t STime;
clock_t ETime;
clock_t StartTime; //게임시작 시각 
clock_t ThisTime; //현재시각 저장변수