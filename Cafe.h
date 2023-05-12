#ifndef CAFE_H
#define CAFE_H

#include <list>
#include "Coin.h"

void RunCafe();

int MinimumCoins(std::list<Coin> coins, int cost);

void WhichChoice(double cost, std::string name);

void WhichDrink();

void WhichFood();

#endif