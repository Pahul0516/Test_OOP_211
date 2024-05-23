#pragma once
#include <algorithm>


#include "repository.h"

class controller
{
private:
	repository repo;

public:

	void contr_populeaza(); // functie care populeaza repositoy-ul
	repository& contr_get_repo(); // functie care obtine repo-ul
	vector<stock>::iterator cautare_dupa_id(string ID); //functie care cauta un stock dupa id
	void contr_sterge(string ID); // functie care gestioneaza stergerea

};

