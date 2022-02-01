#include <iterator>

namespace ft
{
	template <class T>
	class random_access_iterator
	{
		public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		typedef std::random_access_iterator_tag		iterator_category;
		
		private:
		pointer ptr;
		
		public:
		random_access_iterator() : ptr(0) {};
		random_access_iterator(pointer a) : ptr(a) {};
		~random_access_iterator() {};
		random_access_iterator(const random_access_iterator &rai) {*this = rai;}
		random_access_iterator &operator=(const random_access_iterator &rai)
		{
			if (this == &rai)
				return (*this);
			this->ptr = rai.base();
				return (*this);
		}
		
		// Const conversion
		operator random_access_iterator <const value_type> () const {
			return random_access_iterator<const value_type>(ptr);
		}
		
		pointer base() const { return ptr; }
		
		// *a = t
		
		
		//*a a->m
		pointer operator->() const { return ptr; }

		reference operator*() const { return *ptr; }
		
		//--a a--
		random_access_iterator &operator--()
		{
			ptr--;
			return (*this);
		}
		
		random_access_iterator operator--(int)
		{
			random_access_iterator temp = *this;
			ptr--;
			return (temp);
		}
		
		//++a a++
		random_access_iterator &operator++()
		{
			ptr++;
			return (*this);
		}
		
		random_access_iterator operator++(int)
		{
			random_access_iterator temp = *this;
			ptr++;
			return (temp);
		}
		
		// a + n a - n a - b a + b
		
		random_access_iterator operator+ (difference_type n) const
		{
			return (ptr + n);
		}
		
		random_access_iterator operator- (difference_type n) const
		{
			return (ptr - n);
		}
		
		difference_type operator+ (const random_access_iterator &rai)
		{
			return (ptr + rai.base());
		}
		
		difference_type operator- (const random_access_iterator &rai)
		{
			return (ptr - rai.base());
		}
		
		// a += n a -= n
		random_access_iterator operator+=(difference_type n)  {
			ptr += n;
			return *this;
		};
		
		random_access_iterator operator-=(difference_type n)  {
			ptr -= n;
			return *this;
		};
		
		// a[n]
		reference operator[](difference_type n) const {
			return ptr[n];
		};
	};
	
	template<class T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n,
										const random_access_iterator<T> &rhs){
	return (rhs + n);
	}
	
	template <class T>
	bool operator<(ft::random_access_iterator<T> const &lrai,
	ft::random_access_iterator <T> const &rrai)
	{
		return (lrai.base() < rrai.base());
	}
	
	template <class T>
	bool operator<=(ft::random_access_iterator<T> const &lrai,
	ft::random_access_iterator <T> const &rrai)
	{
		return (lrai.base() <= rrai.base());
	}
	
	template <class T>
	bool operator>(ft::random_access_iterator<T> const &lrai,
	ft::random_access_iterator <T> const &rrai)
	{
		return (lrai.base() > rrai.base());
	}
	
	template <class T>
	bool operator>=(ft::random_access_iterator<T> const &lrai,
	ft::random_access_iterator <T> const &rrai)
	{
		return (lrai.base() >= rrai.base());
	}
	
	template<class Iterator1, class Iterator2>
		bool operator!=(ft::random_access_iterator<Iterator1> const &lhs,
						ft::random_access_iterator<Iterator2> const &rhs){
			return (lhs.base() != rhs.base());
		}
	
	template <class T>
	bool operator==(ft::random_access_iterator<T> const &lrai,
	ft::random_access_iterator <T> const &rrai)
	{
		return (lrai.base() == rrai.base());
	}
}
