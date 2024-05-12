#include "head.h"

void mainPtr(void) {
	system("mode con: cols=106 lines=30");
	system("title 보물찾기 - 메인");
	
	gotoxy(x1, 20); printf("새로  하기");
	gotoxy(x2, 20); printf("이어  하기");
	gotoxy(x3, 20); printf("게임  종료");
	return;
}