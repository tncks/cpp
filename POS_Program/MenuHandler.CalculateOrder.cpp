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

	cout << endl << "주문을 정산합니다." << endl << endl;

	cout << "정산을 진행할 주문 번호를 입력해주세요: ";
	cin >> index;

	if (index >= pOrderList->Count)
	{
		cout << "잘못된 주문 번호입니다." << endl << endl;
		return;
	}

	pOrder = pOrderList->GetOrder(index);

	calculate = pOrder->Calculate();

	cout << "정산에 필요한 금액: " << calculate << "원." << endl;

	cout << "받은 금액을 입력해주세요: ";
	cin >> amount;

	if (amount < calculate)
	{
		cout << "금액이 부족합니다. 정산이 취소됩니다." << endl << endl;
		return;
	}

	pCalManager->Calculate(calculate);
	cout << endl << "남은 금액은 " << amount - calculate << "원입니다." << endl;

	pOrderList->DeleteOrder(index);

	cout << "정산이 완료되었습니다." << endl << endl;

	return;
}