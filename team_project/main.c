#include "head.h"


void draw(void);
void con_txt(void);
void game(void);
int main_menu(void);




int main(void) {
	
	int lev;
	int POS = main_menu();
	Sleep(300);
	

	//���� �κ�
	switch (POS) {
	//���� ���� ��Ʈ
	case 0 :
		lev = level();
		cls;
		/*���� ����
		switch (lev) {
		//����
		case 0 :

		//����
		case 1:

		//�����
		case 2:

		}*/

		game();
		break;
	case 2:
		printf("�ƹ�Ű�� �����ÿ�..");
		pause;
		exit(0);
		break;
	}
	return 0;
}

//���� �޴� ȣ��
int main_menu(void) {
	//���� ȭ�� ��Ʈ
	int p = 0;
	CursorView(0);    //Ŀ���� �������� �����ش�.
	system("COLOR 0F");    //ȭ�� ����� ����, �۾� ������ �Ͼ������ ������ �ش�.
	mainPtr();
	while (1) {
		if (GetAsyncKeyState(VK_LEFT))
			if (p == 0) p = 2;
			else p -= 1;
		else if (GetAsyncKeyState(VK_RIGHT))
			if (p == 2) p = 0;
			else p += 1;
		else if (GetAsyncKeyState(VK_RETURN))//���͸� ������ ��
			break;
		switch (p) {
		case 0:
			SetColor(11);
			gotoxy(x1, 20); printf("����  �ϱ�");
			SetColor(15);
			gotoxy(x2, 20); printf("�̾�  �ϱ�");
			gotoxy(x3, 20); printf("����  ����");
			break;
		case 1:
			gotoxy(x1, 20); printf("����  �ϱ�");
			SetColor(11);
			gotoxy(x2, 20); printf("�̾�  �ϱ�");
			SetColor(15);
			gotoxy(x3, 20); printf("����  ����");
			break;
		case 2:
			gotoxy(x1, 20); printf("����  �ϱ�");
			gotoxy(x2, 20); printf("�̾�  �ϱ�");
			SetColor(11);
			gotoxy(x3, 20); printf("����  ����");
			SetColor(15);
			break;

		default: break;
		}
		delay;
	}
	cls;
	return p;
}
//�⺻���� ������ ���� ��
void game(void) {
	draw();
	int x = 2, y = 2, ch;
	Sta_time = time(0); //���� ���� �ð� ����

	while (1) {
		//esc ������ �Ͻ�����
		if (GetAsyncKeyState(VK_ESCAPE)) {
			Stop_time = time(0); // ���� �ð� ����
			menu();
			cls;
			Sta_time += (time(0) - Stop_time);
			draw();
		}
		
		//���� �ð� ǥ��
		gotoxy(2, 25);
		printf("time : %d", full_time - (time(0) - Sta_time));
		if (full_time - (time(0) - Sta_time) == 0) {
			break;
		}
		//���� ��
		gotoxy(x, y);
		
		printf("*");
		Sleep(70);
		if (GetAsyncKeyState(VK_LEFT)) {
			if (x == 2) continue;
			printf("\b ");
			x--;
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			if (x == 100) continue;
			printf("\b ");
			x++;
		}
		else if (GetAsyncKeyState(VK_UP)) {
			if (y == 1) continue;
			printf("\b ");
			y--;
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			if (y == 7) continue;
			printf("\b ");
			y++;
		}
		
		
		/*
		ch = _getch();
		if (ch == 224) {

			printf(" ");
			ch = _getch();
			switch (ch) {
			case 72:
[				if (y == 1) continue;
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
		}*/
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
			gotoxy(20, 12); printf("���� ����");
			gotoxy(20, 14); printf("���� ����");
			gotoxy(20, 16); printf("���� �޴�");
			break;
		case 1:
			gotoxy(20, 10); printf("�簳");
			SetColor(11);
			gotoxy(20, 12); printf("���� ����");
			SetColor(15);
			gotoxy(20, 14); printf("���� ����");
			gotoxy(20, 16); printf("���� �޴�");
			break;
		case 2:
			gotoxy(20, 10); printf("�簳");
			gotoxy(20, 12); printf("���� ����");
			SetColor(11);
			gotoxy(20, 14); printf("���� ����");
			SetColor(15);
			gotoxy(20, 16); printf("���� �޴�");
			break;
		case 3:
			gotoxy(20, 10); printf("�簳");
			gotoxy(20, 12); printf("���� ����");
			gotoxy(20, 14); printf("���� ����");
			SetColor(11);
			gotoxy(20, 16); printf("���� �޴�");
			SetColor(15);
			break;
		default: break;
		}
		delay;
	}
	
	switch (pos){
	case 0:
		break;
	case 1:
		cls;
		con_txt();
		while (1) {
			if (GetAsyncKeyState(VK_RETURN)) {
				break;
			}
		}
		delay;
		menu();
		break;
	case 2:
		break;
	case 3:										//���� �޴��� ���ư���
		cls;
		main();
		break;
	default: break;
	}
	
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

//����Ű ����
void con_txt(void) {
	gotoxy(20,10); printf("\u2190    left");
	gotoxy(20,12); printf("\u2192	  right");
	gotoxy(20,14); printf("\u2191	  up");
	gotoxy(20,16); printf("\u2193	  down");
	gotoxy(20,18); printf("esc	  pause");
	gotoxy(73, 25); printf("�ٽ� ���ư����� enter ��������..");

}