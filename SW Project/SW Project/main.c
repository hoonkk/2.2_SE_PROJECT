//10.1 console ��� (�ܼ�â���� Ŀ�� �� �����Ÿ��� �ϱ�) �߰�


#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "console.h"
#include "gamestart.h"
//a -> �� ȭ��ǥ , b -> �Ʒ� ȭ��ǥ, c -> ���� ȭ��ǥ, d- > ������ ȭ��ǥ
void main()
{
	cursorType(NOCURSOR); // Ŀ�� �ȱ����̰� ����
	int firstSet = 0; // �ʱ� Ű ������ ���ϰ� �������� �Ѿ�� ���� �������� ���� ����
	int menu=0;
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
				printf("Ű���� �Ϸ�. �������� �Ѿ���� ���͸� ��������.\n");
				getchar();
				system("cls");
				gameStart();
				

				break;
			
			}
			////Ű ����////
			case 2:
			{
				userKeySetting();
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
