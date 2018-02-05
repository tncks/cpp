#include "stdafx.h"
#include <iostream>
#include "MenuHandler.h"

MenuHandler::MenuHandler(const ObjectPreset &preset, OrderList *pOrderList, CalculateManager *pCalManager)
	: bPrint(true), preset(preset), pOrderList(pOrderList), pCalManager(pCalManager){
}

bool MenuHandler::Run(void)
{
	using namespace std;

	int menu = 0;

	if (bPrint)
	{
		cout << "-----------------------" << endl;
		cout << "| 0. 프로그램 메뉴 다시 출력" << endl;
		cout << "| 1. 현재 주문 조회." << endl;
		cout << "| 2. 새 주문 추가." << endl;
		cout << "| 3. 주문 수정." << endl;
		cout << "| 4. 주문 정산." << endl;
		cout << "| 5. 현재 총 매출액." << endl;
		cout << "| 6. 프로그램 종료." << endl;
		cout << "-----------------------" << endl;

		bPrint = false;
	}

	cout << "메뉴 번호 입력: ";
	cin >> menu;

	switch (menu)
	{
	case 0:
		bPrint = true;
		break;
	case 1:
		PrintOrder();
		break;
	case 2:
		AddOrder();
		break;
	case 3:
		EditOrder();
		break;
	case 4:
		CalculateOrder();
		break;
	case 5:
		cout << endl
			<< "현재 총 매출액: " << pCalManager->Today	<< "원." << endl << endl;
		break;
	case 6:
		return false;
	}

	return true;
}