#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include "console.h"
#include "gamestart.h"
#include "rangking.h"


void main()
{
	system("title BlueFlagWhiteFlagGame"); // �ܼ� �̸� ����
	system("mode con cols=70 lines=31"); // �ܼ� â ũ�� ����
	cursorType(NOCURSOR); // Ŀ�� �ȱ����̰� ����

	int firstSet = 0; // �ʱ� Ű ������ ���ϰ� �������� �Ѿ�� ���� �������� ���� ����
	int menu = 0;
	while (1) // �⺻ �޴� ���
	{

		printMenu();
		scanf_s("%d", &menu);
		switch (menu)
		{
			////���� ����////
		case 1:
		{
			system("cls");
			if (firstSet == 0) // Ű ������ ���� �ʰ� ���ӿ� ���� ���
			{
				printf("Ű ������ ���� �����̳׿�\n");
				break;
			}
			gotoxy(12, 15);
			printf("Ű���� �Ϸ�. �������� �Ѿ���� ���͸� ��������.\n");
			pause();
			system("cls");
			gameStart();
			break;

		}
		////Ű ����////
		case 2:
		{
			system("cls");
			userKeySetting();
			firstSet++;
			break;
		}
		////��ũ////
		case 3:
		{
			system("cls");
			showRangking();
			break;
		}
		case 4:
		{
			printf("������ �����մϴ�");
			exit(1);
		}
		}

	}


}