#include <stdio.h>
#include <conio.h>
#include "getKey.h"
#include "keySetting.h"
//a -> 위 화살표 , b -> 아래 화살표, c -> 왼쪽 화살표, d- > 오른쪽 화살표
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
