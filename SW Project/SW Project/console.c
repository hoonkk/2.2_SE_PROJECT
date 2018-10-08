#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "console.h"
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

