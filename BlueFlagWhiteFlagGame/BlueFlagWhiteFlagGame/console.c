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

int keySetting() //  두번째 바이트는 버리는 숫자입력
{
	int key;	
	key = getKey();
	getKey();
	return key;
}

void printKeyboard()
{
	textcolor(FONT_WHITE);
	for (int i = 6; i < 12; i++) { gotoxy(5, i); printf("┃"); gotoxy(66, i); printf("┃"); }
	gotoxy(5, 5); printf("┏"); 
	for (int i = 6; i<66; i++) { gotoxy(i, 5); printf("━");}
	gotoxy(66, 5); printf("┓"); gotoxy(5, 12); printf("┗");
	for (int i = 6; i < 66; i++) { gotoxy(i, 12); printf("━"); }
	gotoxy(66, 12); printf("┛");
	textcolor(FONT_RED); gotoxy(7, 6); printf("ESC  F1  F2  F3  F4  F5  F6  F7  F8  F9  F10  F11  F12"); textcolor(FONT_CYAN);
	gotoxy(8, 7); printf("`   1   2   3   4   5   6   7   8   9   0   -   =  "); textcolor(FONT_RED); printf("←");
	gotoxy(7, 8); printf("Tab  "); textcolor(FONT_CYAN);
	printf("q   w   e   r   t   y   u   i   o   p   [   ]   \\"); textcolor(FONT_RED); 
	gotoxy(7, 9); printf("Caps  "); textcolor(FONT_CYAN);
	printf("a   s   d   f   g   h   j   k   l   ;   '"); textcolor(FONT_RED); printf("  Enter");
	gotoxy(7, 10); printf("Shift  "); textcolor(FONT_CYAN);
	gotoxy(14, 10); printf("z   x   c   v   b   n   m   ,   .   /"); textcolor(FONT_RED); printf("  Shift   ↑"); 
	textcolor(FONT_RED); gotoxy(7, 11); printf("Ctrl  ALT              SPACEBAR        한/영");
	gotoxy(57, 11); printf(" ← ↓ →");   // 대문자 키보드

	int copy = 8; // 키보드 모양 복사를 위한 y축 제어에 사용하는 지역 변수 
	textcolor(FONT_WHITE);
	for (int i = 6 + copy; i < 12 + copy; i++) { gotoxy(5, i); printf("┃"); gotoxy(66, i); printf("┃"); }
	gotoxy(5, 5 + copy); printf("┏");
	for (int i = 6; i < 66; i++) { gotoxy(i, 5 + copy); printf("━"); }
	gotoxy(66, 5 + copy); printf("┓"); gotoxy(5, 12 + copy); printf("┗");
	for (int i = 6; i < 66; i++) { gotoxy(i, 12 + copy); printf("━"); }
	gotoxy(66, 12 + copy); printf("┛");
	textcolor(FONT_RED); gotoxy(7, 6 + copy); printf("ESC  F1  F2  F3  F4  F5  F6  F7  F8  F9  F10  F11  F12"); textcolor(FONT_CYAN);
	gotoxy(8, 7 + copy); printf("~   !   @   #   $   %%   ^   &   *   (   )   _   +  "); textcolor(FONT_RED); printf("←");
	gotoxy(7, 8 + copy); printf("Tab  "); textcolor(FONT_CYAN);
	printf("Q   W   E   R   T   Y   U   I   O   P   {   }   |"); textcolor(FONT_RED);
	gotoxy(7, 9 + copy); printf("Caps  "); textcolor(FONT_CYAN);
	printf("A   S   D   F   G   H   J   K   L   :   \""); textcolor(FONT_RED); printf("  Enter");
	gotoxy(7, 10 + copy); printf("Shift  "); textcolor(FONT_CYAN);
	gotoxy(14, 10 + copy); printf("Z   X   C   V   B   N   M   <   >   ?"); textcolor(FONT_RED); printf("  Shift   ↑");
	textcolor(FONT_RED); gotoxy(7, 11 + copy); printf("Ctrl  ALT              SPACEBAR        한/영");
	gotoxy(57, 11 + copy); printf(" ← ↓ →");   // 대문자 키보드
}

