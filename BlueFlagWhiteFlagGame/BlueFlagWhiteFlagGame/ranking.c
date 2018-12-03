#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "console.h"
#define BUFFER 2000
void showRanking()
{
	char buffer[BUFFER] = "";
	FILE *fp;
	char *eachData[BUFFER];
	for (int i = 0;i < BUFFER;i++)
	{
		eachData[i] = "";
	} // ��� ������ �ʱ�ȭ
	int rankingIndex = 0;
	struct _recordData {
		int rank;
		char name[10];
		double playTime;
	}recordData[BUFFER];

	fopen_s(&fp, "data\\gamedata.txt", "r");
	if (fp == NULL)
	{
		gotoxy(22, 15); printf("����� �����Ͱ� �����ϴ�. \n");
		pause();
	}
	else
	{
		textcolor(FONT_YELLOW);
		gotoxy(22, 1); printf("< R  A  N  K  I  N  G >");
		gotoxy(22, 4); printf("RANK");
		gotoxy(30, 4); printf("NAME");
		gotoxy(38, 4); printf("TIME(��)");
		fgets(buffer, BUFFER, fp);
		char *dataToken = strtok(buffer, "^");
		while (dataToken != NULL)
		{
			if (rankingIndex == 51) // �����Ͱ� 50���� ���� ��� ���̻� ���� ����.
			{
				break;
			}
			eachData[rankingIndex] = dataToken;
			strcpy(eachData[rankingIndex], dataToken);
			dataToken = strtok(NULL, "^");
			rankingIndex++;
		}


		for (int i = 0;i < rankingIndex; i++)
		{
			recordData[i].rank = 1;
			char *timeToken = strtok(eachData[i], " ");
			strcpy(recordData[i].name, timeToken);
			timeToken = strtok(NULL, "");
			recordData[i].playTime = atof(timeToken);// �� �����͵��� ��ū���� �����ϴ� ����		
		}
		for (int i = 0; i < rankingIndex; i++)
		{
			for (int j = 0; j < rankingIndex; j++)
			{
				if (recordData[i].playTime > recordData[j].playTime)
				{
					recordData[i].rank++;
				}
			}
		} // �� �����͵��� ������ �ű�� �˰���
		textcolor(FONT_GRAY);
		gotoxy(49, 30);printf("TOTAL DATA: %d/50", rankingIndex);


		for (int i = 0; i < rankingIndex; i++) // ��� �����͸� �˻��ϵ�
		{
			if (recordData[i].rank <= 20) // 20�������� ����ϰ� ��(�����Ͱ� 20�� �Ʒ��� ��� �ڿ������� ������ ���� ��µ�)
			{
				textcolor(FONT_GRAY); gotoxy(22, 5 + recordData[i].rank); printf("%2d��  ", recordData[i].rank);
				textcolor(FONT_WHITE); gotoxy(30, 5 + recordData[i].rank); printf("%s", recordData[i].name);
				textcolor(FONT_CYAN);gotoxy(38, 5 + recordData[i].rank); printf("%0.2f", recordData[i].playTime);
			}
		}

		fclose(fp);
		pause();
		system("cls");
	}
}


