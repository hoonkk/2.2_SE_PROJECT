#include <stdio.h>
#include <stdlib.h> 
#include <time.h> // rand�Լ� ����� ���� ���
#include <stdbool.h> // boolean�� �Լ� ������ ���� ���
#include <Windows.h>
#include <string.h>
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
#define QUESTION_BUFFER 50
#define LIFE 10
#define FONT_BLUE 1
#define FONT_RED 4
#define FONT_YELLOW 6
#define FONT_WHITE 7
void gameStart()
{
	srand((unsigned int)time(NULL)); // ������ cast
	int upDownFront, upDownBack; // ������ ������ �� �ø��� ������, ������ ������ ���� �ο��ϴ� �����Լ�
	int blueWhiteFront, blueWhiteBack; // û��, ����� ���� ��, �޼����� ����.
	int userInputFront, userInputBack; // ����ڰ� �Է��� �� ��
	int uncorrectAnswer;
	stageStatus.score = 0;
	stageStatus.stage = 1;
	stageStatus.life = 10;;
	char *frontQuestion[] = { "�ø���", "������", "�ø�������",  "����������" }; // ���� ����
	char *backQuestion[] = { "�÷�", "����" , "�ø�����", "��������" }; // ���� ����. ������ ��¦ �ٸ��Ƿ� ���� ����.
	char *blueOrWhite[] = { "û��" , "���" }; // û�� ����� �յ� ������ ����.
	stageStatus._frontQuestion[0] = "";
	stageStatus._backQuestion[0] = "";
	stageStatus._blueOrWhite[0] = "";
	stageStatus._blueOrWhite[1] = "";

	while (1)
	{
		uncorrectAnswer = 0;
		upDownFront = rand() % 4; // ���� ����Ǽ��� 4���̹Ƿ� rand�� 4���� �޴´�.
		blueWhiteFront = rand() % 2; // û��, ������� �����ϴ� 2���� rand
		printf("������  �����մϴ� . . . !");
		system("pause>nul");
		system("cls");
		initialShow();
		if (blueWhiteFront == BLUEFLAG)
			blueWhiteBack = WHITEFLAG;
		else if (blueWhiteFront == WHITEFLAG)
			blueWhiteBack = BLUEFLAG;    // û�� ���Ŀ� �� û��, ��� ���Ŀ� �� ��Ⱑ ������ ��� ����.

		if (upDownFront == DO_NOT_UP || upDownFront == DO_NOT_DOWN)
		{
			upDownBack = rand() % 2;
		}
		else // �� ���� �ø�������, ���������� �� ��� �� ���� �ø�����, ���������� ��츦 ������
		{
			upDownBack = rand() % 4;
		}
		stageStatus._blueOrWhite[0] = blueOrWhite[blueWhiteFront];
		stageStatus._frontQuestion[0] = frontQuestion[upDownFront];
		stageStatus._blueOrWhite[1] = blueOrWhite[blueWhiteBack];
		stageStatus._backQuestion[0] = backQuestion[upDownBack];
		updateShow();

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
		int isThatRight = keySetting(); // �� ���� �´ٸ� ���͸� �����Բ� �Ѵ�.
		if (isThatRight == ENTER)
		{
			if (uncorrectAnswer == 0)
			{
				printf("����!\n");
				stageStatus.score += 50;
			}// �����ΰ��
			else
			{
				printf("����!\n"); // �����ΰ��
			}
		}
		else printf("����!\n");
		stageStatus.stage++; // �������� ����
		Sleep(1000);
		system("cls");
		if (stageStatus.stage == 10)
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

void initialShow()
{
	gotoxy(5, 1);
	printf("STAGE : %d", stageStatus.stage);
	gotoxy(55, 1);
	printf("SCORE : %d", stageStatus.score);
}
void updateShow()
{
	textcolor(FONT_YELLOW);
	gotoxy(5, 1);
	printf("STAGE : %d", stageStatus.stage);
	gotoxy(30, 1);
	textcolor(FONT_RED);
	printf("LIFE : %d", stageStatus.life);
	gotoxy(55, 1);
	textcolor(FONT_YELLOW);
	printf("SCORE : %d", stageStatus.score);
	textcolor(FONT_BLUE);
	gotoxy(15, 7);
	printf("û��� : %c", inputKey.blueUp);
	gotoxy(15, 8);
	printf("û��� : %c", inputKey.blueDown);
	textcolor(FONT_WHITE);
	gotoxy(40, 7);
	printf("���� : %c", inputKey.whiteUp);
	gotoxy(40, 8);
	printf("���� : %c", inputKey.whiteDown);

	gotoxy(20, 15);
	textcolor(FONT_YELLOW);
	printf("%s ", stageStatus._blueOrWhite[0]);
	textcolor(FONT_WHITE);
	printf("%s ", stageStatus._frontQuestion[0]);
	textcolor(FONT_YELLOW);
	printf("%s ", stageStatus._blueOrWhite[1]);
	textcolor(FONT_WHITE);
	printf("%s ", stageStatus._backQuestion[0]);



}