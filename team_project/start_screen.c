#include "head.h"
//����ȭ�� 
void mainPtr(void) {
	system("mode con: cols=106 lines=30");
	system("title ����ã�� - ����");
	
	gotoxy(20, 20); printf("����  �ϱ�");
	gotoxy(47, 20); printf("�̾�  �ϱ�");
	gotoxy(75, 20); printf("����  ����");
	return;
}