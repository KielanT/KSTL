export module kArray;
import <iostream>;

namespace KSTL
{
	export template<typename T, size_t N>
	class kArray
	{
	public:
		kArray() = default; // Default constructor
		~kArray() = default; // Default destructor

		kArray(const kArray&) = delete; // Copy constructor
		kArray(kArray&&) = delete; // Move constructor
		kArray& operator=(const kArray&) = delete; // Copy assignment operator
		kArray& operator=(kArray&&) = delete; // Move assignment operator

		void Print()
		{
			for (size_t i = 0; i < N; ++i)
			{
				std::cout << m_Arr[i] << std::endl;
			}
		}

		const size_t Size() const;


		T& operator[](size_t index);
		const T& operator[](size_t index) const;

	private:
		T m_Arr[N];

	};
	template<typename T, size_t N>
	const size_t kArray<T, N>::Size() const
	{
		return N;
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