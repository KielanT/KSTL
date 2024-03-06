export module kVector;

import <stdexcept>;
import <algorithm>;

export namespace KSTL
{

	export template<typename T>
	class kVector
	{
	public:
		kVector(); // Default constructor
		kVector(std::initializer_list<T> list); // Default constructor
		~kVector(); // Default destructor

		kVector(const kVector& inVector); // Copy constructor
		kVector(kVector&&) = delete; // Move constructor
		kVector& operator=(const kVector&) = delete; // Copy assignment operator
		kVector& operator=(kVector&&) = delete; // Move assignment operator

		void Push(const T& data); // Copy
		void Push(T&& data);
		void Pop();
		
		T* begin();
		T* end();

		const size_t Size() const;

		T& operator[](size_t index);

	private:
		T* m_Arr;
		size_t m_Capacity;
		size_t m_Size;

		static constexpr int DEFAULT_CAPACITY = 1;

	};

	template<typename T>
	kVector<T>::kVector()
	{
		m_Arr = { new T[DEFAULT_CAPACITY] };
		m_Capacity = { DEFAULT_CAPACITY };
		m_Size = { 0 };
	}

	template<typename T>
	kVector<T>::kVector(std::initializer_list<T> list)
	{
		m_Arr = { new T[list.size()] };
		m_Capacity = { list.size() };
		m_Size = { list.size() };
		
		std::copy(list.begin(), list.end(), m_Arr);
	}

	template<typename T>
	kVector<T>::~kVector()
	{
		delete[] m_Arr;
	}

	template<typename T>
	kVector<T>::kVector(const kVector& inVector)
	{
		m_Arr = { new T[inVector.Size()] };
		m_Capacity = { inVector.Size() };
		m_Size = { inVector.Size() };

		for (int i = 0; i < m_Size; ++i)
		{
			m_Arr[i] = inVector.m_Arr[i];
		}
	}

	template<typename T>
	void kVector<T>::Push(const T& data)
	{
		if (m_Size == m_Capacity) // Only resize if needed
		{
			m_Capacity *= 2;
			T* temp = { new T[m_Capacity] };

			for (int i = 0; i < m_Size; ++i)
			{
				temp[i] = m_Arr[i];
			}

			delete[] m_Arr;

			m_Arr = temp;
		}

		m_Arr[m_Size] = data;
		m_Size++;
	}

	template<typename T>
	void kVector<T>::Push(T&& data)
	{
		if (m_Size == m_Capacity) // Only resize if needed
		{
			m_Capacity *= 2;
			T* temp = { new T[m_Capacity] };

			for (int i = 0; i < m_Size; ++i)
			{
				temp[i] = m_Arr[i];
			}

			delete[] m_Arr;

			m_Arr = temp;
		}

		m_Arr[m_Size] = std::move(data);
		m_Size++;
	}

	template<typename T>
	void  kVector<T>::Pop()
	{
		m_Size--;
	}

	template<typename T>
	T* kVector<T>::begin()
	{
		return &m_Arr[0];
	}

	template<typename T>
	T* kVector<T>::end()
	{
		// Standard Library end does not point to the last element in the m_Array
		// it has an extra element at the end that gets returned.
		return &m_Arr[m_Size];
	}

	template<typename T>
	const size_t kVector<T>::Size() const
	{
		return m_Size;
	}


	template<typename T>
	T& kVector<T>::operator[](size_t index)
	{
		if (index >= m_Size)
			throw std::out_of_range{ "kVector::operator[]" };
	
		return m_Arr[index];
	}



}
