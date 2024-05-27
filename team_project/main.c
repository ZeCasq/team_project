#include "head.h"


void draw(void);
void con_txt(void);
void game(void);
int main_menu(void);


int first = 0; //게임 실행후 플레이가 최초인지 아닌지 구분



int main(void) {
	
	int lev;
	int POS = main_menu();
	delay;
	if (first == 0) {
		con_txt();
		gotoxy(72, 25); printf("넘어가려면 enter 누르시오        ");
		while (!GetAsyncKeyState(VK_RETURN));
		cls;
		first = 1;
	}
	

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
		break;
	case 2:
		printf("아무키나 누르시오..");
		pause;
		exit(0);
		break;
	}
	return 0;
}

//메인 메뉴 호출
int main_menu(void) {
	//시작 화면 파트
	int p = 0;
	CursorView(0);    //커서의 깜빡임을 숨겨준다.
	system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
	mainPtr();
	while (1) {
		if (GetAsyncKeyState(VK_LEFT))
			if (p == 0) p = 2;
			else p -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (p == 2) p = 0;
			else p += 1;
		else if (GetAsyncKeyState(VK_RETURN))//엔터를 눌렀을 때
			break;
		switch (p) {
		case 0:
			SetColor(11);
			gotoxy(20, 20); printf("새로  하기");
			SetColor(15);
			gotoxy(47, 20); printf("이어  하기");
			gotoxy(75, 20); printf("게임  종료");
			break;
		case 1:
			gotoxy(20, 20); printf("새로  하기");
			SetColor(11);
			gotoxy(47, 20); printf("이어  하기");
			SetColor(15);
			gotoxy(75, 20); printf("게임  종료");
			break;
		case 2:
			gotoxy(20, 20); printf("새로  하기");
			gotoxy(47, 20); printf("이어  하기");
			SetColor(11);
			gotoxy(75, 20); printf("게임  종료");
			SetColor(15);
			break;

		default: break;
		}
		delay;
	}
	cls;
	return p;
}
//기본적인 움직임 구현 툴
void game(void) {
	draw();
	int x = 2, y = 2, ch;
	Start_time = time(0); //게임 시작 시간 설정

	while (1) {
		//esc 눌러서 일시정지
		if (GetAsyncKeyState(VK_ESCAPE)) {
			Stop_time = time(0); // 멈춘 시간 저장
			menu();
			cls;
			Start_time += (time(0) - Stop_time); //멈춘 시간은 제한시간에서 제외
			draw();
		}
		
		//게임 시간 표현
		
		gotoxy(2, 25);

		printf("time : %d           ", full_time - ((time(0) - Start_time)));
		if (full_time - (time(0) - Start_time) == 0) {
			cls;
			GameOver();
			break;
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
			gotoxy(20, 12); printf("조작 설명");
			gotoxy(20, 14); printf("게임 저장");
			gotoxy(20, 16); printf("메인 메뉴");
			break;
		case 1:
			gotoxy(20, 10); printf("재개");
			SetColor(11);
			gotoxy(20, 12); printf("조작 설명");
			SetColor(15);
			gotoxy(20, 14); printf("게임 저장");
			gotoxy(20, 16); printf("메인 메뉴");
			break;
		case 2:
			gotoxy(20, 10); printf("재개");
			gotoxy(20, 12); printf("조작 설명");
			SetColor(11);
			gotoxy(20, 14); printf("게임 저장");
			SetColor(15);
			gotoxy(20, 16); printf("메인 메뉴");
			break;
		case 3:
			gotoxy(20, 10); printf("재개");
			gotoxy(20, 12); printf("조작 설명");
			gotoxy(20, 14); printf("게임 저장");
			SetColor(11);
			gotoxy(20, 16); printf("메인 메뉴");
			SetColor(15);
			break;
		default: break;
		}
		delay;
	}
	
	switch (pos){
	case 0:
		break;
	case 1:
		cls;
		con_txt();
		while (1) {
			if (GetAsyncKeyState(VK_RETURN)) {
				break;
			}
		}
		delay;
		menu();
		break;
	case 2:
		break;
	case 3:										//메인 메뉴로 돌아가기
		cls;
		main();
		break;
	default: break;
	}
	
}



//조작키 설명
void con_txt(void) {
	gotoxy(20,10); printf("\u2190    left");
	gotoxy(20,12); printf("\u2192	  right");
	gotoxy(20,14); printf("\u2191	  up");
	gotoxy(20,16); printf("\u2193	  down");
	gotoxy(20,18); printf("esc	  pause");
	gotoxy(73, 25); printf("다시 돌아가려면 enter 누르세요..");

}