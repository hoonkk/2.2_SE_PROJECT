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

int keySetting() //  �ι�° ����Ʈ�� ������ �����Է�
{
	int key;
	key = getKey();
	getKey();
	return key;
}

void userKeySetting()
{
	printf("Ű������ �����մϴ�.\nû�⸦ �ø��� ��ư�� �Է����ּ���::\n");
	inputKey.blueUp = keySetting();
	printf("�Է��Ͻ� Ű�� "); putchar(inputKey.blueUp); printf(" �Դϴ�");
	printf("û�⸦ ������ ��ư�� �Է����ּ���::\n");
	inputKey.blueDown = keySetting();
	printf("��⸦ �ø��� ��ư�� �Է����ּ���::\n");
	inputKey.whiteUp = keySetting();
	printf("��⸦ ������ ��ư�� �Է����ּ���::\n");
	inputKey.whiteDown = keySetting();
}
