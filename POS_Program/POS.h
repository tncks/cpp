#pragma once

#include "MenuHandler.h"
#include "OrderManager.h"
#include "CalculateManager.h"

class POS {
private:
	MenuHandler handle;

	ObjectPreset preset;

	OrderList orderList;

	CalculateManager calManager;

public:
	POS();

	int Run();
};