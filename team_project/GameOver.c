#include "head.h"

void GameOver(void) {
	int p = 0;
	while (1) {
		if (GetAsyncKeyState(VK_LEFT))
			if (p == 0) p = 1;
			else p -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (p == 1) p = 0;
			else p += 1;
		else if (GetAsyncKeyState(VK_RETURN))//���͸� ������ ��
			break;
		switch (p) {
		case 0:
			SetColor(11);
			gotoxy(30, 20); printf("�ٽ�  �ϱ�");
			SetColor(15);
			gotoxy(60, 20); printf("����  �޴�");
			break;
		case 1:
			gotoxy(30, 20); printf("�ٽ�  �ϱ�");
			SetColor(11);
			gotoxy(60, 20); printf("����  �޴�");
			SetColor(15);
			break;
		default: break;
		}
		delay;
	}
	switch (p) {
	case 0:
		cls;
		game();
		break;
	case 1:
		cls;
		main();
		break;
	default: break;
	}
	
}