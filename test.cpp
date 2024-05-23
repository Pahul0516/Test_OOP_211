#include "test.h"
#include "stock.h"
#include "repository.h"
#include "controller.h"

#include <assert.h>

void rulare_teste()
{
	test_entitate();
	test_repo();
	test_contr();
}

void test_entitate()
{
	stock* s = new stock{ "APPI", "APPLE",2, 3 };
	assert(s->getID() == "APPI");
	assert(s->getNume() == "APPLE");
	assert(s->getPrice() == 2);
	assert(s->getMontchly_ch() == 3);
}

void test_repo()
{
	repository repo;
	repo.citire_fisier();
	assert(repo.get_lista().size() != 0);
	stock st{ "AAPL", "APPLE",2, 3 };
	auto it = find_if(repo.get_lista().begin(), repo.get_lista().end(), [&](stock s) {
		return st.getID() == s.getID();
		});
	repo.sterge(it);
	assert(repo.get_lista().size()==9);
}


void test_contr()
{
	controller contr;
	contr.contr_populeaza();
	assert(contr.contr_get_repo().get_lista().size() != 0);
	contr.contr_sterge("AAPL");
	assert(contr.contr_get_repo().get_lista().size() == 9);
}
