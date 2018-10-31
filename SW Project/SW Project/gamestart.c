#include <stdio.h>
#include <stdlib.h> 
#include <time.h> // rand함수 사용을 위한 헤더
#include <stdbool.h> // boolean형 함수 선언을 위한 헤더
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
	srand((unsigned int)time(NULL)); // 강제로 cast
	int upDownFront, upDownBack; // 문제를 출제할 때 올리는 것인지, 내리는 것인지 등을 부여하는 랜드함수
	int blueWhiteFront, blueWhiteBack; // 청기, 백기의 문제 앞, 뒷순위를 결정.
	int userInputFront, userInputBack; // 사용자가 입력한 값 비교
	int score = 0;
	int uncorrectAnswer;
	int gameaccount = 0;
	char *frontQuestion[] = { "올리고", "내리고", "올리지말고",  "내리지말고" }; // 앞의 문제
	char *backQuestion[] = { "올려", "내려" , "올리지마", "내리지마" }; // 뒤의 문제. 어투가 살짝 다르므로 따로 설정.
	char *blueOrWhite[] = { "청기" , "백기" }; // 청기 백기의 앞뒤 순서를 결정.
	guide();
	while (1)
	{
		uncorrectAnswer = 0;
		upDownFront = rand() % 4; // 문제 경우의수가 4개이므로 rand로 4개를 받는다.
		blueWhiteFront = rand() % 2; // 청기, 백기임을 결정하는 2개의 rand
		printf("게임을  시작합니다 . . . !");
		Sleep(2000);
		system("cls");
		printf("게임 시작!\n");
		
		printf("%s %s", blueOrWhite[blueWhiteFront], frontQuestion[upDownFront]); // 문제의 앞 문 출력
		if (blueWhiteFront == BLUEFLAG)
			blueWhiteBack = WHITEFLAG;
		else if (blueWhiteFront == WHITEFLAG)
			blueWhiteBack = BLUEFLAG;    // 청기 이후에 또 청기, 백기 이후에 또 백기가 나오는 경우 차단.
		
		if (upDownFront == DO_NOT_UP || upDownFront == DO_NOT_DOWN)
		{
			upDownBack = rand() % 2;
			printf(" %s %s\n", blueOrWhite[blueWhiteBack], backQuestion[upDownBack]);
		}
		else // 앞 문이 올리지말고, 내리지말고 인 경우 뒷 문은 올리지마, 내리지마인 경우를 제한함
		{
			upDownBack = rand() % 4;
			printf(" %s %s\n", blueOrWhite[blueWhiteBack], backQuestion[upDownBack]); // 문제의 뒷 문 출력
		}
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
		int isThatRight = keySetting();
		if (isThatRight == ENTER)
		{
			if (uncorrectAnswer == 0)
			{
				printf("정답!\n");
				score = score + 50;
			}// 정답인경우
			else
			{
				printf("오답!\n"); // 오답인경우
			}
		}
		else printf("오답!\n");
		printf("나의 점수 : %d \n", score);
		gameaccount++;
		Sleep(1000);
		system("cls");
		if (gameaccount == 10)
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

void guide()
{
	int guide;
	printf("가이드를 보시겠습니까? \n1.보기\n2.안 보기\n");
	scanf_s("%d", &guide);
	if (guide == 1)
	{
		system("cls");
		printf("청기 백기 게임\n\n\n\n앞의 키 설정에서 정하신 키로 플레이 하시면 됩니다.문제가 출제되면, 스테이지마다 지정된 시간안에");
		printf("입력해야 하며, EX)청기 올리지말고 백기 내려 의 경우 백기 내려에 대한 명령어만 입력하시면 됩니다. 명령어 입력 후에는 엔터를");
		printf("눌러야 채점에 들어가며 명령어를 하나만 입력해야하는 경우에 두 개 이상을 입력하거나, 명령어 입력 후");
		printf("엔터 말고 다른 키를 누르시면 오답처리 됩니다. 시간 내에 입력하셔야 하지만 명령어 이후 엔터를 잘 눌러주셔야 정답입니다.\n");
		getchar();
	}
	
}