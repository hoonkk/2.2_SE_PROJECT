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
	} // ��� ������ �ʱ�ȭ
	int rangkingIndex = 0;
	int inputMax = 0; // ��ŷ�� ����ϴ� �ִ� ���� ����.
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
			recordData[i].playTime = atof(timeToken);// �� �����͵��� ��ū���� �����ϴ� ����		
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
		} // �� �����͵��� ������ �ű�� �˰���
		gotoxy(26, 26);printf("TOTAL DATA �� : %d", rangkingIndex);

		if (rangkingIndex <= 20) inputMax = rangkingIndex; // 20�� ���ϰ� �Էµ��ִٸ� �ִ� ����� ��ŷ�� �ε��������� ���. 
		else inputMax = 20; // 20�� �̻��� �Էµ��ִٸ� �ִ� 20�������� ���.
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
