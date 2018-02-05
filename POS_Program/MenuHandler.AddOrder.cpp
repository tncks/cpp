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

	cout << endl << "주문을 추가합니다." << endl << endl;

	pOrder = pOrderList->AddOrder();

	cout << "0을 입력하면 물품 추가를 종료합니다." << endl;
	while (true)
	{
		cout << "물품 이름을 입력하십시요: ";
		cin >> objName;

		if (objName == "0") break;

		cout << "물품 개수를 입력하십시요: ";
		cin >> objCount;

		if (objCount == 0) break;

		pObj = preset.GetObject(objName);

		if (pObj == 0)
		{
			cout << "물품이 없습니다." << endl;
			continue;
		}

		pObj = new Object(objName, pObj->Price, objCount);

		pOrder->AddObject(*pObj);

		delete pObj;

		cout << "물품이 추가되었습니다." << endl << endl;
	}

	if (pOrder->Count == 0)
	{
		cout << "주문이 추가되지 않았습니다." << endl;
		pOrderList->DeleteOrder(pOrderList->Count - 1);

		return;
	}


	cout << "주문이 추가되었습니다. " << endl << endl;
	
	return;


}