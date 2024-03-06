#include <iostream>
#include <vector>

import kVector;
import kArray;


int main()
{
	KSTL::kArray<int, 5> a;



	a.Print();

	for (size_t i = 0; i < a.Size(); ++i)
	{
		a[i] = i;
		std::cout << a[i] << " ";
	}
}