#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "console.h"
#define BUFFER 1000
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
		gotoxy(5, 2); printf("NAME  TIME");
		fgets(buffer, BUFFER, fp);
		char *dataToken = strtok(buffer, "^");
		while (dataToken != NULL)
		{
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
		gotoxy(26, 30);printf("TOTAL DATA �� : %d/100", rankingIndex);


		for (int i = 0; i < rankingIndex; i++) // ��� �����͸� �˻��ϵ�
		{
			if (recordData[i].rank <= 20) // 20�������� ����ϰ� ��(�����Ͱ� 20�� �Ʒ��� ��� �ڿ������� ������ ���� ��µ�)
			{
				gotoxy(8, 3 + recordData[i].rank); printf("%d", recordData[i].rank);
				printf(" %s   %.2f", recordData[i].name, recordData[i].playTime);
			}
		}

		fclose(fp);
		pause();
		system("cls");
	}
}


