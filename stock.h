#pragma once
#include <string>

using std::string;

class stock
{
private:

	string ID;
	string nume;
	float price;
	int monthly_ch;

public:

	stock(string ID, string nume, float price, int monthly_ch);
	string getID();
	string getNume();
	float getPrice();
	int getMontchly_ch();

};

