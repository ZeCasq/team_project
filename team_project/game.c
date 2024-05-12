#include "head.h"


void draw(void);
void con_txt(void);
//기본적인 움직임 구현 툴
void game(void){
	draw();
	int x = 2, y = 2, ch;
	

	while (1) {
		//esc 눌러서 일시정지
		if (GetAsyncKeyState(VK_ESCAPE)) {
			menu();
			cls;
			draw();
		}
		//게임 툴
		gotoxy(x, y);
		printf("*\b");
		ch = _getch();
		if (ch == 224) {
			
			printf(" ");
			ch = _getch();
			switch (ch) {
			case 72:
				if (y == 1) continue;
				y--;
				break;
			case 80:
				if (y == 7) continue;
				y++;
				break;
			case 75:
				if (x == 2) continue;
				x--;
				break;
			case 77:
				if (x == 100) continue;
				x++;
				break;
			}
		}
	}
}


//일시정지 함수
int menu(void) {
	cls;
	gotoxy(20, 10); printf("재개");
	gotoxy(20, 12); printf("조작 설명");
	gotoxy(20, 14); printf("게임 저장");
	gotoxy(20, 16); printf("메인 메뉴");
	int pos = 0;
	while (1) {
		if (GetAsyncKeyState(VK_UP))
			if (pos == 0) pos = 3;
			else pos -= 1;
		else if (GetAsyncKeyState(VK_DOWN))
			if (pos == 3) pos = 0;
			else pos += 1;
		else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
			break;
		switch (pos) {
		case 0:
			SetColor(11);
			gotoxy(20, 10); printf("재개");
			SetColor(15);
			gotoxy(20, 12); printf(" 조작 설명");
			gotoxy(20, 14); printf("게임 저장");
			gotoxy(20, 16); printf("메인 메뉴");
			break;
		case 1:
			gotoxy(20, 10); printf("재개");
			SetColor(11);
			gotoxy(20, 12); printf(" 조작 설명");
			SetColor(15);
			gotoxy(20, 14); printf("게임 저장");
			gotoxy(20, 16); printf("메인 메뉴");
			break;
		case 2:
			gotoxy(20, 10); printf("재개");
			gotoxy(20, 12); printf(" 조작 설명");
			SetColor(11);
			gotoxy(20, 14); printf("게임 저장");
			SetColor(15);
			gotoxy(20, 16); printf("메인 메뉴");
			break;
		case 3:
			gotoxy(20, 10); printf("재개");
			gotoxy(20, 12); printf(" 조작 설명");
			gotoxy(20, 14); printf("게임 저장");
			SetColor(11);
			gotoxy(20, 16); printf("메인 메뉴");
			SetColor(15);
			break;
		default: break;
		}
		Sleep(500);
		}
	/*
	switch (pos){
	case 0:

	case 1:

	case 2:

	case 3:
		cls;
	
	}
	*/
	}


//게임 맵 그리는 함수
void draw(void) {
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
}

void con_txt(void) {

}