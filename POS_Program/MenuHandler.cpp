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
		cout << "| 0. ���α׷� �޴� �ٽ� ���" << endl;
		cout << "| 1. ���� �ֹ� ��ȸ." << endl;
		cout << "| 2. �� �ֹ� �߰�." << endl;
		cout << "| 3. �ֹ� ����." << endl;
		cout << "| 4. �ֹ� ����." << endl;
		cout << "| 5. ���� �� �����." << endl;
		cout << "| 6. ���α׷� ����." << endl;
		cout << "-----------------------" << endl;

		bPrint = false;
	}

	cout << "�޴� ��ȣ �Է�: ";
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
			<< "���� �� �����: " << pCalManager->Today	<< "��." << endl << endl;
		break;
	case 6:
		return false;
	}

	return true;
}