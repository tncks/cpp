#include "stdafx.h"
#include "CalculateManager.h"

CalculateManager::CalculateManager()
	:today(0)
{

}

void CalculateManager::Calculate(unsigned int amount)
{
	today += amount;

	return;
}