void userKeySetting()
{
	textcolor(FONT_CYAN);
	gotoxy(20, 15);
	printf("K  "); Sleep(WAIT); printf("E  "); Sleep(WAIT); printf("Y  "); Sleep(WAIT);
	printf("S  "); Sleep(WAIT); printf("E  "); Sleep(WAIT); printf("T  "); Sleep(WAIT);
	printf("T  "); Sleep(WAIT); printf("I  "); Sleep(WAIT); printf("N  "); Sleep(WAIT);
	printf("G  "); Sleep(WAIT);
	for (int i = 0; i < 5; i++) // 깜빡이는 효과
	{
		gotoxy(20, 15); printf("                            "); Sleep(WAIT + 50);
		gotoxy(20, 15); printf("K  E  Y  S  E  T  T  I  N  G"); Sleep(WAIT + 50);
	}
	system("cls");
	gotoxy(6, 3); textcolor(FONT_CYAN); printf(" 파란색 "); textcolor(FONT_WHITE); printf("사용 가능한 키");
	gotoxy(42, 3);textcolor(FONT_RED); printf(" 빨간색 "); textcolor(FONT_WHITE); printf("사용 불가능한 키");
	printKeyboard();
	Sleep(1000);
	textcolor(FONT_WHITE);
	while (1)
	{
		gotoxy(20, 28); printf("청기를 올리는 버튼을 입력해주세요::");
		inputKey.blueUp = keySetting();
		gotoxy(20, 29);
		if (keyUseable(inputKey.blueUp) == TRUE)
		{
			printf("입력하신 키는 "); putchar(inputKey.blueUp); printf(" 입니다");
			break;
		}
		else printf("올바른 키가 아닙니다!!");
	}
	while (1)// 버튼이 중복되지 않게 검사하여, 중복시 다시 입력받게 함
	{
		gotoxy(20, 28); printf("청기를 내리는 버튼을 입력해주세요::");
		inputKey.blueDown = keySetting();
		gotoxy(20, 29); printf("입력하신 키는 "); putchar(inputKey.blueDown); printf(" 입니다");
		if (inputKey.blueDown == inputKey.blueUp)
		{
			gotoxy(20, 30); printf("중복된 키를 선택하셨습니다. 다시 입력해주세요");
		}
		else break;
	}
	while (1)
	{
		gotoxy(20, 28); printf("백기를 올리는 버튼을 입력해주세요::");
		inputKey.whiteUp = keySetting();
		gotoxy(20, 29); printf("입력하신 키는 "); putchar(inputKey.whiteUp); printf(" 입니다");
		if (inputKey.whiteUp == inputKey.blueUp || inputKey.whiteUp == inputKey.blueDown)
		{
			gotoxy(20, 30); printf("중복된 키를 선택하셨습니다. 다시 입력해주세요");
		}
		else break;
	}
	while (1)
	{
		gotoxy(20, 28); printf("백기를 내리는 버튼을 입력해주세요::");
		inputKey.whiteDown = keySetting();
		gotoxy(20, 29);printf("입력하신 키는 "); putchar(inputKey.whiteDown); printf(" 입니다");
		if (inputKey.whiteDown == inputKey.blueUp || inputKey.whiteDown == inputKey.blueDown || inputKey.whiteDown == inputKey.whiteUp)
		{
			gotoxy(20, 30);printf("중복된 키를 선택하셨습니다. 다시 입력해주세요");
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
	for (int i = 0;i < stageStatus.life;i++) printf("♥");
	for (int i = 0;i < 5 - stageStatus.life;i++) printf("♡");
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
	for (int i = 0;i < stageStatus.life;i++) printf("♥");
	for (int i = 0;i < 5 - stageStatus.life;i++) printf("♡");
	gotoxy(55, 1);
	textcolor(FONT_YELLOW);
	printf("SCORE : %d", stageStatus.score);
	textcolor(FONT_BLUE);
	gotoxy(15, 5);
	printf("청기↑ : %c", inputKey.blueUp);
	gotoxy(15, 6);
	printf("청기↓ : %c", inputKey.blueDown);
	textcolor(FONT_WHITE);
	gotoxy(40, 5);
	printf("백기↑ : %c", inputKey.whiteUp);
	gotoxy(40, 6);
	printf("백기↓ : %c", inputKey.whiteDown);   // 기본 화면 UI 출력

	gotoxy(22, 10);
	textcolor(FONT_YELLOW);
	printf("%s ", stageStatus._blueOrWhite[0]);
	textcolor(FONT_WHITE);
	printf("%s ", stageStatus._frontQuestion[0]);
	textcolor(FONT_YELLOW);
	printf("%s ", stageStatus._blueOrWhite[1]);
	textcolor(FONT_WHITE);
	printf("%s ", stageStatus._backQuestion[0]); // 문제 출력
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
	gotoxy(8, 22); printDot(12); //왼쪽 청기 그린것
	
	
	textcolor(FONT_YELLOW);
	gotoxy(20, 22); printDot(29);
	gotoxy(31, 15); printDot(7);
	gotoxy(30, 16); printDot(1); gotoxy(38, 16); printDot(1);
	gotoxy(29, 17); printDot(1); gotoxy(39, 17); printDot(1);
	if (emotion == DEFAULT)
	{
		gotoxy(31, 17); printf("■"); gotoxy(35, 17);printf("■"); //눈
		gotoxy(33, 19);printf("▽"); // 평소 표정
	}
	if (emotion == HAPPY)
	{
		gotoxy(31, 17); printf("Λ"); gotoxy(35, 17);printf("Λ"); //눈
		gotoxy(33, 19);printf("▽"); // 맞춘 경우
	}
	if (emotion == SAD)
	{
		gotoxy(31, 17); printf("ㅠ"); gotoxy(35, 17);printf("ㅠ"); //눈
		gotoxy(33, 19); printf("ㅡ"); // 틀린 경우
	}
	gotoxy(29, 18); printDot(1); gotoxy(39, 18); printDot(1);
	gotoxy(30, 19); printDot(1); gotoxy(38, 19); printDot(1);
	gotoxy(31, 20); printDot(7);
	gotoxy(34, 21); printDot(1);
	for (int i = 22; i < 31;i++) { gotoxy(32, i); printDot(5); }  // 사람 그린것
	textcolor(FONT_WHITE);
	gotoxy(57, 26); printDot(1);
	gotoxy(56, 25); printDot(3);
	gotoxy(55, 24); printDot(5);
	gotoxy(54, 23); printDot(7);
	gotoxy(49, 22); printDot(12); //오른쪽 백기 그린것
}

void moveFlag(int flagSwitch)
{
	if (flagSwitch == inputKey.blueUp) // 청기 올리는 것 도트 찍기 청기 내릴때 올리는 건 blank로 다시출력.
	{
		textcolor(FONT_BLUE);
		gotoxy(11, 26); printBlank(1); gotoxy(10, 25); printBlank(3);
		gotoxy(9, 24); printBlank(5); gotoxy(8, 23); printBlank(7); gotoxy(8, 22); printBlank(12); // 기존청기 지우기

		for (int i = 22; i < 31; i++) { gotoxy(20, i); printBlank(1); }
		for (int i = 26; i < 31; i++) { gotoxy(17, i); printBlank(3); }
		for (int i = 27; i < 30; i++) { gotoxy(14, i); printBlank(3); }
		for (int i = 28; i < 29; i++) { gotoxy(13, i); printBlank(1); } // 청기 내린거 지움

		for (int i = 22; i > 13; i--) { gotoxy(20, i); printDot(1); }
		for (int i = 14; i < 19; i++) { gotoxy(17, i); printDot(3); }
		for (int i = 15; i < 18; i++) { gotoxy(14, i); printDot(3); }
		for (int i = 16; i < 17; i++) { gotoxy(13, i); printDot(1); }
		textcolor(FONT_WHITE);
	}
	if (flagSwitch == inputKey.whiteUp) // 백기 올리는 것
	{
		gotoxy(57, 26); printBlank(1); gotoxy(56, 25); printBlank(3);
		gotoxy(55, 24); printBlank(5); gotoxy(54, 23); printBlank(7); gotoxy(49, 22); printBlank(12);//기존 백기 지우기
		textcolor(FONT_WHITE);
		for (int i = 22; i < 31; i++) { gotoxy(48, i); printBlank(1); }
		for (int i = 26; i < 31; i++) { gotoxy(49, i); printBlank(3); }
		for (int i = 27; i < 30; i++) { gotoxy(52, i); printBlank(3); }
		for (int i = 28; i < 29; i++) { gotoxy(55, i); printBlank(1); } // 백기 내린거 지움

		for (int i = 22; i > 13; i--) { gotoxy(48, i); printDot(1); }
		for (int i = 14; i < 19; i++) { gotoxy(49, i); printDot(3); }
		for (int i = 15; i < 18; i++) { gotoxy(52, i); printDot(3); }
		for (int i = 16; i < 17; i++) { gotoxy(55, i); printDot(1); }
	}
	if (flagSwitch == inputKey.blueDown) // 청기 내리는 것
	{
		gotoxy(11, 26); printBlank(1); gotoxy(10, 25); printBlank(3);
		gotoxy(9, 24); printBlank(5); gotoxy(8, 23); printBlank(7); gotoxy(8, 22); printBlank(12);//기존 청기 지우기

		textcolor(FONT_BLUE);
		for (int i = 22; i > 13; i--) { gotoxy(20, i); printBlank(1); }
		for (int i = 14; i < 19; i++) { gotoxy(17, i); printBlank(3); }
		for (int i = 15; i < 18; i++) { gotoxy(14, i); printBlank(3); }
		for (int i = 16; i < 17; i++) { gotoxy(13, i); printBlank(1); } // 청기 올렸을경우 지움
		
		for (int i = 22; i < 31; i++) { gotoxy(20, i); printDot(1); }
		for (int i = 26; i < 31; i++) { gotoxy(17, i); printDot(3); }
		for (int i = 27; i < 30; i++) { gotoxy(14, i); printDot(3); }
		for (int i = 28; i < 29; i++) { gotoxy(13, i); printDot(1); } // 청기 내림
		textcolor(FONT_WHITE);
	}
	if (flagSwitch == inputKey.whiteDown) // 백기 내리는 것
	{
		gotoxy(57, 26); printBlank(1); gotoxy(56, 25); printBlank(3);
		gotoxy(55, 24); printBlank(5); gotoxy(54, 23); printBlank(7); gotoxy(49, 22); printBlank(12); // 기존 백기 지우기
		textcolor(FONT_WHITE);
		for (int i = 22; i > 13; i--) { gotoxy(48, i); printBlank(1); }
		for (int i = 14; i < 19; i++) { gotoxy(49, i); printBlank(3); }
		for (int i = 15; i < 18; i++) { gotoxy(52, i); printBlank(3); }
		for (int i = 16; i < 17; i++) { gotoxy(55, i); printBlank(1); }

		for (int i = 22; i < 31; i++) { gotoxy(48, i); printDot(1); }
		for (int i = 26; i < 31; i++) { gotoxy(49, i); printDot(3); }
		for (int i = 27; i < 30; i++) { gotoxy(52, i); printDot(3); }
		for (int i = 28; i < 29; i++) { gotoxy(55, i); printDot(1); } // 백기 내림
	}
}

void clearFlag()
{
	//청기 내린거 지움
	for (int i = 22; i < 31; i++) { gotoxy(20, i); printBlank(1); }
	for (int i = 26; i < 31; i++) { gotoxy(17, i); printBlank(3); }
	for (int i = 27; i < 30; i++) { gotoxy(14, i); printBlank(3); }
	for (int i = 28; i < 29; i++) { gotoxy(13, i); printBlank(1); }
	//백기 내린거 지움
	for (int i = 22; i < 31; i++) { gotoxy(48, i); printBlank(1); }
	for (int i = 26; i < 31; i++) { gotoxy(49, i); printBlank(3); }
	for (int i = 27; i < 30; i++) { gotoxy(52, i); printBlank(3); }
	for (int i = 28; i < 29; i++) { gotoxy(55, i); printBlank(1); }
	//청기 올린거 지움
	for (int i = 22; i > 13; i--) { gotoxy(20, i); printBlank(1); }
	for (int i = 14; i < 19; i++) { gotoxy(17, i); printBlank(3); }
	for (int i = 15; i < 18; i++) { gotoxy(14, i); printBlank(3); }
	for (int i = 16; i < 17; i++) { gotoxy(13, i); printBlank(1); }
	//백기 올린거 지움
	for (int i = 22; i > 13; i--) { gotoxy(48, i); printBlank(1); }
	for (int i = 14; i < 19; i++) { gotoxy(49, i); printBlank(3); }
	for (int i = 15; i < 18; i++) { gotoxy(52, i); printBlank(3); }
	for (int i = 16; i < 17; i++) { gotoxy(55, i); printBlank(1); }
}

void settingWarning()
{
	gotoxy(22, 15); textcolor(FONT_RED); printf("W  A  R  N  I  N  G  !  !  !");
	gotoxy(15, 16); textcolor(FONT_CYAN); printf("초기 키셋팅을 해야 게임을 시작할 수 있습니다!");
}

bool keyUseable(int inputKey)
{
	if (33 <= inputKey && inputKey <= 126)
		return true;
	else return false;
}