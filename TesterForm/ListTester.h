#pragma once
#include "AbstractTester.h";
#include "structures/list/list.h";
#include "structures/list/array_list.h"
#include "structures/list/linked_list.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>  


using namespace std;
using namespace structures;
using namespace System::Windows::Forms;

class ListTester : public AbstractTester {
	
public:
	ListTester(List<int>* list, int itemsCount, char scenario);

	~ListTester();

	void test() override;

private:
	// implementacia listu pre testy vseobecne
	List<int>* _list; 
	int iMethod, iOperation;
	void ScenarA();
	void ScenarB();
	void ScenarC();
	bool inRange(int number, int lower, int upper);
    
};



ListTester::ListTester(List<int>* list, int itemsCount, char scenario) : AbstractTester(itemsCount, scenario) {
	_list = list;
	iMethod = 0;
	iOperation = 0;
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

bool ListTester::inRange(int number,int lower, int upper) {
	return (number > lower && number <= upper);
}


// funckie pre scenare podla uzivatela sa doplni casom 
void ListTester::ScenarA() {
	MessageBox::Show("Scenar A zaèal...!");
	int cisloNaVlozenie;
	// suborove vlastnosti
	char delimiter = ';';
	stringstream fileName;

	// Create an output filestream object
	if (dynamic_cast<ArrayList<int>*>(_list) == nullptr)
	{
		fileName << "LinkedList_" << "A_" << this->getItemsCount() << ".csv";
	}
	else {
		fileName << "ArrayList_" << "A_" << this->getItemsCount() << ".csv";
	}

	ofstream myFile;
	// we dont wanna append to file 
	myFile.open(fileName.str());
	// hlavicka 
	myFile << "Operacia" << delimiter << "PocetPrvkov"<< delimiter << "TrvanieOperacie" << endl;
	// vykonat 100000 operaci aby sme dostali ustalene hodnoty
	int pocetVykonanychOperaci = 0;
	while (pocetVykonanychOperaci < this->getItemsCount()){
		
		iMethod = rand() % 100 + 1;
		cisloNaVlozenie = rand() % 100000 + 1;

		if (inRange(iMethod, 0, 20)) {
			iOperation = rand() % 3 + 1;

			int indexNaVlozenie;
		
			// get index of array size
			if (static_cast<int>(_list->size()) == 0) {
				indexNaVlozenie = 0;
			}
			else {
				indexNaVlozenie = rand() % static_cast<int>(_list->size() + 1) ;  // size = 6 -> (0-6)
			}
			// vyber operacie VLOZ(zaciatok,nakoniec, na index -> platny)
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				_list->insert(cisloNaVlozenie, 0);
				break;
			case 2:
				_list->add(cisloNaVlozenie);
				break;
			case 3:
				_list->insert(cisloNaVlozenie, indexNaVlozenie);
			default:
				break;
			}
			
			auto end = chrono::high_resolution_clock::now();

			// zapis to csv
			
			myFile << "Vloz" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
			
		}
		else if (inRange(iMethod, 20, 40)) {
			// ked mam prazdny zoznam preskocim 
			if (static_cast<int>(_list->size() == 0))
				continue;
		
			
			int indexNaVymazanie;
			// get index of array size
			if (static_cast<int>(_list->size()) == 1) {
				indexNaVymazanie = 0;
			}
			else {
				indexNaVymazanie = rand() % (static_cast<int>(_list->size())); // chceme platne indexi, size -> 3 -> 0-2
			}

			iOperation = rand() % 3 + 1;
			// vyber operacie VLOZ(zaciatok,nakoniec, na index -> platny)
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				_list->removeAt(0);
				break;
			case 2:
				_list->removeAt((static_cast<int>(_list->size()) - 1));
				break;
			case 3:
				_list->removeAt(indexNaVymazanie);
			default:
				break;
			}
			auto end = chrono::high_resolution_clock::now();
			myFile << "Vymaz" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
		}
		else if (inRange(iMethod, 40, 90)) {
			if (static_cast<int>(_list->size() == 0))
				continue;
			iOperation = rand() % 2 + 1;
			int prvok;
			int indexNaSpristupnenie;
			// get index of array size
			if (static_cast<int>(_list->size()) == 1) {
				indexNaSpristupnenie = 0;
			}
			else {
				indexNaSpristupnenie = rand() % (static_cast<int>(_list->size()));
			}
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				prvok = _list->operator[](indexNaSpristupnenie);
				break;
			case 2:
				_list->operator[](indexNaSpristupnenie) = cisloNaVlozenie;
				break;
			default:
				break;
			}
			auto end = chrono::high_resolution_clock::now();
			myFile << "DajData/NastavData" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
}
		else {
			if (static_cast<int>(_list->size() == 0))
				continue;
			auto start = chrono::high_resolution_clock::now();
			int index = _list->getIndexOf(cisloNaVlozenie);
			auto end = chrono::high_resolution_clock::now();
			myFile << "DajIndex" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
}
	}
	myFile.close();
	
}

