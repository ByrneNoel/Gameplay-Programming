#include <iostream>

void edit_Array(int *t_arr, int t_size);

int main1()
{
	int a = 5;
	int* b =& a;

	*b += 5;

	std::cout << "int a is: " << a << "\n";
	std::cout << "pointer b is: " << * b << "\n";

	// Dynmaic memory allocation
	int* dynamic = new int;
	*dynamic = 15;

	std::cout << "pointer dynamic is: " << * dynamic << "\n";

	// Deallocate memory
	delete dynamic;

	// Implement + test pointers arithmetic
	int array[] = { 1, 2, 3, 4, 5 };
	int* ptr = array;  // Pointer to the first element of the array

	std::cout << "Array elements using pointer arithmetic:";

	for (int i = 0; i < 5; i++) 
	{
		std::cout << *(ptr + i  ) << " ";  // Access elements using pointer arithmetic
		
	}

	std::cout << std::endl;

	// Pointers to manipulate arrays and functions
	int size = 5;
	int arr[] = { 1,2,3,4,5 };

	std::cout << "Normal array: ";

	// Before function
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	edit_Array(arr, size);

	std::cout << "Modified array using pointer + function: ";

	//After function
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}


	return 1;
}

void edit_Array(int* t_arr, int t_size)
{
	for (int i = 0; i < t_size; i++)
	{
		t_arr[i] *= 2;
	}
}

