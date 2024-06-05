#include "head.h"

void con_txt(void);

void game(void); //���� �������� ����
int main_menu();
void displayLives(void);
void menu(void);
void init();


int first = 0; //���� ������ �÷��̰� �������� �ƴ��� ����
int X, Y;
int Life, sec, clear, eyesight;

extern int** map;

int main(void) {
	struct condition player = { 0,0 };
	setlocale(LC_CTYPE, ""); // �����ڵ� ��� ����
	
	int POS = main_menu();
	delay;
	if (first == 0) {
		con_txt();
		gotoxy(72, 25); printf("�Ѿ���� enter �����ÿ�        ");
		while (!GetAsyncKeyState(VK_RETURN));
		cls;
		Sleep(300);
		first = 1;
	}
	

	//���� �κ�
	switch (POS) {
	//���� ���� ��Ʈ
	case 0 :
		level();
		game();
		break;
	case 1:
		//�̾��ϱ�
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
	//int lives = 3; //���, �������� ����.
	
	
	//���� ȭ�� ��Ʈ
	int p = 0;
	CursorView(0);    //Ŀ���� �������� �����ش�.
	system("COLOR 0F");    //ȭ�� ����� ����, �۾� ������ �Ͼ������ ������ �ش�.
	mainPtr();
	displayLives();
	
	while (1) {
		if (GetAsyncKeyState(VK_LEFT)) {
			if (p == 0) p = 2;
			else p -= 1;
		}
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
	//initFlag();//���̵��� ���� ��� �ʱ�ȭ�� �ٸ��� ������
	init();

	int ch;				
	Start_time = time(0); //���� ���� �ð� ����
	GamePlay();
	makeFlag();//���̵��� ���� ��� ��ġ������ �ٸ��� ������

	while (1) {
		//esc ������ �Ͻ�����
		if (GetAsyncKeyState(VK_ESCAPE)) {
			Stop_time = time(0); // ���� �ð� ����
			menu();
			cls;
			Start_time += (time(0) - Stop_time); //���� �ð��� ���ѽð����� ����
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x0001) { //����
			judgeMove(X - 1, Y);
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001) { //������
			judgeMove(X + 1, Y);

		}
		if (GetAsyncKeyState(VK_UP) & 0x0001) { //��
			judgeMove(X, Y - 1);
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) { //�Ʒ�
			judgeMove(X, Y + 1);
		}
		if (GetAsyncKeyState(0x20) & 0x0001)		//�׽�Ʈ��
		{
			map[Y][X] = 9;
		}

		printMap();
		
		//���� �ð� ǥ��
		
		gotoxy(2, 25);

		printf("time : %d           ", full_time - ((time(0) - Start_time)));
		if (full_time - (time(0) - Start_time) <= 0) {
			cls;
			GameOver();
			break;
		}
		//system("cls");
	}
}


//�Ͻ����� �Լ�
void menu(void) {
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
	case 2:										//���� ����
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

//��� ���
void displayLives() {
	gotoxy(1,1);
	for (int i = 0; i < Life; i++) {
		wprintf(L"�� ");
	}
	printf("                ");
	wprintf(L"\n");
}

void init() {			//lev���� �ٸ� �ʱ�ȭ����, initFlag()������ �������� �ٸ� �ʱ�ȭ �����ϰ� ����
	initFlag();
	X = Y = 1;
	lev = 1;
	if (lev == 1)
	{
		Life = 3;
		sec = 300;
		clear = 0;
		eyesight = 5;
	}
	else if (lev == 2)
	{
		Life = 3;
		sec = 300;
		clear = 0;
		eyesight = 5;
	}
	else if (lev == 3)
	{
		Life = 3;
		sec = 300;
		clear = 0;
		eyesight = 5;
	}
	
	return;
}