#include <stdio.h>
#include "console.h"
#define BUFFER 2000
void showRangking()
{
	char buffer[BUFFER] = "";
	FILE *fp;
	fopen_s(&fp,"data\\gamedata.txt", "r");
	if (fp == NULL)
	{
		gotoxy(22, 15); printf("����� �����Ͱ� �����ϴ�. \n");
		pause();
	}
	else
	{
		fgets(buffer, BUFFER, fp);
		gotoxy(5, 2); printf("NAME  TIME");
		gotoxy(5, 3); printf("%s", buffer);
		fclose(fp);
	}
	printf("\n\n\n\n");

}