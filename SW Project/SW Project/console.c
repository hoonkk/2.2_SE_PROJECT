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

void userKeySetting()
{
	printf("키셋팅을 시작합니다.\n청기를 올리는 버튼을 입력해주세요::\n");
	inputKey.blueUp = keySetting();
	printf("입력하신 키는 "); putchar(inputKey.blueUp); printf(" 입니다\n");
	while(1)// 버튼이 중복되지 않게 검사하여, 중복시 다시 입력받게 하는 로직
	{
		printf("청기를 내리는 버튼을 입력해주세요::\n");
		inputKey.blueDown = keySetting();
		printf("입력하신 키는 "); putchar(inputKey.blueDown); printf(" 입니다\n");
		if (inputKey.blueDown == inputKey.blueUp)
			printf("중복된 키를 선택하셨습니다. 다시 입력해주세요\n");
		else break;
	}
	while (1)
	{
		printf("백기를 올리는 버튼을 입력해주세요::\n");
		inputKey.whiteUp = keySetting();
		printf("입력하신 키는 "); putchar(inputKey.whiteUp); printf(" 입니다\n");
		if (inputKey.whiteUp == inputKey.blueUp || inputKey.whiteUp == inputKey.blueDown)
			printf("중복된 키를 선택하셨습니다. 다시 입력해주세요\n");
		else break;
	}
	while (1)
	{
		printf("백기를 내리는 버튼을 입력해주세요::\n");
		inputKey.whiteDown = keySetting();
		printf("입력하신 키는 "); putchar(inputKey.whiteDown); printf(" 입니다\n");
		if (inputKey.whiteDown == inputKey.blueUp || inputKey.whiteDown == inputKey.blueDown || inputKey.whiteDown == inputKey.whiteUp)
			printf("중복된 키를 선택하셨습니다. 다시 입력해주세요\n");
		else break;
	}
}
