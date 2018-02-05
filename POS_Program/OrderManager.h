#pragma once

#include "Object.h"

class Order {
private:
	Object **dpList;
	unsigned int count;

public:
	Order();
	~Order();

	void AddObject(const Object &obj);
	bool DeleteObject(const Object &obj);

	Object *GetObject(unsigned int index) const; //상수객체용 메소드
	Object *GetObject(const std::string &name) const;

	unsigned int Calculate() const;

public:
	const unsigned int &Count = count;
};

class OrderList {
private:
	Order **dpList;
	unsigned int count;

public:
	OrderList();
	~OrderList();

	Order *AddOrder();
	void DeleteOrder(unsigned int index);

	Order *GetOrder(unsigned int index);
	const Order *GetOrder(unsigned int index) const;

public:
	const unsigned int &Count = count;
};

typedef Order ObjectPreset;