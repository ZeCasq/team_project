#include "head.h"


void draw(void);
void con_txt(void);
void game(void);
int main_menu(void);

int main(void) {
	int lev;
	int POS;

	POS = main_menu();
	

	//게임 부분
	switch (POS) {
	//게임 시작 파트
	case 0 :
		lev = level();
		cls;
		/*레벨 구분
		switch (lev) {
		//쉬움
		case 0 :

		//보통
		case 1:

		//어려움
		case 2:

		}*/
		game();
		
	}

	pause;
	return 0;
}

//메인 메뉴 호출
int main_menu(void) {
	//시작 화면 파트
	int POS = 0;
	CursorView(0);    //커서의 깜빡임을 숨겨준다.
	system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
	mainPtr();
	while (1) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 3;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 3) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
			break;
		switch (POS) {
		case 0:
			SetColor(11);
			gotoxy(x1, 20); printf("새로  하기");
			SetColor(15);
			gotoxy(x2, 20); printf("이어  하기");
			gotoxy(x3, 20); printf("게임  종료");
			break;
		case 1:
			gotoxy(x1, 20); printf("새로  하기");
			SetColor(11);
			gotoxy(x2, 20); printf("이어  하기");
			SetColor(15);
			gotoxy(x3, 20); printf("게임  종료");
			break;
		case 2:
			gotoxy(x1, 20); printf("새로  하기");
			gotoxy(x2, 20); printf("이어  하기");
			SetColor(11);
			gotoxy(x3, 20); printf("게임  종료");
			SetColor(15);
			break;

		default: break;
		}
		Sleep(500);
	}
	cls;
	return POS;
}
//기본적인 움직임 구현 툴
void game(void) {
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
	
	switch (pos){
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:										//메인 메뉴로 돌아가기
		cls;
		main_menu();
		break;
	default: break;
	}
	
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

