#include "head.h"

void GameOver(void) {
	mciSendString(TEXT("close mp3_1"), NULL, 0, NULL);
	ov();
	gameover();
	int p = 0;
	while (1) {
		if (GetAsyncKeyState(VK_LEFT)) {
			bs();
			if (p == 0) p = 1;
			else p -= 1;
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			bs();
			if (p == 1) p = 0;
			else p += 1;
		}
		else if (GetAsyncKeyState(VK_RETURN)){//���͸� ������ ��
			cl();
			mciSendString(TEXT("close mp3_4"), NULL, 0, NULL);
			break;
	}
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