//10.1 console ��� (�ܼ�â���� Ŀ�� �� �����Ÿ��� �ϱ�) �߰�


#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "getKey.h"
#include "console.h"
#include "gamestart.h"
//a -> �� ȭ��ǥ , b -> �Ʒ� ȭ��ǥ, c -> ���� ȭ��ǥ, d- > ������ ȭ��ǥ
void main()
{
	cursorType(NOCURSOR); // Ŀ�� �ȱ����̰� ����
	int firstSet = 0; // �ʱ� Ű ������ ���ϰ� �������� �Ѿ�� ���� �������� ���� ����
	int menu=0;
	int chungUp =0, chungDown = 0, baekUp = 0, baekDown = 0;
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
				printf("Ű���� �Ϸ�. �������� �Ѿ�ϴ�\n");
				system("cls");
				gameStart();
				

				break;
			
			}
			////Ű ����////
			case 2:
			{
				printf("Ű������ �����մϴ�.\nû�⸦ �ø��� ��ư�� �Է����ּ���::\n");
				chungUp = keySetting();
				printf("û�⸦ ������ ��ư�� �Է����ּ���::\n");
				chungDown = keySetting();
				printf("��⸦ �ø��� ��ư�� �Է����ּ���::\n");
				baekUp = keySetting();
				printf("��⸦ ������ ��ư�� �Է����ּ���::\n");
				baekDown = keySetting();
				firstSet++;
				break;
			}
			////��ũ////
			case 3:
			{

			}
			case 4:
			{
				printf("������ �����մϴ�");
				exit(1);
			}
		}
		
	}
	
	
}
