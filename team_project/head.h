#pragma once
#include <stdio.h>
#include <windows.h>
#include <stralign.h>
#include <stdlib.h>
#define pause system("pause > nul") //���α׷� ������ �ߴ� ���� ����
#define cls system("cls") //ȭ�� �ʱ�ȭ �Լ� 
#define x1  20
#define x2  47
#define x3  75


void SetColor(int color); // �� ����
void CursorView(char show); //Ŀ�� ���� ���� ����
void gotoxy(int x, int y);  // Ŀ�� ��ġ �̵�
void mainPtr(void); //����â
void game(void); //���� �������� ����