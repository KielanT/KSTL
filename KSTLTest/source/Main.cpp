#include <iostream>
#include <vector>

import kVector;



int main()
{
	KSTL::kVector<std::string> kV;
	kV.Push("true");
	kV.Push("true");
	kV.Push("true");
	kV.Push("false");

	kV.Pop();

	for (auto& i : kV)
	{
		std::cout << i << " ";
	}

	//std::cout << "indexed: " << kV[2] << std::endl;


	//******************
	// Standard Below
	//******************

	//std::vector<int> v;
	/*v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	auto b = v[5];*/

	////for (auto& i : v)
	////{
	////	std::cout << i << " ";
	////}
	//
	////std::cout << "indexed: " << v[0] << std::endl;
	//
	//std::cout << std::endl;

}