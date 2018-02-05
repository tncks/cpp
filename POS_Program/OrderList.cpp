#include "stdafx.h"
#include "OrderManager.h"

OrderList::OrderList()
	: dpList(0), count(0)
{
}

OrderList::~OrderList()
{
	if (dpList)
	{
		for (unsigned int i = 0; i < count; i++)
		{
			if (dpList[i]) delete dpList[i];
		}
	}

	delete[] dpList;
}

Order *OrderList::AddOrder() {
	Order **dpTemp = 0;

	dpTemp = new Order *[count + 1];

	for (unsigned int i = 0; i < count; i++)
	{
		dpTemp[i] = dpList[i];
	}

	dpTemp[count] = new Order;
	count += 1;

	delete[] dpList;
	dpList = dpTemp;

	return dpList[count - 1];
}

void OrderList::DeleteOrder(unsigned int index)
{
	Order **dpTemp = 0;

	if (index >= count) {
		return;
	}

	dpTemp = new Order *[count - 1];

	for (unsigned int i = 0; i < index; i++) {
		dpTemp[i] = dpList[i];
	}
	for (unsigned int i = index + 1; i < count; i++)
	{
		dpTemp[i - 1] = dpList[i];
	}

	delete dpList[index];
	count -= 1;

	delete[] dpList;
	dpList = dpTemp;

	return;
}

Order *OrderList::GetOrder(unsigned int index)
{
	if (index >= count) return 0;

	return dpList[index];

}

const Order *OrderList::GetOrder(unsigned int index) const
{
	if (index >= count) return 0;

	return dpList[index];
}