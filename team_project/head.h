#pragma once
#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
#include <time.h>
#define pause system("pause > nul") //���α׷� ������ �ߴ� ���� ����
#define cls system("cls") //ȭ�� �ʱ�ȭ �Լ� 
#define delay Sleep(500) //����
#define x1  20
#define x2  47
#define x3  75
#define full_time 300 //���� ���� �ð�

void SetColor(int color); // �� ����
void CursorView(char show); //Ŀ�� ���� ���� ����
void gotoxy(int x, int y);  // Ŀ�� ��ġ �̵�
void mainPtr(void); //����â
void game(void); //���� �������� ����
int level(void);
void Time(void);

time_t Sta_time;
time_t Stop_time;
time_t resta_time;