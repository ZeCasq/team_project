#include "head.h"

//���� ���� ǥ��
int level(void) {

	int POS = 0;
	CursorView(0);    //Ŀ���� �������� �����ش�.
	system("COLOR 0F");    //ȭ�� ����� ����, �۾� ������ �Ͼ������ ������ �ش�.
	gotoxy(20, 20); printf("����");
	gotoxy(47, 20); printf("����");
	gotoxy(75, 20); printf("�����");
	while (1) {
		if (GetAsyncKeyState(VK_LEFT))
			if (POS == 0) POS = 3;
			else POS -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (POS == 3) POS = 0;
			else POS += 1;
		else if (GetAsyncKeyState(VK_RETURN))//���͸� ������ ��
			break;
		switch (POS) {
		case 0:
			SetColor(11);
			gotoxy(20, 20); printf("����");
			SetColor(15);
			gotoxy(47, 20); printf("����");
			gotoxy(75, 20); printf("�����");
			break;
		case 1:
			gotoxy(20, 20); printf("����");
			SetColor(11);
			gotoxy(47, 20); printf("����");
			SetColor(15);
			gotoxy(75, 20); printf("�����");
			break;
		case 2:
			gotoxy(20, 20); printf("����");
			gotoxy(47, 20); printf("����");
			SetColor(11);
			gotoxy(75, 20); printf("�����");
			SetColor(15);
			break;

		default: break;
		}
		delay;
	}
	return POS;
}