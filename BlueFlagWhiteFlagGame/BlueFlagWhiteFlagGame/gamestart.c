#include <stdio.h>
#include <stdlib.h> 
#include <time.h> // rand함수 사용을 위한 헤더
#include <stdbool.h> // boolean형 함수 선언을 위한 헤더
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
	srand((unsigned int)time(NULL)); // 강제로 cast
	int upDownFront, upDownBack; // 문제를 출제할 때 올리는 것인지, 내리는 것인지 등을 부여하는 랜드함수
	int blueWhiteFront, blueWhiteBack; // 청기, 백기의 문제 앞, 뒷순위를 결정.
	int userInputFront, userInputBack; // 사용자가 입력한 값 비교
	int uncorrectAnswer;
	stageStatus.score = 0;
	stageStatus.stage = 1;
	stageStatus.life = 10;;
	char *frontQuestion[] = { "올리고", "내리고", "올리지말고",  "내리지말고" }; // 앞의 문제
	char *backQuestion[] = { "올려", "내려" , "올리지마", "내리지마" }; // 뒤의 문제. 어투가 살짝 다르므로 따로 설정.
	char *blueOrWhite[] = { "청기" , "백기" }; // 청기 백기의 앞뒤 순서를 결정.
	stageStatus._frontQuestion[0] = "";
	stageStatus._backQuestion[0] = "";
	stageStatus._blueOrWhite[0] = "";
	stageStatus._blueOrWhite[1] = "";

	while (1)
	{
		uncorrectAnswer = 0;
		upDownFront = rand() % 4; // 문제 경우의수가 4개이므로 rand로 4개를 받는다.
		blueWhiteFront = rand() % 2; // 청기, 백기임을 결정하는 2개의 rand
		printf("게임을  시작합니다 . . . !");
		system("pause>nul");
		system("cls");
		initialShow();
		if (blueWhiteFront == BLUEFLAG)
			blueWhiteBack = WHITEFLAG;
		else if (blueWhiteFront == WHITEFLAG)
			blueWhiteBack = BLUEFLAG;    // 청기 이후에 또 청기, 백기 이후에 또 백기가 나오는 경우 차단.

		if (upDownFront == DO_NOT_UP || upDownFront == DO_NOT_DOWN)
		{
			upDownBack = rand() % 2;
		}
		else // 앞 문이 올리지말고, 내리지말고 인 경우 뒷 문은 올리지마, 내리지마인 경우를 제한함
		{
			upDownBack = rand() % 4;
		}
		stageStatus._blueOrWhite[0] = blueOrWhite[blueWhiteFront];
		stageStatus._frontQuestion[0] = frontQuestion[upDownFront];
		stageStatus._blueOrWhite[1] = blueOrWhite[blueWhiteBack];
		stageStatus._backQuestion[0] = backQuestion[upDownBack];
		updateShow();

		if (upDownFront != DO_NOT_UP && upDownFront != DO_NOT_DOWN) // 문제 전문 앞의 문자가 올리거나, 내리는 경우에만 사용자 INPUT을 받음
			userInputFront = keySetting(); // 사용자의 input(전문)을 받는다
		if (upDownBack != DO_NOT_UP && upDownBack != DO_NOT_DOWN) // 문제 후문 앞의 문자가 올리거나, 내리는 경우에만 사용자 INPUT을 받음
			userInputBack = keySetting(); // 사용자의 input(후문)을 받는다

		if (upDownFront != DO_NOT_UP && upDownFront != DO_NOT_DOWN) // 앞 절의 문제가 있는 경우(올리거나, 내리는 경우)에만 채점
		{
			if (answerCheck(blueWhiteFront, upDownFront, userInputFront) == FALSE)
				uncorrectAnswer++;
		}
		if (upDownBack != DO_NOT_UP && upDownBack != DO_NOT_DOWN) // 뒤 절의 문제가 있는 경우(올리거나, 내리는 경우)에만 채점
		{
			if (answerCheck(blueWhiteBack, upDownBack, userInputBack) == FALSE)
				uncorrectAnswer++;
		}
		int isThatRight = keySetting(); // 그 답이 맞다면 엔터를 누르게끔 한다.
		if (isThatRight == ENTER)
		{
			if (uncorrectAnswer == 0)
			{
				printf("정답!\n");
				stageStatus.score += 50;
			}// 정답인경우
			else
			{
				printf("오답!\n"); // 오답인경우
			}
		}
		else printf("오답!\n");
		stageStatus.stage++; // 스테이지 증가
		Sleep(1000);
		system("cls");
		if (stageStatus.stage == 10)
			printf("exit");
	}
	getchar();
}
bool answerCheck(int blueWhiteCheck, int upDownCheck, int userInputCheck) // 문제 채점
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
	printf("청기↑ : %c", inputKey.blueUp);
	gotoxy(15, 8);
	printf("청기↓ : %c", inputKey.blueDown);
	textcolor(FONT_WHITE);
	gotoxy(40, 7);
	printf("백기↑ : %c", inputKey.whiteUp);
	gotoxy(40, 8);
	printf("백기↓ : %c", inputKey.whiteDown);

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