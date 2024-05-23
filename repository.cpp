#include "repository.h"

vector<stock>& repository::get_lista()
{
	return this->lista_stockuri;
}

void repository::citire_fisier()
{
	fstream f("Stock.txt");
	string line;
	while (getline(f, line))
	{
		string ID, nume, price, monthly_ch;
		float p;
		int monthly;
		stringstream ff(line);
		ff >> ID >> nume >> price >> monthly_ch;
		p = stof(price);
		monthly = stoi(monthly_ch);
		stock* s = new stock{ ID,nume,p,monthly };
		this->lista_stockuri.push_back(*s);
		size++;
	}
}

void repository::sterge(vector<stock>::iterator s)
{
	lista_stockuri.erase(s);
	size--;
}
