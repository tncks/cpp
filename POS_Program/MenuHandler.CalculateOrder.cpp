#include "stdafx.h"
#include <iostream>

#include "MenuHandler.h"

void MenuHandler::CalculateOrder()
{
	using namespace std;

	unsigned int index = 0;
	unsigned int calculate = 0;
	unsigned int amount = 0;

	Order *pOrder = 0;

	cout << endl << "�ֹ��� �����մϴ�." << endl << endl;

	cout << "������ ������ �ֹ� ��ȣ�� �Է����ּ���: ";
	cin >> index;

	if (index >= pOrderList->Count)
	{
		cout << "�߸��� �ֹ� ��ȣ�Դϴ�." << endl << endl;
		return;
	}

	pOrder = pOrderList->GetOrder(index);

	calculate = pOrder->Calculate();

	cout << "���꿡 �ʿ��� �ݾ�: " << calculate << "��." << endl;

	cout << "���� �ݾ��� �Է����ּ���: ";
	cin >> amount;

	if (amount < calculate)
	{
		cout << "�ݾ��� �����մϴ�. ������ ��ҵ˴ϴ�." << endl << endl;
		return;
	}

	pCalManager->Calculate(calculate);
	cout << endl << "���� �ݾ��� " << amount - calculate << "���Դϴ�." << endl;

	pOrderList->DeleteOrder(index);

	cout << "������ �Ϸ�Ǿ����ϴ�." << endl << endl;

	return;
}