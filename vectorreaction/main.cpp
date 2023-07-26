#include <iostream>
#include "Vector.cpp"


using namespace std;



int main()
{
     Vector<int> vectortest;
	 vectortest.loadRandomInt(100000000);

	cout << "initial print" << endl;
	vectortest.printAll();
	cout << "print ascending" << endl;
	vectortest.intSortAscending();
	vectortest.printAll();
	cout << "print descending" << endl;
	vectortest.intSortDescending();
	vectortest.printAll();
	cout << "print size" << endl;
	vectortest.printSIZE();



}
