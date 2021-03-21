#pragma once
// abstract class with virtual fnc
class AbstractTester {
public:
	// pure virtual fnc
	virtual void test() = 0;
	// contructor of class
	AbstractTester(int itemsCount, char scenario);

	char getScenario();
	int getItemsCount();

private:
	// definicia poctu operaci nad testom
	int _itemsCount;
	// ktory scenar si zavolame
	char _scenario;

};


AbstractTester::AbstractTester(int itemsCount, char scenario) {
		_itemsCount = itemsCount;
		_scenario = scenario;
}

char AbstractTester::getScenario() {
	return _scenario;
}
int AbstractTester::getItemsCount() {
	return _itemsCount;
}
