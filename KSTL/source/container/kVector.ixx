export module kVector;

import <iostream>;

namespace KSTL
{

	export class kVector
	{
	public:
		kVector(); // Default constructor
		~kVector(); // Default destructor

		kVector(const kVector&) = delete; // Copy constructor
		kVector(kVector&&) = delete; // Move constructor
		kVector& operator=(const kVector&) = delete; // Copy assignment operator
		kVector& operator=(kVector&&) = delete; // Move assignment operator

		void Push(int data);

	private:
		int* arr;
		int capacity;
		int current;

		const int DEFAULT_CAPACITY = 1;
	};

	kVector::kVector()
	{
		arr = { new int[DEFAULT_CAPACITY] };
		capacity = { DEFAULT_CAPACITY };
		current = { 0 };
	}

	kVector::~kVector()
	{
		delete[] arr;
	}

	void kVector::Push(int data)
	{
		if (current == capacity)
		{
			int* temp = { new int[2 * capacity] };

			for (int i = 0; i < capacity; ++i)
			{
				temp[i] = arr[i];
			}

			delete[] arr;
			capacity *= 2;

			arr = temp;
		}

		arr[current] = data;
		current++;


	}
}