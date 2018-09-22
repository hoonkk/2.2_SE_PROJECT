#include <stdio.h>
#include <conio.h>
//a -> 위 화살표 , b -> 아래 화살표, c -> 왼쪽 화살표, d- > 오른쪽 화살표
void main()
{
	char x[] = "abcdabcd";
	int key;
	for (int i = 0; i < 8; i++)
	{
		switch (x[i]) {
		case 'a':
			printf("↑");
			break;
		case 'b':
			printf("↓");
			break;
		case 'c':
			printf("←");
			break;
		case 'd':
			printf("→");
			break;
		default:
			printf("올바른 값이 아닙니다.\n");

		}

	}

	printf("\n화살표를 입력하세요.\n");

	for (int j = 0; j < 8; j++) {
		key = getch();
		switch (x[j]) {
		case 'a':
			if (key == 224)
			{
				key = getch();
				if (key == 72)
				{
					printf("입력 성공\n");
				}
				else
				{
					printf("입력 실패\n");
				}
			}

		case 'b':
			if (key == 224)
			{
				key = getch();
				if (key == 80)
				{
					printf("입력 성공\n");
				}
				else
				{
					printf("입력 실패\n");
				}
			}

		case 'c':
			if (key == 224)
			{
				key = getch();
				if (key == 75)
				{
					printf("입력 성공\n");
				}
				else
				{
					printf("입력 실패\n");
				}
			}


		case 'd':
			if (key == 224)
			{
				key = getch();
				if (key == 77)
				{
					printf("입력 성공\n");
				}
				else
				{
					printf("입력 실패\n");
				}
			}



		}

	}



}