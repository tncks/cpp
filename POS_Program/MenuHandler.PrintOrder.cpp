#include "stdafx.h"
#include <iostream>

#include "MenuHandler.h"

void MenuHandler::PrintOrder() {
	using namespace std;

	Order *pOrder = 0;
	Object *pObj = 0;
	unsigned int sum = 0;

	cout << endl << "��� �ֹ��� ����մϴ�." << endl << endl;

	if (pOrderList->Count == 0)
	{
		cout << "�ֹ��� �����ϴ�." << endl << endl;

		return;
	}

	for (unsigned int i = 0; i < pOrderList->Count; i++)
	{
		pOrder = pOrderList->GetOrder(i);

		cout << "�ֹ�" << i << "��: " << endl;
		for (unsigned int j = 0; j < pOrder->Count; j++)
		{
			pObj = pOrder->GetObject(j);

			cout << " - " << pObj->Name << " " << pObj->Count << "�� - " << pObj->Calculate() << "��." << endl;
			sum += pObj->Calculate();
		}

		cout << " - �� ���� �ݾ� : " << sum << "��." << endl << endl;

		sum = 0;
	}

	cout << "����� �Ϸ��Ͽ����ϴ�." << endl << endl;

	return;
}