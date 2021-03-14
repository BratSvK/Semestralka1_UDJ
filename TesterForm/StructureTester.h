#pragma once
#include "ListTester.h";
#include "structures/list/array_list.h"

using namespace structures;
/// <summary>
/// Toto je hlavna spustacia trieda testu
/// </summary>

class StructureTester {

public:
	// zavola test na Zoznam
	void testList();		
	// zavola test na prirityQueue
	void testPriorityQueue();
};


void StructureTester::testList() {
	// tu sa vytvori instancia Testeru na zoznam 
	ListTester* testList = new ListTester(new ArrayList<int>(), 100, 'A');
	testList->test();


	delete testList;
}
void StructureTester::testPriorityQueue() {
	// tu sa vytvori instancia Testeru na pririty queue 

}



