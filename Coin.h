#ifndef COIN_H
#define COIN_H

#include <iostream>
#include <string>

class Coin 
{
public:
	std::string Name;
	int Worth;

	Coin(std::string name, double worth);
};

#endif