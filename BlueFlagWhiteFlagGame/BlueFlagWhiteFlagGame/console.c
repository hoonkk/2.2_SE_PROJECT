#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")



#include "console.h"



#define WAIT 50
#define ENTER 13

#define NOTHING 0


#define BEEP 0
#define MENUMOVE 2
#define GAMESTART 3
#define SWING 4
#define KeySetComplete 7


#define BEEPSOUND "sound\\CursorBeep.wav"
#define MISSSOUND "sound\\MISS.wav"
#define MENUMOVESOUND "sound\\MenuMove.wav"
#define GAMESTARTSOUND "sound\\GameStart.wav"
#define SWINGSOUND "sound\\Swing.wav"
#define GAMEOVERSOUND "sound\\GameOver.wav"
#define GOODSOUND "sound\\GOOD.wav"
#define KeySetCompleteSound "sound\\KeySetComplete.wav"
#define CLEARSOUND "sound\\CLEAR.wav"




int menuNumber = 1;
void pause()
{
	int check = 0;
	while (1)
	{
		check = getKey();
		if (check == ENTER)
		{
			getKey();
			playSound(BEEP);
			break;
		}
	}
}

void playSound(int soundIndex)
{
	if(soundIndex==BEEP)
		PlaySound(TEXT(BEEPSOUND), NULL, SND_FILENAME | SND_ASYNC | 0);
	if(soundIndex==MISS)
		PlaySound(TEXT(MISSSOUND), NULL, SND_FILENAME | SND_ASYNC | 0);
	if(soundIndex==MENUMOVE)
		PlaySound(TEXT(MENUMOVESOUND), NULL, SND_FILENAME | SND_ASYNC | 0);
	if(soundIndex==GAMESTART)
		PlaySound(TEXT(GAMESTARTSOUND), NULL, SND_FILENAME | SND_ASYNC | 0);
	if(soundIndex==SWING)
		PlaySound(TEXT(SWINGSOUND), NULL, SND_FILENAME | SND_ASYNC | 0);
	if (soundIndex == GAMEOVER)
		PlaySound(TEXT(GAMEOVERSOUND), NULL, SND_FILENAME | SND_ASYNC | 0);
	if(soundIndex==GOOD)
		PlaySound(TEXT(GOODSOUND), NULL, SND_FILENAME | SND_ASYNC | 0);
	if (soundIndex == KeySetComplete)
		PlaySound(TEXT(KeySetCompleteSound), NULL, SND_FILENAME | SND_ASYNC | 0);
	if (soundIndex == CLEAR)
		PlaySound(TEXT(CLEARSOUND), NULL, SND_FILENAME | SND_ASYNC | 0);
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

void printDot_(int number)
{
	for (int i = 0; i < number;i++)
		printf("#");
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
	gotoxy(6, 3); textcolor(FONT_CYAN); printf(" 파란색 "); textcolor(FONT_WHITE); printf("사용 가능한 키");
	gotoxy(42, 3);textcolor(FONT_RED); printf(" 빨간색 "); textcolor(FONT_WHITE); printf("사용 불가능한 키");
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

	int _y = 8; // 키보드 모양 복사를 위한 y축 제어에 사용하는 지역 변수 
	textcolor(FONT_WHITE);
	for (int i = 6 + _y; i < 12 + _y; i++) { gotoxy(5, i); printf("┃"); gotoxy(66, i); printf("┃"); }
	gotoxy(5, 5 + _y); printf("┏");
	for (int i = 6; i < 66; i++) { gotoxy(i, 5 + _y); printf("━"); }
	gotoxy(66, 5 + _y); printf("┓"); gotoxy(5, 12 + _y); printf("┗");
	for (int i = 6; i < 66; i++) { gotoxy(i, 12 + _y); printf("━"); }
	gotoxy(66, 12 + _y); printf("┛");
	textcolor(FONT_RED); gotoxy(7, 6 + _y); printf("ESC  F1  F2  F3  F4  F5  F6  F7  F8  F9  F10  F11  F12"); textcolor(FONT_CYAN);
	gotoxy(8, 7 + _y); printf("~   !   @   #   $   %%   ^   &   *   (   )   _   +  "); textcolor(FONT_RED); printf("←");
	gotoxy(7, 8 + _y); printf("Tab  "); textcolor(FONT_CYAN);
	printf("Q   W   E   R   T   Y   U   I   O   P   {   }   |"); textcolor(FONT_RED);
	gotoxy(7, 9 + _y); printf("Caps  "); textcolor(FONT_CYAN);
	printf("A   S   D   F   G   H   J   K   L   :   \""); textcolor(FONT_RED); printf("  Enter");
	gotoxy(7, 10 + _y); printf("Shift  "); textcolor(FONT_CYAN);
	gotoxy(14, 10 + _y); printf("Z   X   C   V   B   N   M   <   >   ?"); textcolor(FONT_RED); printf("  Shift   ↑");
	textcolor(FONT_RED); gotoxy(7, 11 + _y); printf("Ctrl  ALT              SPACEBAR        한/영");
	gotoxy(57, 11 + _y); printf(" ← ↓ →");   // 대문자 키보드

	
	_y = 16; // y축 제어에 이용되는 변수
	textcolor(FONT_YELLOW);
	for (int i = 6 + _y; i < 10 + _y; i++) { gotoxy(5, i); printf("┃"); gotoxy(40, i); printf("┃"); }
	gotoxy(5, 5 + _y); printf("┏");
	for (int i = 6; i < 40; i++) { gotoxy(i, 5 + _y); printf("━"); }
	gotoxy(40, 5 + _y); printf("┓"); gotoxy(5, 10 + _y); printf("┗");
	for (int i = 6; i < 40; i++) { gotoxy(i, 10 + _y); printf("━"); }
	gotoxy(40, 10 + _y); printf("┛");
	gotoxy(10, 21); printf("  G U I D E ");
	gotoxy(7, 22); printf("1. 한글 호환 X , 한영키 사용 금지");
	gotoxy(7, 23); printf("2. 대/소문자 구분하여 사용       ");
	gotoxy(7, 24); printf("3. 키보드에 없는 키는 사용 불가  ");
	gotoxy(7, 25); printf("4. 차후에 다시 변경할 수 있습니다");
	textcolor(FONT_WHITE);
}

void gameIntro()
{
	textcolor(FONT_CYAN);
	gotoxy(23, 15);
	playSound(GAMESTART);
	printf("G  "); Sleep(WAIT); printf("A  "); Sleep(WAIT); printf("M  "); Sleep(WAIT);
	printf("E  "); Sleep(WAIT); printf("S  "); Sleep(WAIT); printf("T  "); Sleep(WAIT);
	printf("A  "); Sleep(WAIT); printf("R  "); Sleep(WAIT); printf("T  "); Sleep(WAIT);
	for (int i = 0; i < 5; i++) // 깜빡이는 효과
	{
		gotoxy(23, 15); printf("                         "); Sleep(WAIT + 50);
		gotoxy(23, 15); printf("G  A  M  E  S  T  A  R  T"); Sleep(WAIT + 50);
	}
	textcolor(FONT_WHITE);
}
void userKeySetting()
{
	textcolor(FONT_CYAN);
	gotoxy(20, 15);
	playSound(KeySetComplete);
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
	printKeyboard();
	while (1)
	{
		textcolor(FONT_WHITE);
		gotoxy(3, 28); printf("청기를 올리는 버튼을 입력해주세요::");
		inputKey.blueUp = keySetting();
		gotoxy(3, 29);
		if (keyUseable(inputKey.blueUp) == TRUE)
		{
			printf("입력하신 키는 "); putchar(inputKey.blueUp); printf(" 입니다");
			pause(); gotoxy(3, 29); printBlank(70);
			break;
		}
		else { gotoxy(3, 29); printf("올바른 키가 아닙니다!! 다시 입력해주세요"); }
		pause(); gotoxy(3, 29); printBlank(50); gotoxy(3, 30); printBlank(50);
	}
	textcolor(FONT_CYAN); gotoxy(43, 22); printf("청기 ↑ : %c", inputKey.blueUp); textcolor(FONT_WHITE);
	while (1)// 버튼이 중복되지 않게 검사하여, 중복시 다시 입력받게 함
	{
		gotoxy(3, 28); printf("청기를 내리는 버튼을 입력해주세요::");
		inputKey.blueDown = keySetting();
		if (keyUseable(inputKey.blueDown) == TRUE)
		{
			gotoxy(3, 29); printf("입력하신 키는 "); putchar(inputKey.blueDown); printf(" 입니다");
			if (inputKey.blueDown == inputKey.blueUp)
			{
				gotoxy(3, 30); printf("중복된 키를 선택하셨습니다. 다시 입력해주세요");
			}
			else
			{
				pause(); gotoxy(3, 29); printBlank(70);	break;
			}
		}
		else { gotoxy(3, 29); printf("올바른 키가 아닙니다!! 다시 입력해 주세요"); }
		pause(); gotoxy(3, 29); printBlank(50); gotoxy(3, 30); printBlank(50);
	}
	textcolor(FONT_CYAN); gotoxy(43, 24); printf("청기 ↓ : %c", inputKey.blueDown); textcolor(FONT_WHITE);
	while (1)
	{
		gotoxy(3, 28); printf("백기를 올리는 버튼을 입력해주세요::");
		inputKey.whiteUp = keySetting();
		if (keyUseable(inputKey.whiteUp) == TRUE)
		{
			gotoxy(3, 29); printf("입력하신 키는 "); putchar(inputKey.whiteUp); printf(" 입니다");
			if (inputKey.whiteUp == inputKey.blueUp || inputKey.whiteUp == inputKey.blueDown)
			{
				gotoxy(3, 30); printf("중복된 키를 선택하셨습니다. 다시 입력해주세요");
			}
			else
			{
				pause(); gotoxy(3, 29); printBlank(70);	break;
			}
		}
		else { gotoxy(3, 29); printf("올바른 키가 아닙니다!! 다시 입력해 주세요"); }
		pause(); gotoxy(3, 29); printBlank(50); gotoxy(3, 30); printBlank(50);
	}
	textcolor(FONT_WHITE); gotoxy(55, 22); printf("백기 ↑ : %c", inputKey.whiteUp); textcolor(FONT_WHITE);
	while (1)
	{
		gotoxy(3, 28); printf("백기를 내리는 버튼을 입력해주세요::");
		inputKey.whiteDown = keySetting();
		if (keyUseable(inputKey.whiteDown) == TRUE)
		{
			gotoxy(3, 29); printf("입력하신 키는 "); putchar(inputKey.whiteDown); printf(" 입니다");
			if (inputKey.whiteDown == inputKey.blueUp || inputKey.whiteDown == inputKey.blueDown || inputKey.whiteDown == inputKey.whiteUp)
			{
				gotoxy(3, 29); printf("중복된 키를 선택하셨습니다. 다시 입력해주세요");
			}
			else
			{
				pause();
				break;
			}
		}
		else { gotoxy(3, 30); printf("올바른 키가 아닙니다!! 다시 입력해 주세요"); }
		pause(); gotoxy(3, 29); printBlank(50); gotoxy(3, 30); printBlank(50);
	}
	textcolor(FONT_WHITE); gotoxy(55, 24); printf("백기 ↓ : %c", inputKey.whiteDown); textcolor(FONT_WHITE);
	pause(); system("cls");
	textcolor(FONT_CYAN);
	for (int i = 0; i < 5; i++) // 깜빡이는 효과
	{
		playSound(KeySetComplete);
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
	gotoxy(50, 1);
	printf("LIFE : ");
	for (int i = 0;i < stageStatus.life;i++) printf("♥");
	for (int i = 0;i < 5 - stageStatus.life;i++) printf("♡");
	gotoxy(0, 2); textcolor(FONT_WHITE); 
	for (int i = 0; i < 70; i++) printf("━");
	textcolor(FONT_WHITE);
	printCharactor(DEFAULT);
}

void updateShow()
{
	textcolor(FONT_YELLOW);
	gotoxy(5, 1);
	printf("STAGE : %d", stageStatus.stage);
	gotoxy(50, 1);
	textcolor(FONT_RED);
	printf("LIFE : ");
	for (int i = 0;i < stageStatus.life;i++) printf("♥");
	for (int i = 0;i < 5 - stageStatus.life;i++) printf("♡");
	gotoxy(0, 2); textcolor(FONT_WHITE);
	for (int i = 0; i < 70; i ++) printf("━");
	textcolor(FONT_CYAN);
	gotoxy(15, 5);
	printf("청기↑ : %c", inputKey.blueUp);
	gotoxy(15, 6);
	printf("청기↓ : %c", inputKey.blueDown);
	textcolor(FONT_WHITE);
	gotoxy(40, 5);
	printf("백기↑ : %c", inputKey.whiteUp);
	gotoxy(40, 6);
	printf("백기↓ : %c", inputKey.whiteDown);   
	textcolor(FONT_YELLOW);
	gotoxy(15, 4); printf("아무것도 안하기 : SPACEBAR");
	// 기본 화면 UI 출력
	gotoxy(22, 10);
	printf("%s ", stageStatus._blueOrWhite[0]);
	textcolor(FONT_WHITE);
	printf("%s ", stageStatus._frontQuestion[0]);
	textcolor(FONT_YELLOW);
	printf("%s ", stageStatus._blueOrWhite[1]);
	textcolor(FONT_WHITE);
	printf("%s ", stageStatus._backQuestion[0]); // 문제 출력
}

void printTheme()
{
	textcolor(FONT_CYAN);
	gotoxy(7, 1); printDot_(2); gotoxy(7, 2); printDot_(2); 
	gotoxy(3, 3); printDot_(11); 
	gotoxy(6, 4); printDot_(4); gotoxy(13, 4); printDot_(3);
	gotoxy(4, 5); printDot_(3); gotoxy(9, 5); printDot_(3);
	gotoxy(3, 6); printDot_(3); gotoxy(10, 6); printDot_(3);
	gotoxy(3, 7); printDot_(2); gotoxy(11, 7); printDot_(2);
	for (int i = 1; i < 9;i++){ gotoxy(16, i); printDot_(2); }
	gotoxy(8, 9); printDot_(8); gotoxy(8, 12); printDot_(8);
	gotoxy(7, 10); printDot_(2); gotoxy(15, 10); printDot_(2);
	gotoxy(7, 11); printDot_(2); gotoxy(15, 11); printDot_(2); // '청'

	gotoxy(21, 2); printDot_(7); gotoxy(26, 3); printDot_(2);
	gotoxy(26, 4); printDot_(2); gotoxy(26, 5); printDot_(2);
	for (int i = 1;i < 6;i++) { gotoxy(30, i); printDot_(2); } // '기'

	textcolor(FONT_WHITE);
	for (int i = 5; i < 12; i++){ gotoxy(46, i); printDot_(2); gotoxy(50, i); printDot_(2); }
	gotoxy(48, 8); printDot_(2); gotoxy(42, 12); printDot_(8);
	gotoxy(36, 6); printDot_(2); gotoxy(41, 6); printDot_(2);
	gotoxy(36, 7); printDot_(2); gotoxy(41, 7); printDot_(2);
	gotoxy(36, 8); printDot_(7); gotoxy(36, 10); printDot_(7);
	gotoxy(36, 9); printDot_(2); gotoxy(41, 9); printDot_(2);
	for (int i = 12; i < 16; i++) { gotoxy(48, i); printDot_(2); } // '백'

	gotoxy(55, 5); printDot_(7); gotoxy(60, 6); printDot_(2);
	gotoxy(60, 7); printDot_(2); gotoxy(60, 8); printDot_(2);
	for (int i = 4;i < 9;i++) { gotoxy(64, i); printDot_(2); } // '기'
	textcolor(FONT_YELLOW); gotoxy(3, 18); printf("진행 ::: ENTER"); 
	textcolor(FONT_CYAN);
	gotoxy(28, 30); printf("MADE BY 김경훈(https://github.com/hoonkk)");
	textcolor(FONT_WHITE);
}
void menuSlide()
{
	for (int i = 26; i > 20; i--)
	{
		gotoxy(25, i);     printf("1.G A M E S T A R T");
		gotoxy(25, i + 1); printf("2.K E Y S E T T I N G");
		gotoxy(25, i + 2); printf("3.R A N K I N G");
		gotoxy(25, i + 3); printf("4.E X I T");
		Sleep(50);
		gotoxy(25, i);     printf("                   ");
		gotoxy(25, i + 1); printf("                     ");
		gotoxy(25, i + 2); printf("               ");
		gotoxy(25, i + 3); printf("         ");
	}
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
					playSound(MENUMOVE);
					return NOTHING;
				}
				else return NOTHING;
			}
			if (move == 80)
			{
				if (menuNumber < 4)
				{
					menuNumber++;
					playSound(MENUMOVE);
					return NOTHING;
				}
				else return NOTHING;
			}
			else return NOTHING;
		}
		else if (move == ENTER)
		{
			move = getKey(); // 뒤에 0바이트는 버린다.
			playSound(BEEP);
			return menuNumber;
		}
		else return NOTHING;
}

void initialScreen()
{
	printTheme();
	menuSlide();
	printMenu();
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
	playSound(SWING);
	if (flagSwitch == inputKey.blueUp) // 청기 올리는 것 도트 찍기 청기 내릴때 올리는 건 blank로 다시출력.
	{
		textcolor(FONT_CYAN);
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

		textcolor(FONT_CYAN);
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
	for (int i = 0; i < 5;i ++)
	{
		gotoxy(22, 15); textcolor(FONT_RED); printf("W  A  R  N  I  N  G  !  !  !"); Sleep(WAIT+100);
		gotoxy(22, 15); textcolor(FONT_RED); printf("                            "); Sleep(WAIT+100);
	}
	gotoxy(15, 15); textcolor(FONT_WHITE); printf("초기 키셋팅을 해야 게임을 시작할 수 있습니다!");
}

bool keyUseable(int inputKey)
{
	if (33 <= inputKey && inputKey <= 126)
		return true;
	else return false;
}