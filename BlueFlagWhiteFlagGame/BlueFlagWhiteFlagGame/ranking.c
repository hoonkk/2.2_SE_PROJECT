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
	} // 모든 데이터 초기화
	int rankingIndex = 0;
	struct _recordData {
		int rank;
		char name[10];
		double playTime;
	}recordData[BUFFER];

	fopen_s(&fp, "data\\gamedata.txt", "r");
	if (fp == NULL)
	{
		gotoxy(22, 15); printf("출력할 데이터가 없습니다. \n");
		pause();
	}
	else
	{
		textcolor(FONT_YELLOW);
		gotoxy(22, 1); printf("< R  A  N  K  I  N  G >");
		gotoxy(22, 4); printf("RANK");
		gotoxy(30, 4); printf("NAME");
		gotoxy(38, 4); printf("TIME(초)");
		fgets(buffer, BUFFER, fp);
		char *dataToken = strtok(buffer, "^");
		while (dataToken != NULL)
		{
			if (rankingIndex == 51) // 데이터가 50개를 넘은 경우 더이상 받지 않음.
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
			recordData[i].playTime = atof(timeToken);// 각 데이터들을 토큰으로 분할하는 과정		
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
		} // 각 데이터들의 순위를 매기는 알고리즘
		textcolor(FONT_GRAY);
		gotoxy(49, 30);printf("TOTAL DATA: %d/50", rankingIndex);


		for (int i = 0; i < rankingIndex; i++) // 모든 데이터를 검사하되
		{
			if (recordData[i].rank <= 20) // 20위까지만 출력하게 함(데이터가 20개 아래인 경우 자연스럽게 개수에 맞춰 출력됨)
			{
				textcolor(FONT_GRAY); gotoxy(22, 5 + recordData[i].rank); printf("%2d위  ", recordData[i].rank);
				textcolor(FONT_WHITE); gotoxy(30, 5 + recordData[i].rank); printf("%s", recordData[i].name);
				textcolor(FONT_CYAN);gotoxy(38, 5 + recordData[i].rank); printf("%0.2f", recordData[i].playTime);
			}
		}

		fclose(fp);
		pause();
		system("cls");
	}
}


