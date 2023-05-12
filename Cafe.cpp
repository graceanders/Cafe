#include <climits>
#include <iostream>
#include <list>

#include "Coin.h"
#include "Cafe.h"
#include "MenuItem.h"

using namespace std;

void RunCafe()
{
    WhichDrink();
    system("pause");
    WhichFood();
    std::cout << "\nThank you for shopping at my Cafe :)\n";
    system("pause");
}

Coin Dollar("Dollar", 100);
Coin Quarter("Quarter", 25);
Coin Dime("Dime", 10);
Coin Nickel("Nickel", 05);
Coin Penny("Penny", 01);

list<Coin> Coins{ Dollar, Quarter, Dime, Nickel, Penny };

//NOC = number of coins
int NODollars, NOQuarters, NODimes, NONickels, NOPennies;

int MinimumCoins(list<Coin> coins, int cost) {
	
	if (cost == 0) { return 0; }

    NODollars = 0;
    NOQuarters = 0;
    NODimes = 0;
    NONickels = 0;
    NOPennies = 0;


	 for (const Coin& coin : coins)
    {
        while (cost >= coin.Worth)
        {
            cost = cost - coin.Worth;

            if (coin.Name == "Dollar")
            {
                NODollars++;
            }
            else if (coin.Name == "Quarter")
            {
                NOQuarters++;
            }
            else if (coin.Name == "Dime")
            {
                NODimes++;
            }
            else if (coin.Name == "Nickel")
            {
                NONickels++;
            }
            else if (coin.Name == "Penny")
            {
                NOPennies++;
            }

            if (cost <= 0) { return 0; }
        }
    }

	return 0;
}

double Money = 100;
int HowMany;
int TotalCost;
void WhichChoice(double Cost, std::string Name)
{
	HowMany = 0;
	cout << "\nHow many "<< Name<<"'s would you like to buy?\n";
	cin>>HowMany;
	for (int i = 1; i <= HowMany; i++) {
		Money = Money - Cost;
	}

	cout << "\nYou bought "<< HowMany << " " << Name << " for $" << Cost * HowMany << "\nYou now have $" << Money << "\n";
	MinimumCoins(Coins, ((Cost * HowMany) * 100));
	cout << "Change for "<< Cost * HowMany <<"\nDollars: " << NODollars << "\nQuarters: " << NOQuarters << "\nDime: " << NODimes << "\nNickel: " << NONickels << "\nPennies:" << NOPennies << "\n";
}

int WhichOption;
double Conversion;
void WhichDrink() {

	MenuItem Coffee("Coffee", 200);
	MenuItem IcedCoffee("Iced Coffee", 200);
	MenuItem Latte("Latte", 225);
	MenuItem HotChocolate("Hot Chocolate", 150);

	list<MenuItem> Drinks{ Coffee, IcedCoffee, Latte, HotChocolate };


	cout << "\nWhat drink would you like to buy from the Cafe?\n";
	int i = 0;
	for (MenuItem x : Drinks) {
		i++;
		Conversion = x.Cost;
		Conversion = Conversion / 100;
		cout << i << ": " << x.Name << ": $" << Conversion << "\n";
	}

	cin >> WhichOption;
	if (WhichOption == 1) { WhichChoice(2.00, "Coffee"); }
	if (WhichOption == 2) { WhichChoice(2.00, "Iced Coffee"); }
	if (WhichOption == 3) { WhichChoice(2.25, "Latte"); }
	if (WhichOption == 4) { WhichChoice(1.50, "Hot Chocolate"); }
}

void WhichFood() 
{
	MenuItem Bagel("Bagel", 300);
	MenuItem Sandwich("Sandwich", 525);
	MenuItem Pastry("Pastry", 115);
	MenuItem Muffin("Muffin", 170);

	list<MenuItem> Food{ Bagel, Sandwich, Pastry, Muffin };

	cout << "What food item would you like to buy from the Cafe?\n";
	int i = 0;
	for (MenuItem x : Food) {
		i++;
		Conversion = x.Cost;
		Conversion = Conversion / 100;
		cout << i << ": " << x.Name << ": $" << Conversion << "\n";\
	}

	cin >> WhichOption;
	if (WhichOption == 1) { WhichChoice(3.00, "Bagel"); }
	if (WhichOption == 2) { WhichChoice(5.25, "Sandwich"); }
	if (WhichOption == 3) { WhichChoice(1.15, "Pastry"); }
	if (WhichOption == 4) { WhichChoice(1.70, "Muffin"); }

}