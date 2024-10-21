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

	std::cout << "New value of b: " << b << "\n";

	int* dynamicArray = new int[5]();	// needs to be initialized
	
	
	std::cout << "Dynamic memory: ";

	for (int i = 0; i < 5; i++)
	{
		dynamicArray[i] = i + 1;	// also needs to be initialized
		std::cout << dynamicArray[i] << " ";
	}

	delete[] dynamicArray;

	std::cout << std::endl;

	int arr[3] = { 10,20,30 };
	int* pArr = arr;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Element " << i << " is: " << *(pArr + i) << "\n";
	}

	int x = 5;
	int* px = &x;

	std::cout << "Address of x: " << px << "\n";
	std::cout << "Value of x: " << *px << "\n";



	return 0;


}