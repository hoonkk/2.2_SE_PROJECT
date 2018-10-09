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
	printf("�Է��Ͻ� Ű�� "); putchar(inputKey.blueUp); printf(" �Դϴ�\n");
	while(1)// ��ư�� �ߺ����� �ʰ� �˻��Ͽ�, �ߺ��� �ٽ� �Է¹ް� �ϴ� ����
	{
		printf("û�⸦ ������ ��ư�� �Է����ּ���::\n");
		inputKey.blueDown = keySetting();
		printf("�Է��Ͻ� Ű�� "); putchar(inputKey.blueDown); printf(" �Դϴ�\n");
		if (inputKey.blueDown == inputKey.blueUp)
			printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���\n");
		else break;
	}
	while (1)
	{
		printf("��⸦ �ø��� ��ư�� �Է����ּ���::\n");
		inputKey.whiteUp = keySetting();
		printf("�Է��Ͻ� Ű�� "); putchar(inputKey.whiteUp); printf(" �Դϴ�\n");
		if (inputKey.whiteUp == inputKey.blueUp || inputKey.whiteUp == inputKey.blueDown)
			printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���\n");
		else break;
	}
	while (1)
	{
		printf("��⸦ ������ ��ư�� �Է����ּ���::\n");
		inputKey.whiteDown = keySetting();
		printf("�Է��Ͻ� Ű�� "); putchar(inputKey.whiteDown); printf(" �Դϴ�\n");
		if (inputKey.whiteDown == inputKey.blueUp || inputKey.whiteDown == inputKey.blueDown || inputKey.whiteDown == inputKey.whiteUp)
			printf("�ߺ��� Ű�� �����ϼ̽��ϴ�. �ٽ� �Է����ּ���\n");
		else break;
	}
}
