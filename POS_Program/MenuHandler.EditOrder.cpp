#include "stdafx.h"
#include <iostream>
#include <string>

#include "MenuHandler.h"

void MenuHandler::EditOrder()
{
	using namespace std;

	unsigned int index = 0;

	Order *pEditing = 0;
	Object *pEditObj = 0;

	string objName;
	unsigned int objCount;
	string behavior;

	cout << endl << "주문을 수정합니다." << endl << endl;
	cout << "수정할 주문 번호를 입력하십시요: ";
	cin >> index;

	if (index >= pOrderList->Count)
	{
		cout << "잘못된 주문 번호입니다." << endl << endl;
		return;
	}

	pEditing = pOrderList->GetOrder(index);

	cout << "수정하고자 하는 것을 오른쪽과 형태와 같이 입력해주세요([물품] [개수] [추가/제거]) : ";
	cin >> objName >> objCount >> behavior;

	if (behavior == "추가")
	{
		pEditObj = preset.GetObject(objName);

		if (pEditObj == 0)
		{
			cout << "물품을 찾을 수 없습니다." << endl << endl;
			return;
		}
		else {
			pEditObj = new Object(objName, pEditObj->Price, objCount);
			pEditing->AddObject(*pEditObj);
			delete pEditObj;
		}
	}
	else if (behavior == "제거")
	{
		pEditObj = pEditing->GetObject(objName);

		if (pEditObj == 0)
		{
			cout << " 물품을 찾을 수 없습니다." << endl << endl;
			return;
		}
		else
		{
			pEditObj = new Object(objName, pEditObj->Price, objCount);

			if (pEditing->DeleteObject(*pEditObj)) {
				pOrderList->DeleteOrder(index);
			}
			delete pEditObj;
		}
	}
	else
	{
		cout << "행동을 잘못 입력하셨습니다." << endl << endl;
		return;
	}

	cout << "수정이 완료되었습니다." << endl << endl;

	return;
}