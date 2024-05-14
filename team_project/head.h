#pragma once
#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
#include <time.h>
#define pause system("pause > nul") //프로그램 종료후 뜨는 문구 제거
#define cls system("cls") //화면 초기화 함수 
#define delay Sleep(500) //지연
#define full_time 300 //게임 제한 시간

void SetColor(int color); // 색 설정
void CursorView(char show); //커서 존재 유무 조정
void gotoxy(int x, int y);  // 커서 위치 이동
void mainPtr(void); //시작창
void game(void); //게임 전반적인 구성
int level(void); //단계 창
void GameOver(void); // 게임 오버 창


//시간 제약 부분 변수
time_t Start_time; //게임 시작 시간
time_t Stop_time; //일시정지 시간
time_t resta_time; //게임 일시정지 후 재시작 시간