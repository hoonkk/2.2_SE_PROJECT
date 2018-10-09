#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamestart.h"
#include "console.h"
void gameStart()
{	
	srand((unsigned int)time(NULL)); // 강제로 cast
	int upDown; // 문제를 출제할 때 올리는 것인지, 내리는 것인지 등을 부여하는 랜드함수
	int blueWhite; // 청기, 백기의 우선순위를 결정
	char *frontQuestion[] = { "올리고", "내리고", "올리지말고",  "내리지말고" }; // 앞의 문제
	char *backQuestion[] = { "올려", "내려" , "올리지마", "내리지마" }; // 뒤의 문제. 어투가 살짝 다르므로 따로 설정.
	char *blueOrWhite[] = { "청기" , "백기" }; // 청기 백기의 앞뒤 순서를 결정.
	upDown= rand() % 4; // 문제 경우의수가 4개이므로 rand로 4개를 받는다.
	blueWhite = rand() % 2; // 문제 경우의수가 4개이므로 rand로 4개를 받는다.
	printf("게임시작!\n");
	printf("%s %s", blueOrWhite[blueWhite],frontQuestion[upDown]); // 문제의 앞 문 출력
	if (blueOrWhite[blueWhite] == "청기")
		blueWhite = 1;
	else if (blueOrWhite[blueWhite] == "백기")
		blueWhite = 0;    // 청기 이후에 또 청기, 백기 이후에 또 백기가 나오는 경우 차단.
	upDown = rand() % 4; // 문제 초기화를 위해 rand로 다시 4개를 받는다.
	printf(" %s %s\n", blueOrWhite[blueWhite], backQuestion[upDown]); // 문제의 뒷 문 출력


	getchar();
	
}

