#include <stdio.h>
#include <conio.h>
#include "getKey.h"
#include "keySetting.h"
//a -> �� ȭ��ǥ , b -> �Ʒ� ȭ��ǥ, c -> ���� ȭ��ǥ, d- > ������ ȭ��ǥ
void main()
{
	int chungUp = getKey();
	printf("%c", chungUp);
	int chungDown = getKey();
	printf("%c", chungDown);
	int baekUp = getKey();
	printf("%c", baekUp);
	int baekDown = getKey();
	printf("%c", baekDown);

	
	
}
