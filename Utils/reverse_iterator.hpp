#ifndef REV_IT
#define REV_IT

#include "utils.hpp"

namespace ft{

	template<class Iter>
	class reverse_iterator
	{


		/*/////////////////////////////
				Member Types
		////////////////////////////*/


	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
		
	private:
		iterator_type baseIter;
	
	public:
		reverse_iterator() : baseIter() {};

		explicit reverse_iterator(iterator_type iter) : baseIter(iter){};

		template<class U>
		reverse_iterator(const reverse_iterator<U> &iter){
			baseIter = iter.base();
		};

		template< class U >
		reverse_iterator& operator=(const reverse_iterator<U> &other){
//			if (this == &other)
//				return *this;
			this->baseIter = other.base();
			return *this;
		}

		iterator_type base() const{
			return baseIter;
		}

		/*
	 		*a , a->m
 		*/

		reference operator*() const{
			iterator_type tmp = baseIter;
			return *--tmp;
		}

		pointer operator->()const{
			return &(operator*());
		}

		/*
			 a[n]
 		*/

		reference operator[](difference_type n) const {
			return base()[-n-1];
		};

		/*
			 ++a, a++
 		*/

		reverse_iterator &operator++(){
			--baseIter;
			return *this;
		}

		reverse_iterator operator++(int){
			reverse_iterator temp = *this;
			--baseIter;
			return temp;
		}

		/*
			--a, a--
		*/

		reverse_iterator &operator--(){
			++baseIter;
			return *this;
		}

		reverse_iterator operator--(int){
			reverse_iterator temp = *this;
			++baseIter;
			return temp;
		}

		/*
			 a + n, a -n
		 */

		reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(base() - n);
		};

		reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(base() + n);
		};

		/*
			 a += n, a -= n
 		*/

		reverse_iterator operator+=(difference_type n)  {
			baseIter -= n;
			return *this;
		};

		reverse_iterator operator-=(difference_type n)  {
			baseIter += n;
			return *this;
		};
	
	};
	template< class Iterator1, class Iterator2 >
		bool operator==( const reverse_iterator<Iterator1>& lhs,
						 const reverse_iterator<Iterator2>& rhs ){
			return (lhs.base() == rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator!=( const reverse_iterator<Iterator1>& lhs,
						 const reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() != rhs.base());
		}

		template< class Iterator1, class Iterator2 >
		bool operator<( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs ){
			return lhs.base() > rhs.base();
		}

		template< class Iterator1, class Iterator2 >
		bool operator<=( const reverse_iterator<Iterator1>& lhs,
						 const reverse_iterator<Iterator2>& rhs ){
			return lhs.base() >= rhs.base();
		}

		template< class Iterator1, class Iterator2 >
		bool operator>( const reverse_iterator<Iterator1>& lhs,
						const reverse_iterator<Iterator2>& rhs ){
			return lhs.base() < rhs.base();
		}

		template< class Iterator1, class Iterator2 >
		bool operator>=( const reverse_iterator<Iterator1>& lhs,
						 const reverse_iterator<Iterator2>& rhs ){
			return lhs.base() <= rhs.base();
		}

		template< class Iter >
		reverse_iterator<Iter>
		operator+( typename reverse_iterator<Iter>::difference_type n,
			  	 	const reverse_iterator<Iter>& it ){
			return reverse_iterator<Iter>(it.base() - n);
		}

		template< class Iterator >
		typename reverse_iterator<Iterator>::difference_type
		operator-( const reverse_iterator<Iterator>& lhs,
			   		const reverse_iterator<Iterator>& rhs ){
			return rhs.base() - lhs.base();
		}
	
}

#endif
