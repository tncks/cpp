#include "stdafx.h"
#include <iostream>

#include "MenuHandler.h"

void MenuHandler::PrintOrder() {
	using namespace std;

	Order *pOrder = 0;
	Object *pObj = 0;
	unsigned int sum = 0;

	cout << endl << "모든 주문을 출력합니다." << endl << endl;

	if (pOrderList->Count == 0)
	{
		cout << "주문이 없습니다." << endl << endl;

		return;
	}

	for (unsigned int i = 0; i < pOrderList->Count; i++)
	{
		pOrder = pOrderList->GetOrder(i);

		cout << "주문" << i << "번: " << endl;
		for (unsigned int j = 0; j < pOrder->Count; j++)
		{
			pObj = pOrder->GetObject(j);

			cout << " - " << pObj->Name << " " << pObj->Count << "개 - " << pObj->Calculate() << "원." << endl;
			sum += pObj->Calculate();
		}

		cout << " - 총 정산 금액 : " << sum << "원." << endl << endl;

		sum = 0;
	}

	cout << "출력을 완료하였습니다." << endl << endl;

	return;
}