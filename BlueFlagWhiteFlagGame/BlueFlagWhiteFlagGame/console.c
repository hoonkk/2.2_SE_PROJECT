#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "console.h"
#define _CRT_SECURE_NO_WARNINGS
#define FONT_BLUE 1
#define FONT_RED 4
#define FONT_YELLOW 6
#define FONT_WHITE 7
#define FONT_CYAN 3
#define CYAN 11

void pause()
{
	system("pause>nul");
}

void gotoxy(int x, int y)
{
	COORD Pos = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
void cursorType(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void printDot(int number)
{
	for (int i = 0; i < number;i++)
		printf("*");
}
void printBlank(int num)
{
	for (int i = 0; i < num;i++)
		printf(" ");
}

int getKey()
{
	return _getch();
}

int keySetting() //  �ι�° ����Ʈ�� ������ �����Է�
{
	int key;
	key = getKey();
	getKey();
	return key;
}

void userKeySetting()
{
	gotoxy(20, 28); printf("û�⸦ �ø��� ��ư�� �Է����ּ���::");
	inputKey.blueUp = keySetting();
	gotoxy(20, 29); printf("�Է��Ͻ� Ű�� "); putchar(inputKey.blueUp); printf(" �Դϴ�");
	while (1)// ��ư�� �ߺ����� �ʰ� �˻��Ͽ�, �ߺ��� �ٽ� �Է¹ް� �ϴ� ����
	{
		system("cls");
		gotoxy(20, 28);printf("û�⸦ ������ ��ư�� �Է����ּ���::");
		inputKey.blueDown = keySetting();
		gotoxy(20, 29);printf("�Է��Ͻ� Ű�� "); putchar(inputKey.blueDown); printf(" �Դϴ�");
		if (inputKey.blueDown == inputKey.blueUp)
		{
			gotoxy(20, 30);printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���");
		}
		else break;
	}
	while (1)
	{
		system("cls");
		gotoxy(20, 28); printf("��⸦ �ø��� ��ư�� �Է����ּ���::");
		inputKey.whiteUp = keySetting();
		gotoxy(20, 29); printf("�Է��Ͻ� Ű�� "); putchar(inputKey.whiteUp); printf(" �Դϴ�");
		if (inputKey.whiteUp == inputKey.blueUp || inputKey.whiteUp == inputKey.blueDown)
		{
			gotoxy(20, 30);printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���");
		}
		else break;
	}
	while (1)
	{
		system("cls");
		gotoxy(20, 28); printf("��⸦ ������ ��ư�� �Է����ּ���::");
		inputKey.whiteDown = keySetting();
		gotoxy(20, 29);printf("�Է��Ͻ� Ű�� "); putchar(inputKey.whiteDown); printf(" �Դϴ�");
		if (inputKey.whiteDown == inputKey.blueUp || inputKey.whiteDown == inputKey.blueDown || inputKey.whiteDown == inputKey.whiteUp)
		{
			gotoxy(20, 30);printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���");
		}
		else break;
	}
	system("pause>nul");
	system("cls");
}

void initialShow()
{
	textcolor(FONT_YELLOW);
	gotoxy(5, 1);
	printf("STAGE : %d", stageStatus.stage);
	textcolor(FONT_RED);
	gotoxy(30, 1);
	printf("LIFE : ");
	for (int i = 0;i < stageStatus.life;i++) printf("��");
	for (int i = 0;i < 5 - stageStatus.life;i++) printf("��");
	gotoxy(55, 1);
	textcolor(FONT_YELLOW);
	printf("SCORE : %d", stageStatus.score);
	textcolor(FONT_WHITE);
	printCharactor(DEFAULT);
}
void updateShow()
{
	textcolor(FONT_YELLOW);
	gotoxy(5, 1);
	printf("STAGE : %d", stageStatus.stage);
	gotoxy(30, 1);
	textcolor(FONT_RED);
	printf("LIFE : ");
	for (int i = 0;i < stageStatus.life;i++) printf("��");
	for (int i = 0;i < 5 - stageStatus.life;i++) printf("��");
	gotoxy(55, 1);
	textcolor(FONT_YELLOW);
	printf("SCORE : %d", stageStatus.score);
	textcolor(FONT_BLUE);
	gotoxy(15, 5);
	printf("û��� : %c", inputKey.blueUp);
	gotoxy(15, 6);
	printf("û��� : %c", inputKey.blueDown);
	textcolor(FONT_WHITE);
	gotoxy(40, 5);
	printf("���� : %c", inputKey.whiteUp);
	gotoxy(40, 6);
	printf("���� : %c", inputKey.whiteDown);   // �⺻ ȭ�� UI ���

	gotoxy(22, 10);
	textcolor(FONT_YELLOW);
	printf("%s ", stageStatus._blueOrWhite[0]);
	textcolor(FONT_WHITE);
	printf("%s ", stageStatus._frontQuestion[0]);
	textcolor(FONT_YELLOW);
	printf("%s ", stageStatus._blueOrWhite[1]);
	textcolor(FONT_WHITE);
	printf("%s ", stageStatus._backQuestion[0]); // ���� ���
}

void printMenu()
{
	gotoxy(25, 20);
	printf("1.G A M E S T A R T");
	gotoxy(25, 21);
	printf("2.K E Y S E T T I N G");
	gotoxy(25, 22);
	printf("3.R A N K I N G");
	gotoxy(25, 23);
	printf("4.E X I T");
	textcolor(FONT_RED);
	gotoxy(25, 24);
	printf(">>");
	textcolor(FONT_WHITE);
}

void printCharactor(int emotion)
{
	clearFlag();
	textcolor(FONT_CYAN);
	gotoxy(11, 26); printDot(1);
	gotoxy(10, 25); printDot(3);
	gotoxy(9, 24); printDot(5);
	gotoxy(8, 23); printDot(7);
	gotoxy(8, 22); printDot(12); //���� û�� �׸���
	
	
	textcolor(FONT_YELLOW);
	gotoxy(20, 22); printDot(29);
	gotoxy(31, 15); printDot(7);
	gotoxy(30, 16); printDot(1); gotoxy(38, 16); printDot(1);
	gotoxy(29, 17); printDot(1); gotoxy(39, 17); printDot(1);
	if (emotion == DEFAULT)
	{
		gotoxy(31, 17); printf("��"); gotoxy(35, 17);printf("��"); //��
		gotoxy(33, 19);printf("��"); // ��� ǥ��
	}
	if (emotion == HAPPY)
	{
		gotoxy(31, 17); printf("��"); gotoxy(35, 17);printf("��"); //��
		gotoxy(33, 19);printf("��"); // ���� ���
	}
	if (emotion == SAD)
	{
		gotoxy(31, 17); printf("��"); gotoxy(35, 17);printf("��"); //��
		gotoxy(33, 19); printf("��"); // Ʋ�� ���
	}
	
	gotoxy(29, 18); printDot(1); gotoxy(39, 18); printDot(1);
	gotoxy(30, 19); printDot(1); gotoxy(38, 19); printDot(1);
	gotoxy(31, 20); printDot(7);
	gotoxy(34, 21); printDot(1);
	for (int i = 22; i < 31;i++) { gotoxy(32, i); printDot(5); }  // ��� �׸���

	textcolor(FONT_WHITE);
	gotoxy(57, 26); printDot(1);
	gotoxy(56, 25); printDot(3);
	gotoxy(55, 24); printDot(5);
	gotoxy(54, 23); printDot(7);
	gotoxy(49, 22); printDot(12); //������ ��� �׸���
}
void moveFlag(int flagSwitch)
{
	// ������ ������ �ִ� û���� �����
	//if (flagSwitch == inputKey.blueUp || flagSwitch == inputKey.blueDown || flagSwitch == inputKey.whiteUp || flagSwitch == inputKey.whiteDown)
	//{
	//	gotoxy(11, 26); printBlank(1); gotoxy(10, 25); printBlank(3);
	//	gotoxy(9, 24); printBlank(5); gotoxy(8, 23); printBlank(7); gotoxy(8, 22); printBlank(12); //���� û�� �׸��� �����
	//	gotoxy(57, 26); printBlank(1); gotoxy(56, 25); printBlank(3);
	//	gotoxy(55, 24); printBlank(5); gotoxy(54, 23); printBlank(7); gotoxy(49, 22); printBlank(12); //������ ��� �׸��� �����
	//}
	
	if (flagSwitch == inputKey.blueUp) // û�� �ø��� �� ��Ʈ ��� û�� ������ �ø��� �� blank�� �ٽ����.
	{
		textcolor(FONT_BLUE);
		gotoxy(11, 26); printBlank(1); gotoxy(10, 25); printBlank(3);
		gotoxy(9, 24); printBlank(5); gotoxy(8, 23); printBlank(7); gotoxy(8, 22); printBlank(12); // ����û�� �����

		for (int i = 22; i < 31; i++) { gotoxy(20, i); printBlank(1); }
		for (int i = 26; i < 31; i++) { gotoxy(17, i); printBlank(3); }
		for (int i = 27; i < 30; i++) { gotoxy(14, i); printBlank(3); }
		for (int i = 28; i < 29; i++) { gotoxy(13, i); printBlank(1); } // û�� ������ ����

		for (int i = 22; i > 13; i--) { gotoxy(20, i); printDot(1); }
		for (int i = 14; i < 19; i++) { gotoxy(17, i); printDot(3); }
		for (int i = 15; i < 18; i++) { gotoxy(14, i); printDot(3); }
		for (int i = 16; i < 17; i++) { gotoxy(13, i); printDot(1); }
		textcolor(FONT_WHITE);
	}
	if (flagSwitch == inputKey.whiteUp) // ��� �ø��� ��
	{
		gotoxy(57, 26); printBlank(1); gotoxy(56, 25); printBlank(3);
		gotoxy(55, 24); printBlank(5); gotoxy(54, 23); printBlank(7); gotoxy(49, 22); printBlank(12);//���� ��� �����
		textcolor(FONT_WHITE);
		for (int i = 22; i < 31; i++) { gotoxy(48, i); printBlank(1); }
		for (int i = 26; i < 31; i++) { gotoxy(49, i); printBlank(3); }
		for (int i = 27; i < 30; i++) { gotoxy(52, i); printBlank(3); }
		for (int i = 28; i < 29; i++) { gotoxy(55, i); printBlank(1); } // ��� ������ ����

		for (int i = 22; i > 13; i--) { gotoxy(48, i); printDot(1); }
		for (int i = 14; i < 19; i++) { gotoxy(49, i); printDot(3); }
		for (int i = 15; i < 18; i++) { gotoxy(52, i); printDot(3); }
		for (int i = 16; i < 17; i++) { gotoxy(55, i); printDot(1); }
	}
	if (flagSwitch == inputKey.blueDown) // û�� ������ ��
	{
		gotoxy(11, 26); printBlank(1); gotoxy(10, 25); printBlank(3);
		gotoxy(9, 24); printBlank(5); gotoxy(8, 23); printBlank(7); gotoxy(8, 22); printBlank(12);//���� û�� �����

		textcolor(FONT_BLUE);
		for (int i = 22; i > 13; i--) { gotoxy(20, i); printBlank(1); }
		for (int i = 14; i < 19; i++) { gotoxy(17, i); printBlank(3); }
		for (int i = 15; i < 18; i++) { gotoxy(14, i); printBlank(3); }
		for (int i = 16; i < 17; i++) { gotoxy(13, i); printBlank(1); } // û�� �÷������ ����
		
		for (int i = 22; i < 31; i++) { gotoxy(20, i); printDot(1); }
		for (int i = 26; i < 31; i++) { gotoxy(17, i); printDot(3); }
		for (int i = 27; i < 30; i++) { gotoxy(14, i); printDot(3); }
		for (int i = 28; i < 29; i++) { gotoxy(13, i); printDot(1); } // û�� ����
		textcolor(FONT_WHITE);
	}
	if (flagSwitch == inputKey.whiteDown) // ��� ������ ��
	{
		gotoxy(57, 26); printBlank(1); gotoxy(56, 25); printBlank(3);
		gotoxy(55, 24); printBlank(5); gotoxy(54, 23); printBlank(7); gotoxy(49, 22); printBlank(12); // ���� ��� �����
		textcolor(FONT_WHITE);
		for (int i = 22; i > 13; i--) { gotoxy(48, i); printBlank(1); }
		for (int i = 14; i < 19; i++) { gotoxy(49, i); printBlank(3); }
		for (int i = 15; i < 18; i++) { gotoxy(52, i); printBlank(3); }
		for (int i = 16; i < 17; i++) { gotoxy(55, i); printBlank(1); }

		for (int i = 22; i < 31; i++) { gotoxy(48, i); printDot(1); }
		for (int i = 26; i < 31; i++) { gotoxy(49, i); printDot(3); }
		for (int i = 27; i < 30; i++) { gotoxy(52, i); printDot(3); }
		for (int i = 28; i < 29; i++) { gotoxy(55, i); printDot(1); } // ��� ����
	}
}

void clearFlag()
{
	//û�� ������ ����
	for (int i = 22; i < 31; i++) { gotoxy(20, i); printBlank(1); }
	for (int i = 26; i < 31; i++) { gotoxy(17, i); printBlank(3); }
	for (int i = 27; i < 30; i++) { gotoxy(14, i); printBlank(3); }
	for (int i = 28; i < 29; i++) { gotoxy(13, i); printBlank(1); }
	//��� ������ ����
	for (int i = 22; i < 31; i++) { gotoxy(48, i); printBlank(1); }
	for (int i = 26; i < 31; i++) { gotoxy(49, i); printBlank(3); }
	for (int i = 27; i < 30; i++) { gotoxy(52, i); printBlank(3); }
	for (int i = 28; i < 29; i++) { gotoxy(55, i); printBlank(1); }
	//û�� �ø��� ����
	for (int i = 22; i > 13; i--) { gotoxy(20, i); printBlank(1); }
	for (int i = 14; i < 19; i++) { gotoxy(17, i); printBlank(3); }
	for (int i = 15; i < 18; i++) { gotoxy(14, i); printBlank(3); }
	for (int i = 16; i < 17; i++) { gotoxy(13, i); printBlank(1); }
	//��� �ø��� ����
	for (int i = 22; i > 13; i--) { gotoxy(48, i); printBlank(1); }
	for (int i = 14; i < 19; i++) { gotoxy(49, i); printBlank(3); }
	for (int i = 15; i < 18; i++) { gotoxy(52, i); printBlank(3); }
	for (int i = 16; i < 17; i++) { gotoxy(55, i); printBlank(1); }
}

