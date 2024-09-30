#include <iostream>

int main()
{
	int a = 10;
	int* p = &a;

	std::cout << "Value of a: " << a << "\n";
	std::cout << "Address of a: " << &a << "\n";
	std::cout << "Pointer p points to: " << p << "\n";
	std::cout << "Value pointed by p: " << *p << " \n";

	int b = 20;
	int* pb = &b;
	*pb = 30;

	std::cout << "New value of b: " << b << "\n ";

	int* dynamicArray = new int[5];
	
	
	std::cout << "Dynamic memory: ";

	for (int i = 0; i < 5; i++)
	{
		std::cout << (dynamicArray[i] = i + 1) << " ";
	}

	delete[] dynamicArray;

}