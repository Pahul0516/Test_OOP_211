#include "controller.h"

void controller::contr_populeaza()
{
	repo.citire_fisier();
}

repository& controller::contr_get_repo()
{
	return this->repo;
}


vector<stock>::iterator controller::cautare_dupa_id(string ID)
{
	auto it = find_if(repo.get_lista().begin(), repo.get_lista().end(), [&](stock s) {
		return s.getID() == ID;
		});
	return it;
}

void controller::contr_sterge(string ID)
{
	vector<stock>::iterator it = cautare_dupa_id(ID);
	repo.sterge(it);
}
