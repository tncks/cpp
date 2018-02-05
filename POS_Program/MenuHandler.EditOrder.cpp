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

	cout << endl << "�ֹ��� �����մϴ�." << endl << endl;
	cout << "������ �ֹ� ��ȣ�� �Է��Ͻʽÿ�: ";
	cin >> index;

	if (index >= pOrderList->Count)
	{
		cout << "�߸��� �ֹ� ��ȣ�Դϴ�." << endl << endl;
		return;
	}

	pEditing = pOrderList->GetOrder(index);

	cout << "�����ϰ��� �ϴ� ���� �����ʰ� ���¿� ���� �Է����ּ���([��ǰ] [����] [�߰�/����]) : ";
	cin >> objName >> objCount >> behavior;

	if (behavior == "�߰�")
	{
		pEditObj = preset.GetObject(objName);

		if (pEditObj == 0)
		{
			cout << "��ǰ�� ã�� �� �����ϴ�." << endl << endl;
			return;
		}
		else {
			pEditObj = new Object(objName, pEditObj->Price, objCount);
			pEditing->AddObject(*pEditObj);
			delete pEditObj;
		}
	}
	else if (behavior == "����")
	{
		pEditObj = pEditing->GetObject(objName);

		if (pEditObj == 0)
		{
			cout << " ��ǰ�� ã�� �� �����ϴ�." << endl << endl;
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
		cout << "�ൿ�� �߸� �Է��ϼ̽��ϴ�." << endl << endl;
		return;
	}

	cout << "������ �Ϸ�Ǿ����ϴ�." << endl << endl;

	return;
}