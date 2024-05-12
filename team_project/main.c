#include "head.h"




int main(void) {

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
	

	//게임 부분
	switch (POS) {
	//게임 시작 파트
	case 0 :
		game();

	}

	pause;
	return 0;
}



