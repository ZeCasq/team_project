#include "head.h"

//레벨 설정 표기
int level(void) {

	int POS = 0;
	CursorView(0);    //커서의 깜빡임을 숨겨준다.
	system("COLOR 0F");    //화면 배경을 검정, 글씨 색깔을 하얀색으로 설정해 준다.
	gotoxy(20, 20); printf("쉬움");
	gotoxy(47, 20); printf("보통");
	gotoxy(75, 20); printf("어려움");
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
			gotoxy(20, 20); printf("쉬움");
			SetColor(15);
			gotoxy(47, 20); printf("보통");
			gotoxy(75, 20); printf("어려움");
			break;
		case 1:
			gotoxy(20, 20); printf("쉬움");
			SetColor(11);
			gotoxy(47, 20); printf("보통");
			SetColor(15);
			gotoxy(75, 20); printf("어려움");
			break;
		case 2:
			gotoxy(20, 20); printf("쉬움");
			gotoxy(47, 20); printf("보통");
			SetColor(11);
			gotoxy(75, 20); printf("어려움");
			SetColor(15);
			break;

		default: break;
		}
		delay;
	}
	return POS;
}