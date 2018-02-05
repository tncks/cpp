#include "stdafx.h"
#include "OrderManager.h"

using namespace std;

Order::Order()
	: dpList(0), count(0)
{

}

Order::~Order()
{
	if (dpList)
	{
		for (unsigned int i = 0; i < count; i++) {
			if (dpList[i]) delete dpList[i];
		}
	}
	delete[] dpList;
}

void Order::AddObject(const Object &obj) {
	Object **dpTemp = 0;

	for (unsigned int i = 0; i < count; i++)
	{
		if (dpList[i]->Name == obj.Name) {
			dpList[i]->EditCount(obj.Count);
			return;
		}
	}

	dpTemp = new Object *[count + 1];

	for (unsigned int i = 0; i < count; i++)
	{
		dpTemp[i] = dpList[i];
	}

	dpTemp[count] = new Object(obj);
	count += 1;

	delete[] dpList;
	dpList = dpTemp;

	return;
}

bool Order::DeleteObject(const Object &obj)
{
	unsigned int deleteId = 0;

	Object **dpTemp = 0;

	for (unsigned int i = 0; i < count; i++)
	{
		if (dpList[i]->Name == obj.Name)
		{
			if (dpList[i]->Count <= obj.Count)
			{
				deleteId = i;
				break;
			}
			else {
				dpList[i]->EditCount(-static_cast<int>(obj.Count));
				return false; // 개수 감소했지만 아직 물품이 주문에 남아있음
			}
		}
	}

	if (count > 1)
	{
		dpTemp = new Object *[count - 1];
	}

	for (unsigned int i = 0; i < deleteId; i++)
	{
		dpTemp[i] = dpList[i];
	}
	for (unsigned int i = deleteId + 1; i < count; i++)
	{
		dpTemp[i - 1] = dpList[i];
	}

	delete dpList[deleteId];
	count -= 1;

	delete[] dpList;
	dpList = dpTemp;

	return count == 0;
}

Object *Order::GetObject(unsigned int index) const {
	if (index >= count)
	{
		return 0;
	}

	return dpList[index];
}

Object *Order::GetObject(const string &name) const {
	for (unsigned int i = 0; i < count; i++)
	{
		if (dpList[i]->Name == name)
		{
			return dpList[i];
		}
	}

	return 0;
}

unsigned int Order::Calculate() const {
	unsigned int sum = 0;

	for (unsigned int i = 0; i < count; i++)
	{
		sum += dpList[i]->Calculate();
	}

	return sum;
}