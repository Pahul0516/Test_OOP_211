#include "stock.h"

//constructor stock
stock::stock(string ID, string nume, float price, int monthly_ch)
{
	this->ID = ID;
	this->nume = nume;
	this->price = price;
	this->monthly_ch = monthly_ch;

}


// getter  id
string stock::getID()
{
	return this->ID;
}


// getter  nume
string stock::getNume()
{
	return this->nume;
}


// getter  pret
float stock::getPrice()
{
	return this->price;
}


// getter schimabare
int stock::getMontchly_ch()
{
	return this->monthly_ch;
}

