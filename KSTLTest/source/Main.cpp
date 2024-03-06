#include <iostream>
#include <vector>

import kVector;



int main()
{
	KSTL::kVector<int> kV = {0, 1, 2, 3};

	for (auto& i : kV)
	{
		std::cout << i << " ";
	}

	KSTL::kVector<int> kV2 = kV;

	std::cout << std::endl;
	for (auto& i : kV2)
	{
		std::cout << i << " ";
	}

	//******************
	// Standard Below
	//******************
	//std::cout << std::endl;
	//
	//std::vector<int> v = { 0, 1, 2, 3 };
	//std::vector<int> v2 = { v };
	//
	//for (auto& i : v)
	//{
	//	std::cout << i << " ";
	//}
	

}