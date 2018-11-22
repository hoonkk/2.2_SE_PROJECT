#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>
#include "console.h"
#include "gamestart.h"
#include "rangking.h"


void main()
{
	system("title BlueFlagWhiteFlagGame"); // 콘솔 이름 설정
	system("mode con cols=70 lines=31"); // 콘솔 창 크기 설정
	cursorType(NOCURSOR); // 커서 안깜빡이게 설정

	int firstSet = 0; // 초기 키 설정을 안하고 게임으로 넘어가는 것을 막기위한 변수 선언
	int menu = 0;
	while (1) // 기본 메뉴 출력
	{

		printMenu();
		scanf_s("%d", &menu);
		switch (menu)
		{
			////게임 시작////
		case 1:
		{
			system("cls");
			if (firstSet == 0) // 키 설정을 하지 않고 게임에 들어가는 경우
			{
				printf("키 설정을 하지 않으셨네요\n");
				break;
			}
			gotoxy(12, 15);
			printf("키셋팅 완료. 게임으로 넘어가려면 엔터를 누르세요.\n");
			pause();
			system("cls");
			gameStart();
			break;

		}
		////키 설정////
		case 2:
		{
			system("cls");
			userKeySetting();
			firstSet++;
			break;
		}
		////랭크////
		case 3:
		{
			system("cls");
			showRangking();
			break;
		}
		case 4:
		{
			printf("게임을 종료합니다");
			exit(1);
		}
		}

	}


}