#include <stdio.h>
#include <stdlib.h> 
#include <time.h> // rand�Լ� ����� ���� ���
#include <stdbool.h> // boolean�� �Լ� ������ ���� ���
#include <Windows.h>
#include "gamestart.h"
#include "console.h"
#define DO_UP 0
#define DO_DOWN 1
#define DO_NOT_UP 2
#define DO_NOT_DOWN 3
#define BLUEFLAG 0
#define WHITEFLAG 1
#define TRUE 1
#define FALSE 0
#define ENTER 13
void gameStart()
{	
	srand((unsigned int)time(NULL)); // ������ cast
	int upDownFront, upDownBack; // ������ ������ �� �ø��� ������, ������ ������ ���� �ο��ϴ� �����Լ�
	int blueWhiteFront, blueWhiteBack; // û��, ����� ���� ��, �޼����� ����.
	int userInputFront, userInputBack; // ����ڰ� �Է��� �� ��
	int score = 0;
	int uncorrectAnswer;
	int gameaccount = 0;
	char *frontQuestion[] = { "�ø���", "������", "�ø�������",  "����������" }; // ���� ����
	char *backQuestion[] = { "�÷�", "����" , "�ø�����", "��������" }; // ���� ����. ������ ��¦ �ٸ��Ƿ� ���� ����.
	char *blueOrWhite[] = { "û��" , "���" }; // û�� ����� �յ� ������ ����.
	guide();
	while (1)
	{
		uncorrectAnswer = 0;
		upDownFront = rand() % 4; // ���� ����Ǽ��� 4���̹Ƿ� rand�� 4���� �޴´�.
		blueWhiteFront = rand() % 2; // û��, ������� �����ϴ� 2���� rand
		printf("������  �����մϴ� . . . !");
		Sleep(2000);
		system("cls");
		printf("���� ����!\n");
		
		printf("%s %s", blueOrWhite[blueWhiteFront], frontQuestion[upDownFront]); // ������ �� �� ���
		if (blueWhiteFront == BLUEFLAG)
			blueWhiteBack = WHITEFLAG;
		else if (blueWhiteFront == WHITEFLAG)
			blueWhiteBack = BLUEFLAG;    // û�� ���Ŀ� �� û��, ��� ���Ŀ� �� ��Ⱑ ������ ��� ����.
		
		if (upDownFront == DO_NOT_UP || upDownFront == DO_NOT_DOWN)
		{
			upDownBack = rand() % 2;
			printf(" %s %s\n", blueOrWhite[blueWhiteBack], backQuestion[upDownBack]);
		}
		else // �� ���� �ø�������, ���������� �� ��� �� ���� �ø�����, ���������� ��츦 ������
		{
			upDownBack = rand() % 4;
			printf(" %s %s\n", blueOrWhite[blueWhiteBack], backQuestion[upDownBack]); // ������ �� �� ���
		}
		if (upDownFront != DO_NOT_UP && upDownFront != DO_NOT_DOWN) // ���� ���� ���� ���ڰ� �ø��ų�, ������ ��쿡�� ����� INPUT�� ����
			userInputFront = keySetting(); // ������� input(����)�� �޴´�
		if (upDownBack != DO_NOT_UP && upDownBack != DO_NOT_DOWN) // ���� �Ĺ� ���� ���ڰ� �ø��ų�, ������ ��쿡�� ����� INPUT�� ����
			userInputBack = keySetting(); // ������� input(�Ĺ�)�� �޴´�

		if (upDownFront != DO_NOT_UP && upDownFront != DO_NOT_DOWN) // �� ���� ������ �ִ� ���(�ø��ų�, ������ ���)���� ä��
		{
			if (answerCheck(blueWhiteFront, upDownFront, userInputFront) == FALSE)
				uncorrectAnswer++;
		}
		if (upDownBack != DO_NOT_UP && upDownBack != DO_NOT_DOWN) // �� ���� ������ �ִ� ���(�ø��ų�, ������ ���)���� ä��
		{
			if (answerCheck(blueWhiteBack, upDownBack, userInputBack) == FALSE)
				uncorrectAnswer++;
		}
		int isThatRight = keySetting();
		if (isThatRight == ENTER)
		{
			if (uncorrectAnswer == 0)
			{
				printf("����!\n");
				score = score + 50;
			}// �����ΰ��
			else
			{
				printf("����!\n"); // �����ΰ��
			}
		}
		else printf("����!\n");
		printf("���� ���� : %d \n", score);
		gameaccount++;
		Sleep(1000);
		system("cls");
		if (gameaccount == 10)
			printf("exit");
	} 
	getchar();
}
bool answerCheck(int blueWhiteCheck, int upDownCheck, int userInputCheck) // ���� ä��
{
	if (blueWhiteCheck == BLUEFLAG && upDownCheck == DO_UP && userInputCheck == inputKey.blueUp)
		return true;
	else if (blueWhiteCheck == BLUEFLAG && upDownCheck == DO_DOWN && userInputCheck == inputKey.blueDown)
		return true;
	else if (blueWhiteCheck == WHITEFLAG && upDownCheck == DO_UP && userInputCheck == inputKey.whiteUp)
		return true;
	else if (blueWhiteCheck == WHITEFLAG && upDownCheck == DO_DOWN && userInputCheck == inputKey.whiteDown)
		return true;
	else return false;
}

void guide()
{
	int guide;
	printf("���̵带 ���ðڽ��ϱ�? \n1.����\n2.�� ����\n");
	scanf_s("%d", &guide);
	if (guide == 1)
	{
		system("cls");
		printf("û�� ��� ����\n\n\n\n���� Ű �������� ���Ͻ� Ű�� �÷��� �Ͻø� �˴ϴ�.������ �����Ǹ�, ������������ ������ �ð��ȿ�");
		printf("�Է��ؾ� �ϸ�, EX)û�� �ø������� ��� ���� �� ��� ��� ������ ���� ��ɾ �Է��Ͻø� �˴ϴ�. ��ɾ� �Է� �Ŀ��� ���͸�");
		printf("������ ä���� ���� ��ɾ �ϳ��� �Է��ؾ��ϴ� ��쿡 �� �� �̻��� �Է��ϰų�, ��ɾ� �Է� ��");
		printf("���� ���� �ٸ� Ű�� �����ø� ����ó�� �˴ϴ�. �ð� ���� �Է��ϼž� ������ ��ɾ� ���� ���͸� �� �����ּž� �����Դϴ�.\n");
		getchar();
	}
	
}