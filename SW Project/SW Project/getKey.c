#include <stdio.h>
#include <conio.h>
#include "getkey.h"

int getKey()
{
	return _getch();
}

void keySetting(int _chungUp, int _chungDown, int _baekUp, int _baekDown)
{
	printf("Ű������ �����մϴ�.������ ���ĺ��� �����մϴ�.\nû�⸦ ���ø��� ��ư�� �������ּ���==>");
	_chungUp = getKey();
	getKey();// ���� 0 ����Ʈ�� �о ����
	printf("%d", _chungUp);
	printf("\nû�⸦ ������ ��ư�� �������ּ���==>");
	_chungDown = getKey();
	getKey(); // ���� 0 ����Ʈ�� �о ����
	printf("%d", _chungDown);
	printf("\n��⸦ �ø��� ��ư�� �������ּ���==>");
	_baekUp = getKey();
	getKey(); // ���� 0 ����Ʈ�� �о ����
	printf("\n��⸦ ������ ��ư�� �������ּ���==>\n");
	_baekDown = getKey();
	getKey();
}