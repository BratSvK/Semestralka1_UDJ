#pragma once
#include "ListTester.h";
#include "structures/list/array_list.h"
#include "structures/list/linked_list.h"

using namespace structures;
/// <summary>
/// Toto je hlavna spustacia trieda testu
/// </summary>

class StructureTester {

public:
	// zavola test na Zoznam
	void testList(bool isAds, char ScenarList);		
	// zavola test na prirityQueue
	void testPriorityQueue();
};


void StructureTester::testList(bool isAds, char scenar) {
	// tu sa vytvori instancia Testeru na zoznam 
	ListTester* testList;
	int pocetOperaci = 100000;
	if (isAds){
		testList = new ListTester(new ArrayList<int>(), pocetOperaci,scenar);
	}
	else {
		testList = new ListTester(new LinkedList<int>(), pocetOperaci,scenar);
	}
	
	testList->test();


	delete testList;
}
void StructureTester::testPriorityQueue() {
	// tu sa vytvori instancia Testeru na pririty queue 

}



