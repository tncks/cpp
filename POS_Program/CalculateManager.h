#pragma once

class CalculateManager {
private:
	unsigned int today;

public:
	CalculateManager();

	void Calculate(unsigned int amount);

public:
	const unsigned int &Today = today;
};