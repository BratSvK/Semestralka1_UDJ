#pragma once
#include "AbstractTester.h";
#include "structures/list/list.h";

using namespace structures;

class PriorityQueue : public AbstractTester {

public:
	PriorityQueue(List<int>* list, int itemsCount, char scenario);

	~PriorityQueue();

	void test();

private:
	// implementacia listu pre testy vseobecne
	List<int>* _list;
};

PriorityQueue::PriorityQueue(List<int>* list, int itemsCount, char scenario) : AbstractTester(itemsCount, scenario) {
	_list = list;
}

PriorityQueue::~PriorityQueue() {
	delete _list;
}

void PriorityQueue::test() {

}