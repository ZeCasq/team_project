#include "head.h"

//기본적인 움직임 구현 툴
void game(void){
	int x = 2, y = 2, ch;
	puts("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	puts("■                                                                                                      ■");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	while (1) {

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