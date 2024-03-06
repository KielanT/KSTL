export module kVector;

import <stdexcept>;

export namespace KSTL
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
		void Pop();
		
		int* begin();
		int* end();

		int& operator[](int index);

	private:
		int* m_Arr;
		int m_Capacity;
		int m_Size;

		static const int DEFAULT_CAPACITY = 1;

	};

	kVector::kVector()
	{
		m_Arr = { new int[DEFAULT_CAPACITY] };
		m_Capacity = { DEFAULT_CAPACITY };
		m_Size = { 0 };
	}

	kVector::~kVector()
	{
		delete[] m_Arr;
	}

	void kVector::Push(int data)
	{
		if (m_Size == m_Capacity)
		{
			int* temp = { new int[2 * m_Capacity] };

			for (int i = 0; i < m_Capacity; ++i)
			{
				temp[i] = m_Arr[i];
			}

			delete[] m_Arr;
			m_Capacity *= 2;

			m_Arr = temp;
		}

		m_Arr[m_Size] = data;
		m_Size++;


	}

	void kVector::Pop()
	{
		m_Size--;
	}

	int* kVector::begin()
	{
		return &m_Arr[0];
	}

	int* kVector::end()
	{
		// Standard Library end does not point to the last element in the m_Array
		// it has an extra element at the end that gets returned.
		return &m_Arr[m_Size];
	}

	int& kVector::operator[](int index)
	{
		if (index >= m_Size)
			throw std::out_of_range{ "kVector::operator[]" };

		return m_Arr[index];
	}


}
