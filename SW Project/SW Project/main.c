//10.1 console ��� (�ܼ�â���� Ŀ�� �� �����Ÿ��� �ϱ�) �߰�


#include <stdio.h>
#include <conio.h>
#include "getKey.h"
#include "console.h"
//a -> �� ȭ��ǥ , b -> �Ʒ� ȭ��ǥ, c -> ���� ȭ��ǥ, d- > ������ ȭ��ǥ
void main()
{
	cursorType(NOCURSOR); // Ŀ�� �ȱ����̰� ����
	int firstSet = 0; // �ʱ� Ű ������ ���ϰ� �������� �Ѿ�� ���� �������� ���� ����
	int menu=0;
	int chungUp=1, chungDown=0, baekUp =0, baekDown = 0;
	while (1) // �⺻ �޴� ���
	{
		
		printf("û���� ����\n1.���� ����\n2.Ű ����\n3.��ũ\n4.���� ����\n");
		scanf_s("%d", &menu);
		switch (menu)
		{
			////���� ����////
			case 1:
			{
				if (firstSet == 0) // Ű ������ ���� �ʰ� ���ӿ� ���� ���
				{
					printf("Ű ������ ���� �����̳׿�\n");
					break;
				}
				printf("Ű���� �Ϸ�. �������� �Ѿ�ϴ�");
				break;
			
			}
			////Ű ����////
			case 2:
			{
				keySetting(chungUp, chungDown, baekUp, baekDown);
				firstSet++;
				break;
			}
		}
		
	}
	
	
}
