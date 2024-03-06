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
	
	KSTL::kVector<int> kV2 = { 0, 1, 2, 3 };

	
	std::cout << std::endl;
	for (auto& i : kV2)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	if (kV == kV2)
	{
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;
	}

	//******************
	// Standard Below
	//******************
	//std::cout << std::endl;
	
	//std::vector<int> v = { 0, 1, 2, 3 };
	//std::vector<int> v2;
	//v2 = v;
	//
	//for (auto& i : v)
	//{
	//	std::cout << i << " ";
	//}
	//std::cout << std::endl;
	//
	//for (auto& i : v2)
	//{
	//	std::cout << i << " ";
	//}
	

}