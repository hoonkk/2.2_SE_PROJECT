#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#include "console.h"

#define FONT_BLUE 1
#define FONT_RED 4
#define FONT_YELLOW 6
#define FONT_WHITE 7
#define FONT_CYAN 3
#define CYAN 11

#define WAIT 50

#define NOTHING 0



int menuNumber = 1;
void pause()
{
	int check = 0;
	while (1)
	{
		check = getKey();
		if (check == SPACEBAR)
		{
			getKey();
			break;
		}
	}
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

void printKeyboard()
{
	gotoxy(6, 3); textcolor(FONT_CYAN); printf(" �Ķ��� "); textcolor(FONT_WHITE); printf("��� ������ Ű");
	gotoxy(42, 3);textcolor(FONT_RED); printf(" ������ "); textcolor(FONT_WHITE); printf("��� �Ұ����� Ű");
	textcolor(FONT_WHITE);
	for (int i = 6; i < 12; i++) { gotoxy(5, i); printf("��"); gotoxy(66, i); printf("��"); }
	gotoxy(5, 5); printf("��"); 
	for (int i = 6; i<66; i++) { gotoxy(i, 5); printf("��");}
	gotoxy(66, 5); printf("��"); gotoxy(5, 12); printf("��");
	for (int i = 6; i < 66; i++) { gotoxy(i, 12); printf("��"); }
	gotoxy(66, 12); printf("��");
	textcolor(FONT_RED); gotoxy(7, 6); printf("ESC  F1  F2  F3  F4  F5  F6  F7  F8  F9  F10  F11  F12"); textcolor(FONT_CYAN);
	gotoxy(8, 7); printf("`   1   2   3   4   5   6   7   8   9   0   -   =  "); textcolor(FONT_RED); printf("��");
	gotoxy(7, 8); printf("Tab  "); textcolor(FONT_CYAN);
	printf("q   w   e   r   t   y   u   i   o   p   [   ]   \\"); textcolor(FONT_RED); 
	gotoxy(7, 9); printf("Caps  "); textcolor(FONT_CYAN);
	printf("a   s   d   f   g   h   j   k   l   ;   '"); textcolor(FONT_RED); printf("  Enter");
	gotoxy(7, 10); printf("Shift  "); textcolor(FONT_CYAN);
	gotoxy(14, 10); printf("z   x   c   v   b   n   m   ,   .   /"); textcolor(FONT_RED); printf("  Shift   ��"); 
	textcolor(FONT_RED); gotoxy(7, 11); printf("Ctrl  ALT              SPACEBAR        ��/��");
	gotoxy(57, 11); printf(" �� �� ��");   // �빮�� Ű����

	int _y = 8; // Ű���� ��� ���縦 ���� y�� ��� ����ϴ� ���� ���� 
	textcolor(FONT_WHITE);
	for (int i = 6 + _y; i < 12 + _y; i++) { gotoxy(5, i); printf("��"); gotoxy(66, i); printf("��"); }
	gotoxy(5, 5 + _y); printf("��");
	for (int i = 6; i < 66; i++) { gotoxy(i, 5 + _y); printf("��"); }
	gotoxy(66, 5 + _y); printf("��"); gotoxy(5, 12 + _y); printf("��");
	for (int i = 6; i < 66; i++) { gotoxy(i, 12 + _y); printf("��"); }
	gotoxy(66, 12 + _y); printf("��");
	textcolor(FONT_RED); gotoxy(7, 6 + _y); printf("ESC  F1  F2  F3  F4  F5  F6  F7  F8  F9  F10  F11  F12"); textcolor(FONT_CYAN);
	gotoxy(8, 7 + _y); printf("~   !   @   #   $   %%   ^   &   *   (   )   _   +  "); textcolor(FONT_RED); printf("��");
	gotoxy(7, 8 + _y); printf("Tab  "); textcolor(FONT_CYAN);
	printf("Q   W   E   R   T   Y   U   I   O   P   {   }   |"); textcolor(FONT_RED);
	gotoxy(7, 9 + _y); printf("Caps  "); textcolor(FONT_CYAN);
	printf("A   S   D   F   G   H   J   K   L   :   \""); textcolor(FONT_RED); printf("  Enter");
	gotoxy(7, 10 + _y); printf("Shift  "); textcolor(FONT_CYAN);
	gotoxy(14, 10 + _y); printf("Z   X   C   V   B   N   M   <   >   ?"); textcolor(FONT_RED); printf("  Shift   ��");
	textcolor(FONT_RED); gotoxy(7, 11 + _y); printf("Ctrl  ALT              SPACEBAR        ��/��");
	gotoxy(57, 11 + _y); printf(" �� �� ��");   // �빮�� Ű����

	
	_y = 16; // y�� ��� �̿�Ǵ� ����
	textcolor(FONT_YELLOW);
	for (int i = 6 + _y; i < 10 + _y; i++) { gotoxy(5, i); printf("��"); gotoxy(40, i); printf("��"); }
	gotoxy(5, 5 + _y); printf("��");
	for (int i = 6; i < 40; i++) { gotoxy(i, 5 + _y); printf("��"); }
	gotoxy(40, 5 + _y); printf("��"); gotoxy(5, 10 + _y); printf("��");
	for (int i = 6; i < 40; i++) { gotoxy(i, 10 + _y); printf("��"); }
	gotoxy(40, 10 + _y); printf("��");
	gotoxy(10, 21); printf("  G U I D E ");
	gotoxy(7, 22); printf("1. �ѱ� ȣȯ X , �ѿ�Ű ��� ����");
	gotoxy(7, 23); printf("2. ��/�ҹ��� �����Ͽ� ���       ");
	gotoxy(7, 24); printf("3. Ű���忡 ���� Ű�� ��� �Ұ�  ");
	gotoxy(7, 25); printf("4. ���Ŀ� �ٽ� ������ �� �ֽ��ϴ�");
	textcolor(FONT_WHITE);
}

void gameIntro()
{
	textcolor(FONT_CYAN);
	gotoxy(20, 15);
	printf("G  "); Sleep(WAIT); printf("A  "); Sleep(WAIT); printf("M  "); Sleep(WAIT);
	printf("E  "); Sleep(WAIT); printf("S  "); Sleep(WAIT); printf("T  "); Sleep(WAIT);
	printf("A  "); Sleep(WAIT); printf("R  "); Sleep(WAIT); printf("T  "); Sleep(WAIT);
	for (int i = 0; i < 5; i++) // �����̴� ȿ��
	{
		gotoxy(20, 15); printf("                         "); Sleep(WAIT + 50);
		gotoxy(20, 15); printf("G  A  M  E  S  T  A  R  T"); Sleep(WAIT + 50);
	}
	textcolor(FONT_WHITE);
}
void userKeySetting()
{
	textcolor(FONT_CYAN);
	gotoxy(20, 15);
	printf("K  "); Sleep(WAIT); printf("E  "); Sleep(WAIT); printf("Y  "); Sleep(WAIT);
	printf("S  "); Sleep(WAIT); printf("E  "); Sleep(WAIT); printf("T  "); Sleep(WAIT);
	printf("T  "); Sleep(WAIT); printf("I  "); Sleep(WAIT); printf("N  "); Sleep(WAIT);
	printf("G  "); Sleep(WAIT);
	for (int i = 0; i < 5; i++) // �����̴� ȿ��
	{
		gotoxy(20, 15); printf("                            "); Sleep(WAIT + 50);
		gotoxy(20, 15); printf("K  E  Y  S  E  T  T  I  N  G"); Sleep(WAIT + 50);
	}
	system("cls");
	printKeyboard(); Sleep(1000);
	while (1)
	{
		textcolor(FONT_WHITE);
		gotoxy(3, 28); printf("û�⸦ �ø��� ��ư�� �Է����ּ���::");
		inputKey.blueUp = keySetting();
		gotoxy(3, 29);
		if (keyUseable(inputKey.blueUp) == TRUE)
		{
			printf("�Է��Ͻ� Ű�� "); putchar(inputKey.blueUp); printf(" �Դϴ�");
			pause(); gotoxy(3, 29); printBlank(70);
			break;
		}
		else { gotoxy(3, 29); printf("�ùٸ� Ű�� �ƴմϴ�!! �ٽ� �Է����ּ���"); }
		pause(); gotoxy(3, 29); printBlank(50); gotoxy(3, 30); printBlank(50);
	}
	textcolor(FONT_CYAN); gotoxy(43, 22); printf("û�� �� : %c", inputKey.blueUp); textcolor(FONT_WHITE);
	while (1)// ��ư�� �ߺ����� �ʰ� �˻��Ͽ�, �ߺ��� �ٽ� �Է¹ް� ��
	{
		gotoxy(3, 28); printf("û�⸦ ������ ��ư�� �Է����ּ���::");
		inputKey.blueDown = keySetting();
		if (keyUseable(inputKey.blueDown) == TRUE)
		{
			gotoxy(3, 29); printf("�Է��Ͻ� Ű�� "); putchar(inputKey.blueDown); printf(" �Դϴ�");
			if (inputKey.blueDown == inputKey.blueUp)
			{
				gotoxy(3, 30); printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���");
			}
			else
			{
				pause(); gotoxy(3, 29); printBlank(70);	break;
			}
		}
		else { gotoxy(3, 29); printf("�ùٸ� Ű�� �ƴմϴ�!! �ٽ� �Է��� �ּ���"); }
		pause(); gotoxy(3, 29); printBlank(50); gotoxy(3, 30); printBlank(50);
	}
	textcolor(FONT_CYAN); gotoxy(43, 24); printf("û�� �� : %c", inputKey.blueDown); textcolor(FONT_WHITE);
	while (1)
	{
		gotoxy(3, 28); printf("��⸦ �ø��� ��ư�� �Է����ּ���::");
		inputKey.whiteUp = keySetting();
		if (keyUseable(inputKey.whiteUp) == TRUE)
		{
			gotoxy(3, 29); printf("�Է��Ͻ� Ű�� "); putchar(inputKey.whiteUp); printf(" �Դϴ�");
			if (inputKey.whiteUp == inputKey.blueUp || inputKey.whiteUp == inputKey.blueDown)
			{
				gotoxy(3, 30); printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���");
			}
			else
			{
				pause(); gotoxy(3, 29); printBlank(70);	break;
			}
		}
		else { gotoxy(3, 29); printf("�ùٸ� Ű�� �ƴմϴ�!! �ٽ� �Է��� �ּ���"); }
		pause(); gotoxy(3, 29); printBlank(50); gotoxy(3, 30); printBlank(50);
	}
	textcolor(FONT_WHITE); gotoxy(55, 22); printf("��� �� : %c", inputKey.whiteUp); textcolor(FONT_WHITE);
	while (1)
	{
		gotoxy(3, 28); printf("��⸦ ������ ��ư�� �Է����ּ���::");
		inputKey.whiteDown = keySetting();
		if (keyUseable(inputKey.whiteDown) == TRUE)
		{
			gotoxy(3, 29); printf("�Է��Ͻ� Ű�� "); putchar(inputKey.whiteDown); printf(" �Դϴ�");
			if (inputKey.whiteDown == inputKey.blueUp || inputKey.whiteDown == inputKey.blueDown || inputKey.whiteDown == inputKey.whiteUp)
			{
				gotoxy(3, 29); printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���");
			}
			else
			{
				pause();
				break;
			}
		}
		else { gotoxy(3, 30); printf("�ùٸ� Ű�� �ƴմϴ�!! �ٽ� �Է��� �ּ���"); }
		pause(); gotoxy(3, 29); printBlank(50); gotoxy(3, 30); printBlank(50);
	}
	textcolor(FONT_WHITE); gotoxy(55, 24); printf("��� �� : %c", inputKey.whiteDown); textcolor(FONT_WHITE);
	pause(); system("cls");
	textcolor(FONT_CYAN);
	for (int i = 0; i < 5; i++) // �����̴� ȿ��
	{
		gotoxy(20, 15); printf("K  E  Y  S  E  T  T  I  N  G"); 
		gotoxy(20, 17); printf("C  O  M  P  L  E  T  E  !  !"); Sleep(WAIT + 150);
		gotoxy(20, 15); printf("                            "); 
		gotoxy(20, 17); printf("                            "); Sleep(WAIT + 150);
	}
	textcolor(FONT_WHITE);
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
	textcolor(FONT_WHITE);
	if (menuNumber == 1) { textcolor(FONT_YELLOW); }
	gotoxy(25, 20); printf("1.G A M E S T A R T");
	textcolor(FONT_WHITE);
	if (menuNumber == 2) { textcolor(FONT_YELLOW); }
	gotoxy(25, 21); printf("2.K E Y S E T T I N G");
	textcolor(FONT_WHITE);
	if (menuNumber == 3) { textcolor(FONT_YELLOW); }
	gotoxy(25, 22); printf("3.R A N K I N G");
	textcolor(FONT_WHITE);
	if (menuNumber == 4) { textcolor(FONT_YELLOW); }
	gotoxy(25, 23); printf("4.E X I T");
	textcolor(FONT_WHITE);
}

int choiceMenu()
{  
	int move = 0;
	move = getKey();
		if (move == 224)
		{
			move = getKey();
			if (move == 72)
			{
				if (menuNumber>1)
				{
					menuNumber--;
					return NOTHING;
				}
				else return NOTHING;
			}
			if (move == 80)
			{
				if (menuNumber < 4)
				{
					menuNumber++;
					return NOTHING;
				}
				else return NOTHING;
			}
			else return NOTHING;
		}
		else if (move == SPACEBAR)
		{
			move = getKey(); // �ڿ� 0����Ʈ�� ������.
			return menuNumber;
		}
		else return NOTHING;
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

void settingWarning()
{
	for (int i = 0; i < 5;i ++)
	{
		gotoxy(22, 15); textcolor(FONT_RED); printf("W  A  R  N  I  N  G  !  !  !"); Sleep(WAIT+100);
		gotoxy(22, 15); textcolor(FONT_RED); printf("                            "); Sleep(WAIT+100);
	}
	gotoxy(15, 15); textcolor(FONT_WHITE); printf("�ʱ� Ű������ �ؾ� ������ ������ �� �ֽ��ϴ�!");
}

bool keyUseable(int inputKey)
{
	if (33 <= inputKey && inputKey <= 126)
		return true;
	else return false;
}