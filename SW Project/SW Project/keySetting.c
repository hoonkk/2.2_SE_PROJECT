#include "keySetting.h"
#include "getKey.h"
#include <stdio.h>
#include <conio.h>

int keySetting() // 청기 백기 올리고 내리는 키를 사용자가 직접 지정하는 함수
{
	printf("지금부터 키를 지정합니다. TEST용이니 알파벳 소문자만 입력하세요.\n");
	getKey();
}