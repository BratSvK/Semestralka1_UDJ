#pragma once
#include "AbstractTester.h";
#include "structures/list/list.h";
#include <iostream>

using namespace std;
using namespace structures;

class ListTester : public AbstractTester {
	
public:
	ListTester(List<int>* list, int itemsCount, char scenario);

	~ListTester();

	void test() override;

private:
	// implementacia listu pre testy vseobecne
	List<int>* _list; 
	void ScenarA();
	void ScenarB();
	void ScenarC();

};



ListTester::ListTester(List<int>* list, int itemsCount, char scenario) : AbstractTester(itemsCount, scenario) {
	_list = list;
}

ListTester::~ListTester() {
	delete _list;
}


// vykonavanie samotneho testu podla scenarov
void ListTester::test() {
	
	switch (tolower(this->getScenario()))
	{
	case 'a':
		this->ScenarA();
		break;
	case 'b': 
		this->ScenarB();
		break;
	case 'c':
		this->ScenarC();
		break;
	default:
		break;
	}
}


// funckie pre scenare podla uzivatela sa doplni casom 
void ListTester::ScenarA() {
	cout << "Ahoj";
}


void ListTester::ScenarB() {
	cout << "Ahoj";

}

void ListTester::ScenarC() {
	cout << "Ahoj";

}