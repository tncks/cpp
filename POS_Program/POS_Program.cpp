#include "stdafx.h"
#include <iostream>
#include "POS.h"

POS::POS()
	: handle(preset, &orderList, &calManager)
{
	preset.AddObject(Object("사과", 100, 1));
	preset.AddObject(Object("배", 200, 1));
	preset.AddObject(Object("수박", 500, 1));
}

int POS::Run()
{
	using namespace std;

	cout << "POS Project with OOP 1.0." << endl << endl;

	while (handle.Run());

	return 0;
}