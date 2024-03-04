#include <iostream>
#include <vector>

import kVector;



int main()
{
	KSTL::kVector kV;
	kV.Push(1);
	kV.Push(2);
	kV.Push(3);
	kV.Push(4);

	//kV.Print();

	for (auto& i : kV)
	{
		std::cout << i << " ";
	}

	//std::cout << "indexed: " << kV[2] << std::endl;


	//******************
	// Standard Below
	//******************

	//std::vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//

	////for (auto& i : v)
	////{
	////	std::cout << i << " ";
	////}
	//
	////std::cout << "indexed: " << v[0] << std::endl;
	//
	//std::cout << std::endl;

}