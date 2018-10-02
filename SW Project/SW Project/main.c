//10.1 console 헤더 (콘솔창에서 커서 안 깜빡거리게 하기) 추가


#include <stdio.h>
#include <conio.h>
#include "getKey.h"
#include "keySetting.h"
#include "console.h"
//a -> 위 화살표 , b -> 아래 화살표, c -> 왼쪽 화살표, d- > 오른쪽 화살표
void main()
{
	int firstSet = 0; // 초기 키 설정을 안하고 게임으로 넘어가는 것을 막기위한 변수 선언
	int menu = 0;
	while (1) // 기본 메뉴 출력
	{
		printf("청기백기 게임\n1.게임 시작\n2.키 설정\n3.랭크\n4.게임 종료");
		menu = gets();
		printf("%d", menu);
	}
	
	
}
