//10.1 console ��� (�ܼ�â���� Ŀ�� �� �����Ÿ��� �ϱ�) �߰�


#include <stdio.h>
#include <conio.h>
#include "getKey.h"
#include "keySetting.h"
#include "console.h"
//a -> �� ȭ��ǥ , b -> �Ʒ� ȭ��ǥ, c -> ���� ȭ��ǥ, d- > ������ ȭ��ǥ
void main()
{
	int firstSet = 0; // �ʱ� Ű ������ ���ϰ� �������� �Ѿ�� ���� �������� ���� ����
	int menu = 0;
	while (1) // �⺻ �޴� ���
	{
		printf("û���� ����\n1.���� ����\n2.Ű ����\n3.��ũ\n4.���� ����");
		menu = gets();
		printf("%d", menu);
	}
	
	
}
