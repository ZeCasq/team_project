#include "head.h"


void draw(void);
void con_txt(void);
void game(void);
int main_menu(void);


int first = 0; //���� ������ �÷��̰� �������� �ƴ��� ����



int main(void) {
	
	int lev;
	int POS = main_menu();
	delay;
	if (first == 0) {
		con_txt();
		gotoxy(72, 25); printf("�Ѿ���� enter �����ÿ�        ");
		while (!GetAsyncKeyState(VK_RETURN));
		cls;
		first = 1;
	}
	

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
			gotoxy(20, 20); printf("����  �ϱ�");
			SetColor(15);
			gotoxy(47, 20); printf("�̾�  �ϱ�");
			gotoxy(75, 20); printf("����  ����");
			break;
		case 1:
			gotoxy(20, 20); printf("����  �ϱ�");
			SetColor(11);
			gotoxy(47, 20); printf("�̾�  �ϱ�");
			SetColor(15);
			gotoxy(75, 20); printf("����  ����");
			break;
		case 2:
			gotoxy(20, 20); printf("����  �ϱ�");
			gotoxy(47, 20); printf("�̾�  �ϱ�");
			SetColor(11);
			gotoxy(75, 20); printf("����  ����");
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
	Start_time = time(0); //���� ���� �ð� ����

	while (1) {
		//esc ������ �Ͻ�����
		if (GetAsyncKeyState(VK_ESCAPE)) {
			Stop_time = time(0); // ���� �ð� ����
			menu();
			cls;
			Start_time += (time(0) - Stop_time); //���� �ð��� ���ѽð����� ����
			draw();
		}
		
		//���� �ð� ǥ��
		
		gotoxy(2, 25);

		printf("time : %d           ", full_time - ((time(0) - Start_time)));
		if (full_time - (time(0) - Start_time) == 0) {
			cls;
			GameOver();
			break;
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



//����Ű ����
void con_txt(void) {
	gotoxy(20,10); printf("\u2190    left");
	gotoxy(20,12); printf("\u2192	  right");
	gotoxy(20,14); printf("\u2191	  up");
	gotoxy(20,16); printf("\u2193	  down");
	gotoxy(20,18); printf("esc	  pause");
	gotoxy(73, 25); printf("�ٽ� ���ư����� enter ��������..");

}