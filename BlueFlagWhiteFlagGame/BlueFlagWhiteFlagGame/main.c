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
	initialScreen();
	while (1) // �⺻ �޴� ���
	{
		printTheme();
		printMenu();
		menu = choiceMenu(); 
		printMenu();
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
		////��������////
		case 4:
		{
			system("cls");
			gotoxy(20, 15);
			printf("������ �����մϴ�");
			exit(1);
		}
		case 5:
		{
			
		}
		
		}

	}


}