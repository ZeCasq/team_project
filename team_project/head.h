#pragma once
#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
#include <time.h>
#define pause system("pause > nul") //���α׷� ������ �ߴ� ���� ����
#define cls system("cls") //ȭ�� �ʱ�ȭ �Լ� 
#define delay Sleep(500) //����
#define full_time 300 //���� ���� �ð�

void SetColor(int color); // �� ����
void CursorView(char show); //Ŀ�� ���� ���� ����
void gotoxy(int x, int y);  // Ŀ�� ��ġ �̵�
void mainPtr(void); //����â
void game(void); //���� �������� ����
int level(void); //�ܰ� â
void GameOver(void); // ���� ���� â


//�ð� ���� �κ� ����
time_t Start_time; //���� ���� �ð�
time_t Stop_time; //�Ͻ����� �ð�
time_t resta_time; //���� �Ͻ����� �� ����� �ð