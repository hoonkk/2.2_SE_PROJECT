#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamestart.h"
#include "console.h"
void gameStart()
{	
	srand((unsigned int)time(NULL)); // ������ cast
	int upDown; // ������ ������ �� �ø��� ������, ������ ������ ���� �ο��ϴ� �����Լ�
	int blueWhite; // û��, ����� �켱������ ����
	char *frontQuestion[] = { "�ø���", "������", "�ø�������",  "����������" }; // ���� ����
	char *backQuestion[] = { "�÷�", "����" , "�ø�����", "��������" }; // ���� ����. ������ ��¦ �ٸ��Ƿ� ���� ����.
	char *blueOrWhite[] = { "û��" , "���" }; // û�� ����� �յ� ������ ����.
	upDown= rand() % 4; // ���� ����Ǽ��� 4���̹Ƿ� rand�� 4���� �޴´�.
	blueWhite = rand() % 2; // ���� ����Ǽ��� 4���̹Ƿ� rand�� 4���� �޴´�.
	printf("���ӽ���!\n");
	printf("%s %s", blueOrWhite[blueWhite],frontQuestion[upDown]); // ������ �� �� ���
	if (blueOrWhite[blueWhite] == "û��")
		blueWhite = 1;
	else if (blueOrWhite[blueWhite] == "���")
		blueWhite = 0;    // û�� ���Ŀ� �� û��, ��� ���Ŀ� �� ��Ⱑ ������ ��� ����.
	upDown = rand() % 4; // ���� �ʱ�ȭ�� ���� rand�� �ٽ� 4���� �޴´�.
	printf(" %s %s\n", blueOrWhite[blueWhite], backQuestion[upDown]); // ������ �� �� ���


	getchar();
	
}

