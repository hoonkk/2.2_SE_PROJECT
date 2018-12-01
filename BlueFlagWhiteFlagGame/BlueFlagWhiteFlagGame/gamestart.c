#include <stdio.h>
#include <conio.h>
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
	gameIntro();
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

		userInputFront = keySetting(); // 사용자의 input(전문)을 받는다
		moveFlag(userInputFront);
		userInputBack = keySetting(); // 사용자의 input(후문)을 받는다
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
			gotoxy(28, 12); printf("G  O  O  D  ♬  ");
			printCharactor(HAPPY);
		}// 정답인경우
		else
		{
			gotoxy(28, 12); printf("M  I  S  S !   "); // 오답인경우
			printCharactor(SAD);
			stageStatus.life--;
		}
		if (stageStatus.life == 0) // 게임오버
		{
			pause();
			system("cls");
			textcolor(FONT_RED);
			for (int i = 0; i < 5; i++) // 깜빡이는 효과
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
		printf("현재까지 경과 시간 :: %.2f초", stageStatus.time / 1000);
		stageStatus.stage++; // 스테이지 증가
		if (stageStatus.stage == 2) // 클리어
		{
			char a[FILE_BUFFER] = "";
			pause();
			system("cls"); 
			printCharactor(HAPPY);
			for (int i = 0; i < 5; i++) // 깜빡이는 효과
			{
				gotoxy(25, 10); printf("                   "); Sleep(100);
				gotoxy(25, 10); printf("C  L  E  A  R  !  !"); Sleep(100);
				gotoxy(25, 12); for (int a = 0; a <= i; a++) printf("★  ");
				gotoxy(25, 8); for (int a = 0; a <= i; a++) printf("★  ");
				Sleep(100);
			}
			
			pause(); system("cls");
			textcolor(FONT_YELLOW);
			gotoxy(17, 10); printf("총 STAGE : %d   총 걸린 시간 : %.2f초", stageStatus.stage, stageStatus.time / 1000);
			textcolor(FONT_CYAN);
			gotoxy(10, 17); printf("랭킹에 등록할 이름을 입력하세요");
			gotoxy(10, 18); printf("3자까지만 인식하여 입력되며, 알파벳 OR 숫자로 입력하세요");
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
	else if ((upDownCheck == DO_NOT_UP || upDownCheck == DO_NOT_DOWN) && userInputCheck == SPACEBAR)
		return true;
	else return false;
}


