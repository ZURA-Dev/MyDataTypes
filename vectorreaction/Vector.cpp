
#include <iostream>
#include <typeinfo>
#include <cstdlib>


using namespace std;

// Re-declare template for definitions

template<typename T>
class Vector {
public:
	T* ptr;
	int* SIZE;
	Vector() {
		SIZE = new int(0);
		ptr = new T[*SIZE];
	}
	
	~Vector() {
		delete[] ptr;
		delete SIZE;
	}

	void printSIZE() {
		cout << *SIZE;
	}
	
	size_t sizeByte()
	{
		return sizeof(ptr);
	}

	int size() {
		return *SIZE;
	}

	void add(T value) {
		//there is always going to be a +1 buffer to memory because of object initialization
		int oldSIZE = *SIZE;
		//store ptr into tempptr before deletion and new ptr creation
		T* tempptr = new T[oldSIZE];

		for (int i = 0; i < oldSIZE; i++) {
			tempptr[i] = ptr[i];
		}

		delete[] ptr;//deletes pointer and size

		(*SIZE)++;
		ptr = new T[*SIZE];
		int newSIZE = *SIZE;

		for (int i = 0; i < newSIZE; i++) {
			ptr[i] = tempptr[i];
		}
		ptr[*SIZE - 1] = value;
		delete[] tempptr;
	}
	
	void removeEnd() {
		int oldSIZE = *SIZE;
		T* tempptr = new T[oldSIZE];
		for (int i = 0; i < oldSIZE - 1; i++) {
			tempptr[i] = ptr[i];
		}
		(*SIZE)--;
		delete[] ptr;
		ptr = new T[*SIZE];

		for (int i = 0; i < *SIZE; i++) {
			ptr[i] = tempptr[i];
		}
		delete[] tempptr;
	}
	
	void removeBeginning() {
		int oldSIZE = *SIZE;
		T temparray = new T[oldSIZE];
		for (int i = 0; i < oldSIZE; i++) {
			temparray[i] = ptr[i];
		}
		delete[] ptr;
		(*SIZE)--;
		ptr = new T[*SIZE];
		for (int i = 0; i < oldSIZE; i++) {
			ptr[i] = temparray[i + 1];
		}
		delete[] temparray;
	}
	
	void replaceBeginning(T value)
	{

		T temparray = new T[*SIZE];
		for (int i = 0; i < *SIZE; i++) {
			temparray[i] = ptr[i];
		}
		delete[] ptr;
		ptr = new T[*SIZE];
		for (int i = 0; i < *SIZE; i++) {
			if (i == 0) {
				ptr[i] = value;
			}
			else {
				ptr[i] = temparray[i];
			}
		}
		delete[] temparray;
	}

	T getIndex(T value)
	{
		//catch out of bounds
		if (value > *SIZE - 1 || value < 0) {
			cout << "error out of bounds";
			return 0;
		}
		else {
			return ptr[value];
		}
	}
	
	void begin() {
		int* start = ptr;
		ptr = start; //moves pointer back to beginning

	}
	
	void end()
	{
		//idk if i should do -1 or just keep it like this because of the buffer.
		int* end = &ptr[*SIZE - 1];
		ptr = end;

	}
	
	void intSortAscending()
	{
		//smallest to largest, also checking type, if none int thro1w error

		for (int i = 0; i < *SIZE; i++)
		{
			for (int j = 0; j < *SIZE - 1; j++)
			{
				if (ptr[j] > ptr[j + 1]) {
					swap(ptr[j], ptr[j + 1]);
				}
			}
		}
	}
	
	void intSortDescending()
	{
		//smallest to largest, also checking type, if none int thro1w error

		for (int i = 0; i < *SIZE; i++)
		{
			for (int j = 0; j < *SIZE - 1; j++)
			{
				if (ptr[j] < ptr[j + 1]) {
					swap(ptr[j], ptr[j + 1]);
				}
			}
		}
	}
	
	void printAll()
	{
		for (int i = 0; i < *SIZE; i++)
		{
			cout << ptr[i] << endl;
		}
	}
	
	void replaceIndex()
	{

	}
	
	bool empty()
	{
		//returns bool
		bool check = (*SIZE == 0) ? true : false;
		return check;
	}
	void loadRandomInt(int value) 
	{
	//load with random numbers
	srand(time(0));
	for (int i = 0; i < value; i++)
	{
		int randomNum = rand() % 100;
		add(randomNum);
	}
	}
};


