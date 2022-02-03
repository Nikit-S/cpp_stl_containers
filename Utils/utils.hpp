#ifndef UTILS_HPP
#define UTILS_HPP

#include <iterator>

namespace ft
{
	
		/*/////////////////////////////
				Iterator traits
		////////////////////////////*/
		
	template <class Iterator> class iterator_traits
	{
		public:
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T> class iterator_traits<T*>
	{
		public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T> class iterator_traits<const T*>
	{
		public:
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};



		/*/////////////////////////////
				enable_if
		////////////////////////////*/
		
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T>
	{
		typedef T type;
	};
	
	
	
		/*/////////////////////////////
				 is_integral
		////////////////////////////*/
		
	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator T() const { return v; }
	};
	
	typedef integral_constant<bool, true>   true_type;
	typedef integral_constant<bool, false>  false_type;

	template <class T>	struct is_integral						: public false_type {};
	template <>			struct is_integral<bool>				: public true_type {};
	template <>			struct is_integral<char>				: public true_type {};
	template <>			struct is_integral<char16_t>			: public true_type {};
	template <>			struct is_integral<char32_t>			: public true_type {};
	template <>			struct is_integral<wchar_t>				: public true_type {};
	template <>			struct is_integral<signed char>			: public true_type {};
	template <>			struct is_integral<short int>			: public true_type {};
	template <>			struct is_integral<int>					: public true_type {};
	template <>			struct is_integral<long int>			: public true_type {};
	template <>			struct is_integral<long long int>		: public true_type {};
	template <>			struct is_integral<unsigned char>		: public true_type {};
	template <>			struct is_integral<unsigned short int>	: public true_type {};
	template <>			struct is_integral<unsigned int>		: public true_type {};
	template <>			struct is_integral<unsigned long int>	: public true_type {};
	template <>			struct is_integral<unsigned long long int> : public true_type {};
	
	
	
		/*/////////////////////////////
				 equal
		////////////////////////////*/
		
	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1   last1, InputIterator2 first2 ) {
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
	
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal ( InputIterator1 first1, InputIterator1   last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}



		/*/////////////////////////////
			lexicographical_compare
		////////////////////////////*/
		
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1,										InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 <* first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}
	
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1,
								InputIterator1 last1,
								InputIterator2 first2,
								InputIterator2 last2,
								Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first2, *first1))
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}


		/*/////////////////////////////
					pair
		////////////////////////////*/

	template< class T1, class T2>
	struct pair{

		typedef	T1		first_type;
		typedef	T2		second_type;

		pair() : first(first_type()), second(second_type())
	{
		}

		pair(const T1& x, const T2& y) : first(x), second(y)
	{
		}

		template< class U1, class U2 >
		pair(const pair<U1, U2>& p): first(p.first), second(p.second)
	{
		}

		pair& operator=(const pair& other)
	{
			if (this == &other)
				return *this;
			this->first = other.first;
			this->second = other.second;
			return *this;
		}

		first_type first;
		second_type second;

	};

	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair(T1 t, T2 u)
	{
		return pair<T1, T2>(t, u);
	}

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}
}

#endif
