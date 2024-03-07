#include <array>

import kVector;
import kArray;


int main()
{
	KSTL::kArray<int, 5> a = { 0, 1, 2, 3, 5 };

	for (const auto& elem : a)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;

}