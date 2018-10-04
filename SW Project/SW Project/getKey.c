#include <stdio.h>
#include <conio.h>
#include "getkey.h"

int getKey()
{
	return _getch();
}

void keySetting(int _chungUp, int _chungDown, int _baekUp, int _baekDown)
{
	printf("키세팅을 시작합니다.아직은 알파벳만 구현합니다.\n청기를 들어올리는 버튼을 설정해주세요==>");
	_chungUp = getKey();
	getKey();// 뒤의 0 바이트를 읽어서 버림
	printf("%d", _chungUp);
	printf("\n청기를 내리는 버튼을 설정해주세요==>");
	_chungDown = getKey();
	getKey(); // 뒤의 0 바이트를 읽어서 버림
	printf("%d", _chungDown);
	printf("\n백기를 올리는 버튼을 설정해주세요==>");
	_baekUp = getKey();
	getKey(); // 뒤의 0 바이트를 읽어서 버림
	printf("\n백기를 내리는 버튼을 설정해주세요==>\n");
	_baekDown = getKey();
	getKey();
}