void ListTester::ScenarB() {
	MessageBox::Show("Scenar B zaèal...!");
	int cisloNaVlozenie;
	// suborove vlastnosti
	char delimiter = ';';
	stringstream fileName;

	// Create an output filestream object
	if (dynamic_cast<ArrayList<int>*>(_list) == nullptr)
	{
		fileName << "LinkedList_" << "B_" << this->getItemsCount() << ".csv";
	}
	else {
		fileName << "ArrayList_" << "B_" << this->getItemsCount() << ".csv";
	}

	ofstream myFile;
	// we dont wanna append to file 
	myFile.open(fileName.str());
	myFile << "Operacia" << delimiter << "PocetPrvkov" << delimiter << "TrvanieOperacie" << endl;
	// vykonat 100000 operaci aby sme dostali ustalene hodnoty
	int pocetVykonanychOperaci = 0;
	while (pocetVykonanychOperaci < this->getItemsCount()) {

		iMethod = rand() % 100 + 1;
		cisloNaVlozenie = rand() % 100000 + 1;

		if (inRange(iMethod, 0, 35)) {
			iOperation = rand() % 3 + 1;

			int indexNaVlozenie;

			// get index of array size
			if (static_cast<int>(_list->size()) == 0) {
				indexNaVlozenie = 0;
			}
			else {
				indexNaVlozenie = rand() % static_cast<int>(_list->size() + 1);  // size = 6 -> (0-6)
			}
			// vyber operacie VLOZ(zaciatok,nakoniec, na index -> platny)
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				_list->insert(cisloNaVlozenie, 0);
				break;
			case 2:
				_list->add(cisloNaVlozenie);
				break;
			case 3:
				_list->insert(cisloNaVlozenie, indexNaVlozenie);
			default:
				break;
			}

			auto end = chrono::high_resolution_clock::now();

			// zapis to csv

			myFile << "Vloz" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;

		}
		else if (inRange(iMethod, 35, 70)) {
			// ked mam prazdny zoznam preskocim 
			if (static_cast<int>(_list->size() == 0))
				continue;


			int indexNaVymazanie;
			// get index of array size
			if (static_cast<int>(_list->size()) == 1) {
				indexNaVymazanie = 0;
			}
			else {
				indexNaVymazanie = rand() % (static_cast<int>(_list->size())); // chceme platne indexi, size -> 3 -> 0-2
			}

			iOperation = rand() % 3 + 1;
			// vyber operacie VLOZ(zaciatok,nakoniec, na index -> platny)
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				_list->removeAt(0);
				break;
			case 2:
				_list->removeAt((static_cast<int>(_list->size()) - 1));
				break;
			case 3:
				_list->removeAt(indexNaVymazanie);
			default:
				break;
			}
			auto end = chrono::high_resolution_clock::now();
			myFile << "Vymaz" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
		}
		else if (inRange(iMethod, 70, 90)) {
			if (static_cast<int>(_list->size() == 0))
				continue;
			iOperation = rand() % 2 + 1;
			int prvok;
			int indexNaSpristupnenie;
			// get index of array size
			if (static_cast<int>(_list->size()) == 1) {
				indexNaSpristupnenie = 0;
			}
			else {
				indexNaSpristupnenie = rand() % (static_cast<int>(_list->size()));
			}
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				prvok = _list->operator[](indexNaSpristupnenie);
				break;
			case 2:
				_list->operator[](indexNaSpristupnenie) = cisloNaVlozenie;
				break;
			default:
				break;
			}
			auto end = chrono::high_resolution_clock::now();
			myFile << "DajData/NastavData" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
		}
		else {
			if (static_cast<int>(_list->size() == 0))
				continue;
			auto start = chrono::high_resolution_clock::now();
			int index = _list->getIndexOf(cisloNaVlozenie);
			auto end = chrono::high_resolution_clock::now();
			myFile << "DajIndex" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
		}
	}
	myFile.close();
}

