#include "stdafx.h"
#include <iostream>
#include <string>

#include "MenuHandler.h"

void MenuHandler::AddOrder()
{
	using namespace std;

	string objName;
	unsigned int objCount = 0;
	Object *pObj = 0;

	Order *pOrder = 0;

	cout << endl << "�ֹ��� �߰��մϴ�." << endl << endl;

	pOrder = pOrderList->AddOrder();

	cout << "0�� �Է��ϸ� ��ǰ �߰��� �����մϴ�." << endl;
	while (true)
	{
		cout << "��ǰ �̸��� �Է��Ͻʽÿ�: ";
		cin >> objName;

		if (objName == "0") break;

		cout << "��ǰ ������ �Է��Ͻʽÿ�: ";
		cin >> objCount;

		if (objCount == 0) break;

		pObj = preset.GetObject(objName);

		if (pObj == 0)
		{
			cout << "��ǰ�� �����ϴ�." << endl;
			continue;
		}

		pObj = new Object(objName, pObj->Price, objCount);

		pOrder->AddObject(*pObj);

		delete pObj;

		cout << "��ǰ�� �߰��Ǿ����ϴ�." << endl << endl;
	}

	if (pOrder->Count == 0)
	{
		cout << "�ֹ��� �߰����� �ʾҽ��ϴ�." << endl;
		pOrderList->DeleteOrder(pOrderList->Count - 1);

		return;
	}


	cout << "�ֹ��� �߰��Ǿ����ϴ�. " << endl << endl;
	
	return;


}