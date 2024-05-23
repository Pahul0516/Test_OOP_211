#pragma once
#include <vector>
#include <fstream>
#include <sstream>

#include "stock.h"

using std::fstream;
using std::vector;
using std::stringstream;
using std::remove;

class repository
{
private:
	int size;
	vector<stock> lista_stockuri;

public:


	vector<stock>& get_lista(); // functie care imi returnaza lista de stock-uri
	void citire_fisier(); // functie care imi face citirea din ficesr
	void sterge(vector<stock>::iterator s); // functe care chiar sterge din fisier
};

