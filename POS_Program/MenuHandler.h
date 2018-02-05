#pragma once

#include "OrderManager.h"
#include "CalculateManager.h"

class MenuHandler {
private:
	bool bPrint;

	const ObjectPreset &preset;
	OrderList *pOrderList;
	CalculateManager *pCalManager;

private:
	void PrintOrder();
	void AddOrder();
	void EditOrder();
	void CalculateOrder();

public:
	MenuHandler(const ObjectPreset &preset, OrderList *pOrderList, CalculateManager *pCalManager);

	bool Run();
};

