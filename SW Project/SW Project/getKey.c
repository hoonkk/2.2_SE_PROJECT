#include <stdio.h>
#include <conio.h>
#include "getkey.h"

int getKey()
{
	return _getch();
}

int keySetting()
{
	int key;
	key = getKey();
	getKey();
	return key;
}