#include "head.h"
#define x 30
//���� ���� ǥ��
void level(void) {

	int POS = 1;
	CursorView(0);    //Ŀ���� �������� �����ش�.
	system("COLOR 0F");    //ȭ�� ����� ����, �۾� ������ �Ͼ������ ������ �ش�.
	gotoxy(x, 5);
	printf("   ___           _ _             \n");
	gotoxy(x, 6);
	printf("  |_ _|_ __   __| (_) __ _ _ __   __ _ \n");
	gotoxy(x, 7);
	printf("   | || '_ \\ / _` | |/ _` | '_ \\ / _` |\n");
	gotoxy(x, 8);
	printf("   | || | | | (_| | | (_| | | | | (_| |\n");
	gotoxy(x, 9);
	printf("  |___|_| |_|\\__,_|_|\\__,_|_| |_|\\__,_|\n");
	gotoxy(x, 10);
	printf(" _   __ _____  _   _  _   __ _   _  _   __\n");
	gotoxy(x, 11);
	printf("| | / /|  _  || \\ | || | / /| | | || | / /\n");
	gotoxy(x, 12);
	printf("| |/ / | | | ||  \\| || |/ / | | | || |/ / \n");
	gotoxy(x, 13);
	printf("|    \\ | | | || . ` ||    \\ | | | ||    \\ \n");
	gotoxy(x, 14);
	printf("| |\\  \\\\ \\_/ /| |\\  || |\\  \\| |_| || |\\  \\\n");
	gotoxy(x, 15);
	printf("\\_| \\_/ \\___/ \\_| \\_/\\_| \\_/ \\___/ \\_| \\_/\n");
	printf("                                          \n");
	printf("                                          \n");
	gotoxy(20, 20); printf("����");
	gotoxy(47, 20); printf("����");
	gotoxy(75, 20); printf("�����");
	while (1) {
		if (GetAsyncKeyState(VK_LEFT)) {
			bs();
			if (POS == 1) POS = 3;
			else POS -= 1;
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			bs();
			if (POS == 3) POS = 1;
			else POS += 1;
		}
		else if (GetAsyncKeyState(VK_RETURN)) {//���͸� ������ ��
			cl();
			break;
		}

		switch (POS) {
		case 1:
			SetColor(11);
			gotoxy(20, 20); printf("����");
			SetColor(15);
			gotoxy(47, 20); printf("����");
			gotoxy(75, 20); printf("�����");
			break;
		case 2:
			gotoxy(20, 20); printf("����");
			SetColor(11);
			gotoxy(47, 20); printf("����");
			SetColor(15);
			gotoxy(75, 20); printf("�����");
			break;
		case 3:
			gotoxy(20, 20); printf("����");
			gotoxy(47, 20); printf("����");
			SetColor(11);
			gotoxy(75, 20); printf("�����");
			SetColor(15);
			break;
		default:break;
		}
		
	}
	lev =  POS;
	cls;
}