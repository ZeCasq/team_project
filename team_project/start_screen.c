#include "head.h"
//시작화면 
void mainPtr(void) {
	system("mode con: cols=106 lines=30");
	system("title 보물찾기 - 메인");
	
	gotoxy(20, 20); printf("새로  하기");
	gotoxy(47, 20); printf("이어  하기");
	gotoxy(75, 20); printf("게임  종료");
	return;
}