void ListTester::ScenarC() {
	MessageBox::Show("Scenar C zaèal...!");
	int cisloNaVlozenie;
	// suborove vlastnosti
	char delimiter = ';';
	stringstream fileName;

	// Create an output filestream object
	if (dynamic_cast<ArrayList<int>*>(_list) == nullptr)
	{
		fileName << "LinkedList_" << "C_" << this->getItemsCount() << ".csv";
	}
	else {
		fileName << "ArrayList_" << "C_" << this->getItemsCount() << ".csv";
	}

	ofstream myFile;
	// we dont wanna append to file 
	myFile.open(fileName.str());
	// vykonat 100000 operaci aby sme dostali ustalene hodnoty
	myFile << "Operacia" << delimiter << "PocetPrvkov" << delimiter << "TrvanieOperacie" << endl;
	// vykonat 100000 operaci aby sme dostali ustalene hodnoty
	int pocetVykonanychOperaci = 0;
	while (pocetVykonanychOperaci < this->getItemsCount()) {

		iMethod = rand() % 100 + 1;
		cisloNaVlozenie = rand() % 100000 + 1;

		if (inRange(iMethod, 0, 45)) {
			iOperation = rand() % 3 + 1;

			int indexNaVlozenie;

			// get index of array size
			if (static_cast<int>(_list->size()) == 0) {
				indexNaVlozenie = 0;
			}
			else {
				indexNaVlozenie = rand() % static_cast<int>(_list->size() + 1);  // size = 6 -> (0-6)
			}
			// vyber operacie VLOZ(zaciatok,nakoniec, na index -> platny)
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				_list->insert(cisloNaVlozenie, 0);
				break;
			case 2:
				_list->add(cisloNaVlozenie);
				break;
			case 3:
				_list->insert(cisloNaVlozenie, indexNaVlozenie);
			default:
				break;
			}

			auto end = chrono::high_resolution_clock::now();

			// zapis to csv

			myFile << "Vloz" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;

		}
		else if (inRange(iMethod, 45, 90)) {
			// ked mam prazdny zoznam preskocim 
			if (static_cast<int>(_list->size() == 0))
				continue;


			int indexNaVymazanie;
			// get index of array size
			if (static_cast<int>(_list->size()) == 1) {
				indexNaVymazanie = 0;
			}
			else {
				indexNaVymazanie = rand() % (static_cast<int>(_list->size())); // chceme platne indexi, size -> 3 -> 0-2
			}

			iOperation = rand() % 3 + 1;
			// vyber operacie VLOZ(zaciatok,nakoniec, na index -> platny)
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				_list->removeAt(0);
				break;
			case 2:
				_list->removeAt((static_cast<int>(_list->size()) - 1));
				break;
			case 3:
				_list->removeAt(indexNaVymazanie);
			default:
				break;
			}
			auto end = chrono::high_resolution_clock::now();
			myFile << "Vymaz" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
		}
		else if (inRange(iMethod, 90, 95)) {
			if (static_cast<int>(_list->size() == 0))
				continue;
			iOperation = rand() % 2 + 1;
			int prvok;
			int indexNaSpristupnenie;
			// get index of array size
			if (static_cast<int>(_list->size()) == 1) {
				indexNaSpristupnenie = 0;
			}
			else {
				indexNaSpristupnenie = rand() % (static_cast<int>(_list->size()));
			}
			auto start = chrono::high_resolution_clock::now();
			switch (iOperation)
			{
			case 1:
				prvok = _list->operator[](indexNaSpristupnenie);
				break;
			case 2:
				_list->operator[](indexNaSpristupnenie) = cisloNaVlozenie;
				break;
			default:
				break;
			}
			auto end = chrono::high_resolution_clock::now();
			myFile << "DajData/NastavData" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
		}
		else {
			if (static_cast<int>(_list->size() == 0))
				continue;
			auto start = chrono::high_resolution_clock::now();
			int index = _list->getIndexOf(cisloNaVlozenie);
			auto end = chrono::high_resolution_clock::now();
			myFile << "DajIndex" << delimiter << _list->size() << delimiter << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl;
			// zvys o jedna 
			pocetVykonanychOperaci++;
		}
	}
	myFile.close();
}