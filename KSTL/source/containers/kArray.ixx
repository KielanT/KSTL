export module kArray;
import <iostream>;

namespace KSTL
{
	export template<typename T, size_t N>
	class kArray
	{
	public:
		kArray() = default; // Default constructor
		kArray(std::initializer_list<T> list);
		~kArray() = default; // Default destructor

		kArray(const kArray&) = delete; // Copy constructor
		kArray(kArray&&) = delete; // Move constructor
		kArray& operator=(const kArray&) = delete; // Copy assignment operator
		kArray& operator=(kArray&&) = delete; // Move assignment operator

		const size_t Size() const;

		void Fill(const T& value);

		T* Data();

		T* begin();
		T* end();

		T& operator[](size_t index);
		const T& operator[](size_t index) const;

	private:
		T m_Arr[N];

	};

	template<typename T, size_t N>
	kArray<T, N>::kArray(std::initializer_list<T> list)
	{
		std::copy(list.begin(), list.end(), m_Arr);
	}

	template<typename T, size_t N>
	const size_t kArray<T, N>::Size() const
	{
		return N;
	}

	template<typename T, size_t N>
	void kArray<T, N>::Fill(const T& value)
	{
		for (auto& element : m_Arr)
		{
			element = value;
		}
	}

	template<typename T, size_t N>
	T* kArray<T, N>::Data()
	{
		return m_Arr;
	}

	template<typename T, size_t N>
	T* kArray<T, N>::begin()
	{
		return Data();
	}

	template<typename T, size_t N>
	T* kArray<T, N>::end()
	{
		return Data() + N;
	}


	template<typename T, size_t N>
	T& kArray<T, N>::operator[](size_t index)
	{
		return m_Arr[index];
	}

	template<typename T, size_t N>
	const T& kArray<T, N>::operator[](size_t index) const
	{
		return m_Arr[index];
	}
}