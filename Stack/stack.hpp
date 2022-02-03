#ifndef STACK_HPP
#define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class stack
	{
		public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		//typedef typename Container::reference		reference; // std11
		//typedef typename Container::const_reference	const_reference; // std11
		
		protected:
		container_type c;
		
		public:
		explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
		
		stack &operator=(const stack &other)
		{
			if (this != &other)
				c = other.c;
			return (*this);
		}

		~stack(){}
		
		bool empty() const
		{
			return (c.empty());
		}
		
		size_type size() const
		{
			return (c.size());
		}
		
		value_type& top()
		{
			return (*(c.end() - 1));
		}
		
		const value_type& top() const
		{
			return (*(c.end() - 1));
		}
		
		void push (const value_type& val)
		{
			c.push_back(val);
		}
		
		void pop ()
		{
			c.pop_back();
		}

		template <class U, class Cont>
		friend bool operator== (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);
		
		template <class U, class Cont>
		friend bool operator> (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);
		
		template <class U, class Cont>
		friend bool operator< (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);
		
	};
	
	template <class U, class Cont>
	bool operator== (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	
	template <class U, class Cont>
	bool operator!= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs)
	{
		return !(lhs == rhs);
	}
	
	template <class U, class Cont>
	bool operator<(const stack<U,Cont>& lhs, const stack<U,Cont>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	
	template <class U, class Cont>
	bool operator<= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs)
	{
		return !(lhs > rhs);
	}
	
	template <class U, class Cont>
	bool operator>(const stack<U,Cont>& lhs, const stack<U,Cont>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	
	template <class U, class Cont>
	bool operator>= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs)
	{
		return !(lhs < rhs);
	}
	
}

#endif
