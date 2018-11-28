#include <stdio.h>
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
#define ENTER 13
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
	stageStatus.score = 0;
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
	printf("������  �����մϴ� . . . !");
	pause();
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
		if (upDownFront != DO_NOT_UP && upDownFront != DO_NOT_DOWN) // ���� ���� ���� ���ڰ� �ø��ų�, ������ ��쿡�� ����� INPUT�� ����
				userInputFront = keySetting(); // ������� input(����)�� �޴´�
		moveFlag(userInputFront);
		if (upDownBack != DO_NOT_UP && upDownBack != DO_NOT_DOWN) // ���� �Ĺ� ���� ���ڰ� �ø��ų�, ������ ��쿡�� ����� INPUT�� ����
				userInputBack = keySetting(); // ������� input(�Ĺ�)�� �޴´�
		moveFlag(userInputBack);
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
		gotoxy(28, 12);
		if (isThatRight == ENTER)
		{
			if (uncorrectAnswer == 0)
			{
				printf("G  O  O  D  ��\n");
				printCharactor(HAPPY);
				stageStatus.score += 50;
			}// �����ΰ��
			else
			{
				printf("M  I  S  S !\n"); // �����ΰ��
				printCharactor(SAD);
				stageStatus.life--;
			}
		}
		else
		{
			printf("M  I  S  S!\n"); //���� ���� �ٸ� ���� ���� ���.
			printCharactor(SAD);
			stageStatus.life--;
		}

		endTimer = clock();
		stageStatus.time += (endTimer - startTimer);
		if (stageStatus.life == 0)
		{
			char a[FILE_BUFFER] = "";

			system("cls"); gotoxy(20, 15); printf("GAME OVER . . . ! "); pause(); system("cls");
			gotoxy(20, 15); printf("�� STAGE : %d   �� �ɸ� �ð� : %.2f��", stageStatus.stage, stageStatus.time/1000);
			gotoxy(20, 17);printf("NAME?(3�ڱ����� �ν��Ͽ� �Է��մϴ�.)");
			gotoxy(20, 20); printf("��"); gotoxy(21, 20); printf("��"); 
			gotoxy(22, 20); printf("��"); gotoxy(20, 19); printf("��"); gotoxy(20, 18); printf("��");
			gotoxy(21, 18); printf("��"); gotoxy(22, 18); printf("��"); gotoxy(23, 18); printf("��");
			gotoxy(25, 18); printf("��"); gotoxy(25, 19); printf("��"); gotoxy(25, 20); printf("��"); gotoxy(24, 20); printf("��");
			gotoxy(22, 19); scanf_s("%3s", a, FILE_BUFFER);
			fopen_s(&fp,"data\\gamedata.txt", "a");
			fprintf(fp, "%s %.2f^" , a , stageStatus.time/1000);
			fclose(fp);
			pause(); system("cls");
			break;
		}
		gotoxy(20, 2);
		printf("�̹� ������������ �ɸ� �ð� :: %.2f��", (endTimer - startTimer)/1000);
		gotoxy(20, 3);
		printf("������� ��� �ð� :: %.2f��", stageStatus.time / 1000);
		stageStatus.stage++; // �������� ����
		pause();
		system("cls");
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


