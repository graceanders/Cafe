#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>

class MenuItem
{
public:
    std::string Name;
    int Cost;

    MenuItem(std::string name, int cost);
};

#endif