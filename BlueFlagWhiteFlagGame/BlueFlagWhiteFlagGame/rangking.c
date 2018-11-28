#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "console.h"

#define BUFFER 1000
void showRangking()
{
	char buffer[BUFFER] = "";
	FILE *fp;
	char *eachData[BUFFER];
	for (int i = 0;i < BUFFER;i++)
	{
		eachData[i] = "";
	} // 모든 데이터 초기화
	int rangkingIndex = 0;
	int inputMax = 0; // 랭킹을 출력하는 최대 수를 지정.
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
		gotoxy(5, 2); printf("NAME  TIME");
		fgets(buffer, BUFFER, fp);
		char *dataToken = strtok(buffer, "^");
		while (dataToken != NULL)
		{
			eachData[rangkingIndex] = dataToken;
			strcpy(eachData[rangkingIndex], dataToken);
			dataToken = strtok(NULL, "^");
			rangkingIndex++;
		}


		for (int i = 0;i < rangkingIndex; i++)
		{
			recordData[i].rank = 1;
			char *timeToken = strtok(eachData[i], " ");
			strcpy(recordData[i].name, timeToken);
			timeToken = strtok(NULL, "");
			recordData[i].playTime = atof(timeToken);// 각 데이터들을 토큰으로 분할하는 과정		
		}


		for (int i = 0; i < rangkingIndex; i++)
		{
			for (int j = 0; j < rangkingIndex; j++)
			{
				if (recordData[i].playTime > recordData[j].playTime)
				{
					recordData[i].rank++;
				}
			}
			/*gotoxy(3, 3 + recordData[i].rank); printf("%d", recordData[i].rank);
			printf(" %s   %.2f", recordData[i].name, recordData[i].playTime);*/
		} // 각 데이터들의 순위를 매기는 알고리즘
		gotoxy(26, 26);printf("TOTAL DATA 수 : %d", rangkingIndex);

		if (rangkingIndex <= 20) inputMax = rangkingIndex; // 20개 이하가 입력되있다면 최대 출력은 랭킹의 인덱스까지만 출력. 
		else inputMax = 20; // 20개 이상이 입력되있다면 최대 20개까지만 출력.
		for (int i = 0; i < rangkingIndex; i++)
		{
			if (recordData[i].rank <= 20)
			{
				gotoxy(3, 3 + recordData[i].rank); printf("%d", recordData[i].rank);
				printf(" %s   %.2f", recordData[i].name, recordData[i].playTime);
			}
		}

		fclose(fp);
		pause();
	}
}

\
