#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <time.h> // rand�Լ� ���, clock()�� ���� ���
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

#define QUESTION_BUFFER 50
#define LIFE 10
#define FILE_BUFFER 100

void gameStart()
{
	FILE *fp; //���� ����
	
	srand((unsigned int)time(NULL)); // ������ cast
	int upDownFront, upDownBack; // ������ ������ �� �ø��� ������, ������ ������ ���� �ο��ϴ� �����Լ�
	int blueWhiteFront, blueWhiteBack; // û��, ����� ���� ��, �޼����� ����.
	int userInputFront = 0, userInputBack = 0; // ����ڰ� �Է��� �� ��
	int uncorrectAnswer; //����ó��
	stageStatus.time = 0;
	stageStatus.stage = 1;
	stageStatus.life = 1; //�ӽ÷� �ٲ� �׽���������
	double startTimer, endTimer;
	char *frontQuestion[] = { "�ø���", "������", "�ø�������",  "����������" }; // ���� ����
	char *backQuestion[] = { "�÷�", "����" , "�ø�����", "��������" }; // ���� ����. ������ ��¦ �ٸ��Ƿ� ���� ����.
	char *blueOrWhite[] = { "û��" , "���" }; // û�� ����� �յ� ������ ����.
	stageStatus._frontQuestion[0] = "";
	stageStatus._backQuestion[0] = "";
	stageStatus._blueOrWhite[0] = "";
	stageStatus._blueOrWhite[1] = "";
	gotoxy(22, 15);
	gameIntro();
	while (1)
	{
		uncorrectAnswer= 0, userInputFront = 0, userInputBack = 0;
		upDownFront = rand() % 4; // ���� ����Ǽ��� 4���̹Ƿ� rand�� 4���� �޴´�.
		blueWhiteFront = rand() % 2; // û��, ������� �����ϴ� 2���� rand
		
		system("cls");
		initialShow();
		gotoxy(26, 12);
		printf("R  E  A  D  Y  ?");
		pause();
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
		updateShow(); // ���� ���
		/* ���⼭ ���� �ð��� ��ϴ� */
		startTimer = clock();

		userInputFront = keySetting(); // ������� input(����)�� �޴´�
		moveFlag(userInputFront);
		userInputBack = keySetting(); // ������� input(�Ĺ�)�� �޴´�
		moveFlag(userInputBack);
		if (answerCheck(blueWhiteFront, upDownFront, userInputFront) == FALSE) 
		{
			uncorrectAnswer++;
		}
		if (answerCheck(blueWhiteBack, upDownBack, userInputBack) == FALSE)
		{
			uncorrectAnswer++;
		}
		
		gotoxy(28, 12);
		printf("PRESS ENTER!");
		pause();
		if (uncorrectAnswer == 0)
		{
			gotoxy(28, 12); printf("G  O  O  D  ��  ");
			printCharactor(HAPPY);
		}// �����ΰ��
		else
		{
			gotoxy(28, 12); printf("M  I  S  S !   "); // �����ΰ��
			printCharactor(SAD);
			stageStatus.life--;
		}
		if (stageStatus.life == 0) // ���ӿ���
		{
			pause();
			system("cls");
			textcolor(FONT_RED);
			for (int i = 0; i < 5; i++) // �����̴� ȿ��
			{
				gotoxy(24, 15); printf("                       "); Sleep(150);
				gotoxy(24, 15); printf("G  A  M  E  O  V  E  R "); Sleep(150);
			}
			textcolor(FONT_WHITE);
			pause();
			system("cls");
			break;
		}
		endTimer = clock();
		stageStatus.time += (endTimer - startTimer);
		gotoxy(40, 30);
		printf("������� ��� �ð� :: %.2f��", stageStatus.time / 1000);
		stageStatus.stage++; // �������� ����
		if (stageStatus.stage == 2) // Ŭ����
		{
			char a[FILE_BUFFER] = "";
			pause();
			system("cls"); 
			printCharactor(HAPPY);
			for (int i = 0; i < 5; i++) // �����̴� ȿ��
			{
				gotoxy(25, 10); printf("                   "); Sleep(100);
				gotoxy(25, 10); printf("C  L  E  A  R  !  !"); Sleep(100);
				gotoxy(25, 12); for (int a = 0; a <= i; a++) printf("��  ");
				gotoxy(25, 8); for (int a = 0; a <= i; a++) printf("��  ");
				Sleep(100);
			}
			
			pause(); system("cls");
			textcolor(FONT_YELLOW);
			gotoxy(17, 10); printf("�� STAGE : %d   �� �ɸ� �ð� : %.2f��", stageStatus.stage, stageStatus.time / 1000);
			textcolor(FONT_CYAN);
			gotoxy(10, 17); printf("��ŷ�� ����� �̸��� �Է��ϼ���");
			gotoxy(10, 18); printf("3�ڱ����� �ν��Ͽ� �ԷµǸ�, ���ĺ� OR ���ڷ� �Է��ϼ���");
			gotoxy(10, 19); printf("=>  "); 
			textcolor(FONT_WHITE); scanf_s("%3s", a, FILE_BUFFER);
			textcolor(FONT_WHITE);
			fopen_s(&fp, "data\\gamedata.txt", "a");
			fprintf(fp, "%s %.2f^", a, stageStatus.time / 1000);
			fclose(fp);
			pause(); system("cls");
			break;
		}
		pause();
		system("cls");
	}
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
	else if ((upDownCheck == DO_NOT_UP || upDownCheck == DO_NOT_DOWN) && userInputCheck == SPACEBAR)
		return true;
	else return false;
}


