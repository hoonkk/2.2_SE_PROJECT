#include <stdio.h>
#include <stdlib.h> 
#include <time.h> // rand함수 사용, clock()을 위한 헤더
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
#define ENTER 13
#define QUESTION_BUFFER 50
#define LIFE 10
#define FILE_BUFFER 100

void gameStart()
{
	FILE *fp; //파일 생성
	
	srand((unsigned int)time(NULL)); // 강제로 cast
	int upDownFront, upDownBack; // 문제를 출제할 때 올리는 것인지, 내리는 것인지 등을 부여하는 랜드함수
	int blueWhiteFront, blueWhiteBack; // 청기, 백기의 문제 앞, 뒷순위를 결정.
	int userInputFront = 0, userInputBack = 0; // 사용자가 입력한 값 비교
	int uncorrectAnswer; //오답처리
	stageStatus.score = 0;
	stageStatus.time = 0;
	stageStatus.stage = 1;
	stageStatus.life = 1; //임시로 바꿈 테스팅을위해
	double startTimer, endTimer;
	char *frontQuestion[] = { "올리고", "내리고", "올리지말고",  "내리지말고" }; // 앞의 문제
	char *backQuestion[] = { "올려", "내려" , "올리지마", "내리지마" }; // 뒤의 문제. 어투가 살짝 다르므로 따로 설정.
	char *blueOrWhite[] = { "청기" , "백기" }; // 청기 백기의 앞뒤 순서를 결정.
	stageStatus._frontQuestion[0] = "";
	stageStatus._backQuestion[0] = "";
	stageStatus._blueOrWhite[0] = "";
	stageStatus._blueOrWhite[1] = "";
	gotoxy(22, 15);
	printf("게임을  시작합니다 . . . !");
	pause();
	while (1)
	{
		uncorrectAnswer= 0, userInputFront = 0, userInputBack = 0;
		upDownFront = rand() % 4; // 문제 경우의수가 4개이므로 rand로 4개를 받는다.
		blueWhiteFront = rand() % 2; // 청기, 백기임을 결정하는 2개의 rand
		
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
		updateShow(); // 문제 출력
		/* 여기서 부터 시간을 잽니다 */
		startTimer = clock();
		if (upDownFront != DO_NOT_UP && upDownFront != DO_NOT_DOWN) // 문제 전문 앞의 문자가 올리거나, 내리는 경우에만 사용자 INPUT을 받음
				userInputFront = keySetting(); // 사용자의 input(전문)을 받는다
		moveFlag(userInputFront);
		if (upDownBack != DO_NOT_UP && upDownBack != DO_NOT_DOWN) // 문제 후문 앞의 문자가 올리거나, 내리는 경우에만 사용자 INPUT을 받음
				userInputBack = keySetting(); // 사용자의 input(후문)을 받는다
		moveFlag(userInputBack);
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
		gotoxy(28, 12);
		if (isThatRight == ENTER)
		{
			if (uncorrectAnswer == 0)
			{
				printf("G  O  O  D  ♬\n");
				printCharactor(HAPPY);
				stageStatus.score += 50;
			}// 정답인경우
			else
			{
				printf("M  I  S  S !\n"); // 오답인경우
				printCharactor(SAD);
				stageStatus.life--;
			}
		}
		else
		{
			printf("M  I  S  S!\n"); //엔터 말고 다른 것을 누른 경우.
			printCharactor(SAD);
			stageStatus.life--;
		}

		endTimer = clock();
		stageStatus.time += (endTimer - startTimer);
		if (stageStatus.life == 0)
		{
			char a[FILE_BUFFER] = "";

			system("cls"); gotoxy(20, 15); printf("GAME OVER . . . ! "); pause(); system("cls");
			gotoxy(20, 15); printf("총 STAGE : %d   총 걸린 시간 : %.2f초", stageStatus.stage, stageStatus.time/1000);
			gotoxy(20, 17);printf("NAME?(3자까지만 인식하여 입력합니다.)");
			gotoxy(20, 20); printf("┗"); gotoxy(21, 20); printf("━"); 
			gotoxy(22, 20); printf("━"); gotoxy(20, 19); printf("┃"); gotoxy(20, 18); printf("┏");
			gotoxy(21, 18); printf("━"); gotoxy(22, 18); printf("━"); gotoxy(23, 18); printf("━");
			gotoxy(25, 18); printf("┓"); gotoxy(25, 19); printf("┃"); gotoxy(25, 20); printf("┛"); gotoxy(24, 20); printf("━");
			gotoxy(22, 19); scanf_s("%3s", a, FILE_BUFFER);
			fopen_s(&fp,"data\\gamedata.txt", "a");
			fprintf(fp, "%s %.2f^" , a , stageStatus.time/1000);
			fclose(fp);
			pause(); system("cls");
			break;
		}
		gotoxy(20, 2);
		printf("이번 스테이지에서 걸린 시간 :: %.2f초", (endTimer - startTimer)/1000);
		gotoxy(20, 3);
		printf("현재까지 경과 시간 :: %.2f초", stageStatus.time / 1000);
		stageStatus.stage++; // 스테이지 증가
		pause();
		system("cls");
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


