#include "head.h"


void draw(void);
void con_txt(void);
//�⺻���� ������ ���� ��
void game(void){
	draw();
	int x = 2, y = 2, ch;
	

	while (1) {
		//esc ������ �Ͻ�����
		if (GetAsyncKeyState(VK_ESCAPE)) {
			menu();
			cls;
			draw();
		}
		//���� ��
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


//�Ͻ����� �Լ�
int menu(void) {
	cls;
	gotoxy(20, 10); printf("�簳");
	gotoxy(20, 12); printf("���� ����");
	gotoxy(20, 14); printf("���� ����");
	gotoxy(20, 16); printf("���� �޴�");
	int pos = 0;
	while (1) {
		if (GetAsyncKeyState(VK_UP))
			if (pos == 0) pos = 3;
			else pos -= 1;
		else if (GetAsyncKeyState(VK_DOWN))
			if (pos == 3) pos = 0;
			else pos += 1;
		else if (GetAsyncKeyState(VK_RETURN))//���͸� ������ ��
			break;
		switch (pos) {
		case 0:
			SetColor(11);
			gotoxy(20, 10); printf("�簳");
			SetColor(15);
			gotoxy(20, 12); printf(" ���� ����");
			gotoxy(20, 14); printf("���� ����");
			gotoxy(20, 16); printf("���� �޴�");
			break;
		case 1:
			gotoxy(20, 10); printf("�簳");
			SetColor(11);
			gotoxy(20, 12); printf(" ���� ����");
			SetColor(15);
			gotoxy(20, 14); printf("���� ����");
			gotoxy(20, 16); printf("���� �޴�");
			break;
		case 2:
			gotoxy(20, 10); printf("�簳");
			gotoxy(20, 12); printf(" ���� ����");
			SetColor(11);
			gotoxy(20, 14); printf("���� ����");
			SetColor(15);
			gotoxy(20, 16); printf("���� �޴�");
			break;
		case 3:
			gotoxy(20, 10); printf("�簳");
			gotoxy(20, 12); printf(" ���� ����");
			gotoxy(20, 14); printf("���� ����");
			SetColor(11);
			gotoxy(20, 16); printf("���� �޴�");
			SetColor(15);
			break;
		default: break;
		}
		Sleep(500);
		}
	/*
	switch (pos){
	case 0:

	case 1:

	case 2:

	case 3:
		cls;
	
	}
	*/
	}


//���� �� �׸��� �Լ�
void draw(void) {
	puts("������������������������������������������������������");
	puts("��                                                                                                      ��");
	puts("��                                                                                                      ��");
	puts("��                                                                                                      ��");
	puts("��                                                                                                      ��");
	puts("��                                                                                                      ��");
	puts("��                                                                                                      ��");
	puts("��                                                                                                      ��");
	printf("������������������������������������������������������");
}

void con_txt(void) {

}