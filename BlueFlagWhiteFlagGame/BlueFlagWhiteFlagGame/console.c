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

int keySetting() //  두번째 바이트는 버리는 숫자입력
{
	int key;
	key = getKey();
	getKey();
	return key;
}

void userKeySetting()
{
	gotoxy(20, 28); printf("청기를 올리는 버튼을 입력해주세요::");
	inputKey.blueUp = keySetting();
	gotoxy(20, 29); printf("입력하신 키는 "); putchar(inputKey.blueUp); printf(" 입니다");
	while (1)// 버튼이 중복되지 않게 검사하여, 중복시 다시 입력받게 하는 로직
	{
		system("cls");
		gotoxy(20, 28);printf("청기를 내리는 버튼을 입력해주세요::");
		inputKey.blueDown = keySetting();
		gotoxy(20, 29);printf("입력하신 키는 "); putchar(inputKey.blueDown); printf(" 입니다");
		if (inputKey.blueDown == inputKey.blueUp)
		{
			gotoxy(20, 30);printf("중복된 키를 선택하셨습니다. 다시 입력해주세요");
		}
		else break;
	}
	while (1)
	{
		system("cls");
		gotoxy(20, 28); printf("백기를 올리는 버튼을 입력해주세요::");
		inputKey.whiteUp = keySetting();
		gotoxy(20, 29); printf("입력하신 키는 "); putchar(inputKey.whiteUp); printf(" 입니다");
		if (inputKey.whiteUp == inputKey.blueUp || inputKey.whiteUp == inputKey.blueDown)
		{
			gotoxy(20, 30);printf("중복된 키를 선택하셨습니다. 다시 입력해주세요");
		}
		else break;
	}
	while (1)
	{
		system("cls");
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
	// 기존의 가만히 있는 청기백기 지우기
	//if (flagSwitch == inputKey.blueUp || flagSwitch == inputKey.blueDown || flagSwitch == inputKey.whiteUp || flagSwitch == inputKey.whiteDown)
	//{
	//	gotoxy(11, 26); printBlank(1); gotoxy(10, 25); printBlank(3);
	//	gotoxy(9, 24); printBlank(5); gotoxy(8, 23); printBlank(7); gotoxy(8, 22); printBlank(12); //왼쪽 청기 그린것 지우기
	//	gotoxy(57, 26); printBlank(1); gotoxy(56, 25); printBlank(3);
	//	gotoxy(55, 24); printBlank(5); gotoxy(54, 23); printBlank(7); gotoxy(49, 22); printBlank(12); //오른쪽 백기 그린것 지우기
	//}
	
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

