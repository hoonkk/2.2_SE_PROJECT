#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include "console.h"
#include "gamestart.h"
#include "ranking.h"


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
				settingWarning();
				pause();
				system("cls");
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
			showRanking();
			break;
		}
		case 4:
		{
			printf("������ �����մϴ�");
			exit(1);
		}
		case 5: // �ƽ�Ű�ڵ� üũ��
		{
			
			while (1) {
				system("cls");
				gotoxy(30, 15);
				char a = keySetting();
				printf("%d  %c", a, a);

				pause();
			}
		}
	
	
		}

	}


}