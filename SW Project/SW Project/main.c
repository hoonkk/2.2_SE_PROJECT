//10.1 console 헤더 (콘솔창에서 커서 안 깜빡거리게 하기) 추가


#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "console.h"
#include "gamestart.h"
//a -> 위 화살표 , b -> 아래 화살표, c -> 왼쪽 화살표, d- > 오른쪽 화살표
void main()
{
	cursorType(NOCURSOR); // 커서 안깜빡이게 설정
	int firstSet = 0; // 초기 키 설정을 안하고 게임으로 넘어가는 것을 막기위한 변수 선언
	int menu=0;
	int blueUp =0, blueDown = 0, whiteUp = 0, whiteDown = 0;
	while (1) // 기본 메뉴 출력
	{
		
		printf("청기백기 게임\n1.게임 시작\n2.키 설정\n3.랭크\n4.게임 종료\n");
		scanf_s("%d", &menu);
		switch (menu)
		{
			////게임 시작////
			case 1:
			{
				if (firstSet == 0) // 키 설정을 하지 않고 게임에 들어가는 경우
				{
					printf("키 설정을 하지 않으셨네요\n");
					break;
				}
				printf("키셋팅 완료. 게임으로 넘어가려면 엔터를 누르세요.\n");
				getchar();
				system("cls");
				gameStart();
				

				break;
			
			}
			////키 설정////
			case 2:
			{
				printf("키셋팅을 시작합니다.\n청기를 올리는 버튼을 입력해주세요::\n");
				blueUp = keySetting();
				printf("입력하신 키는 "); putchar(blueUp); printf(" 입니다");
				printf("청기를 내리는 버튼을 입력해주세요::\n");
				blueDown = keysSetting();
				printf("백기를 올리는 버튼을 입력해주세요::\n");
				whiteUp = keySetting();
				printf("백기를 내리는 버튼을 입력해주세요::\n");
				whiteDown = keySetting();
				firstSet++;
				break;
			}
			////랭크////
			case 3:
			{

			}
			case 4:
			{
				printf("게임을 종료합니다");
				exit(1);
			}
		}
		
	}
	
	
}
