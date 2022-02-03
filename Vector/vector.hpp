#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <stdexcept>
#include "../Utils/random_access_iterator.hpp"
#include "../Utils/reverse_iterator.hpp"
#include "../Utils/utils.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class Vector
	{
		//public member types//
		public:
			typedef	T					value_type;
			typedef	Allocator			allocator_type;
			typedef	std::size_t			size_type;
			typedef	std::ptrdiff_t		difference_type;
			typedef	value_type&			reference;
			typedef	const value_type&	const_reference;
			typedef typename Allocator::value_type
										pointer;
			typedef typename Allocator::const_pointer
										const_pointer;
			typedef	ft::random_access_iterator<value_type>
										iterator;
			typedef	ft::random_access_iterator<const value_type>
										const_iterator;
			typedef	ft::reverse_iterator<iterator>
											reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>
											const_reverse_iterator;
		
		//private member types//
		private:
			value_type*		_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
		
		//constructors//
		public:
		//default
		explicit Vector (const allocator_type& alloc= allocator_type()):
		_data(NULL), _size(0), _capacity(0), _alloc(alloc){}
		
		//fill
		explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc= allocator_type()):
		_size(n), _capacity(n), _alloc(alloc)
		{
			_data = _alloc.allocate(n);
			for (int i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
			
		}
		
		//range
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc= allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0):
		_size(last - first),
		_capacity(last - first),
		_alloc(alloc)
		{
			_data = _alloc.allocate(_size);
			int i = 0;
			for (; first != last;)
			{
				_alloc.construct(_data + i, *first);
				first++;
				i++;
			}
		}
		
		allocator_type get_allocator() const
		{
			return _alloc;
		}
		
		//copy
		Vector (const Vector& x):
		_size(x.size()), _capacity(x.size()), _alloc(x.get_allocator())
		{
			_data = _alloc.allocate(_capacity);
			for (int i = 0; i < _size;)
			{
				_alloc.construct(_data + i, x[i]);
				i++;
			}
		}
		
		Vector& operator=(const Vector& other)
		{
			if (this == &other)
				return *this;
			_alloc.deallocate(_data, _capacity);
			
			_size = other.size();
			_capacity = other.capacity();
			_alloc = other.get_allocator();
			_data = _alloc.allocate(_size);
			for (int i = 0; i < _size;)
			{
				_alloc.construct(_data + i, other[i]);
				i++;
			}
			return (*this);
		}
		
		//destructor
		~Vector()
		{
			_alloc.deallocate(_data, _capacity);
		}
		
		// MEMBER FUNCTIONS
		//Iterators
		
		
		//operators
		
		reference operator[]( size_type pos )
		{
			return _data[pos];
		}

		const_reference operator[]( size_type pos ) const
		{
			return _data[pos];
		}
		
		iterator begin() { return iterator(_data); }
		iterator end() { return iterator(_data + _size); }

		const_iterator begin() const { return const_iterator(_data); }
		const_iterator end() const{ return const_iterator(_data + _size); }

		reverse_iterator rbegin()  { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend() const{ return const_reverse_iterator(begin()); }
		
		//Capacity
		size_type size() const
		{
			return (_size);
		}
		
		size_type capacity() const
		{
			return (_capacity);
		}
		
		size_type max_size() const{
			return _alloc.max_size();
		}
		
		bool empty() const
		{
			if (_size == 0)
				return true;
			return false;
		}
		
		reference at (size_type n)
		{
			std::string what;
			std::stringstream out;
			std::stringstream out2;
			out << n;
			out2 << _size;
			what = "vector::_M_range_check: __n (which is " + out.str() + ") >= this->size() (which is " + out2.str() + ")";
			if (n < _size)
				return _data[n];
			throw std::out_of_range(what);
		}
		
		const_reference at (size_type n) const
		{
			std::string what;
			std::stringstream out;
			std::stringstream out2;
			out << n;
			out2 << _size;
			what = "vector::_M_range_check: __n (which is " + out.str() + ") >= this->size() (which is " + out2.str() + ")";
			if (n < _size)
				return _data[n];
			throw std::out_of_range(what);
		}
		
		reference front()
		{
			return _data[0];
		}
		
		const_reference front() const
		{
			return _data[0];
		}
		
		
		reference back()
		{
			return _data[_size - 1];
		}
		
		const_reference back() const
		{
			return _data[_size - 1];
		}
		
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = 0)
		{
			clear();
			if (last - first > _capacity)
			{
				_alloc.deallocate(_data, _capacity);
				_capacity = last - first;
				_data = _alloc.allocate(_capacity);
			}
			_size = last - first;
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(_data + i, *first);
				first++;
			}
			
		}

		void assign (size_type n, const value_type& val)
		{
			clear();
			if (n > _capacity)
			{
				_alloc.deallocate(_data, _capacity);
				_data = _alloc.allocate(n);
				_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_data + i, val);
			_size = n;
		}
		
		void clear()
		{
			while(_size)
				pop_back();
		}
		
		void pop_back()
		{
			_alloc.destroy(_data + _size - 1);
			_size--;
		}
		
		void push_back (const value_type& val)
		{
			if (_size == _capacity) {
				_capacity = (_capacity == 0) ? (_capacity + 1) : (_capacity * 2);
				reserve(_capacity);
			}
			_alloc.construct(_data + _size, val);
			_size++;
		}
		
		iterator erase (iterator position)
		{
			size_type index = position - begin();
			_alloc.destroy(_data + index);

			for (size_type i = index; i < _size - 1; i++)
				_alloc.construct(_data + i, _data[i + 1]);

			_size--;
			return iterator(_data + index);
		}
		
		void swap(Vector &x)
		{
			std::swap(_data, x._data);
			std::swap(_size, x._size);
			std::swap(_capacity, x._capacity);
			std::swap(_alloc, x._alloc);
		}
		
		iterator erase (iterator first, iterator last)
		{
			iterator temp = first;
			
			for (;temp < last; temp++)
				_alloc.destroy(&(*temp));
			
			int i = 0;
			temp = last;
			for (;temp < end(); temp++)
			{
				_alloc.construct(&(*(first + i)), *(last + i));
				i++;
			}
			_size -= last - first;
			return iterator(first);
		}
		
		iterator insert(iterator pos, const T& value)
		{
			size_type index = pos - begin();

			if (_size == _capacity)
			{
				size_type new_cap = (_capacity == 0) ? _capacity + 1 : _capacity * 2;
				value_type *newAlloc = _alloc.allocate(new_cap);
				for (size_type i = 0; i < (_size - index); i++)
					_alloc.construct(newAlloc + i, _data[i]);

				_alloc.construct(newAlloc + index, value);

				for (size_type i = index + 1; i <= _size; i++)
					_alloc.construct(newAlloc + i, _data[i - 1]);

				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_data[i]);


				_alloc.deallocate(_data, _capacity);

				_data = newAlloc;
				_capacity = new_cap;
			}
			else
			{
				for (size_type i = _size; i > index; i--)
				{
					_alloc.destroy(_data + i);
					_alloc.construct(_data + i, *(_data + i -1));
				}
				_alloc.destroy(_data + index);
				_alloc.construct(_data + index, value);
			}

			_size++;
			return begin() + index;
		}


		void insert (iterator position, size_type n, const value_type& val)
		{	
			size_type index_take = position - begin();
			size_type _old_capcity = _capacity;
			value_type* _temp_data;
			if (n > _capacity - _size)
			{
				if (_size + n > _size * 2)
				{
					_temp_data = _alloc.allocate(n + _size);
					_capacity = n + _size;
				}
				else if (_size + n <= _size * 2)
				{
					_temp_data = _alloc.allocate(_size * 2);
					_capacity = _size * 2;
				}
			}
			else
				_temp_data = _alloc.allocate(_capacity);
			size_type i = 0;
			
			
			for (; i < index_take; i++)
				_alloc.construct(_temp_data + i, _data[i]);
			
			
			for (; i < n + index_take; i++)
				_alloc.construct(_temp_data + i, val);
			
			
			for (; i < _size + n; i++)
				_alloc.construct(_temp_data + i, _data[i - n]);
			
			
			_alloc.deallocate(_data, _old_capcity);
			_data = _temp_data;
			
			_size += n;
		}

		template< class InputIt >
		void insert(iterator pos, InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = NULL)
			{

			size_type index = pos - begin();
			size_type count = last - first;

			value_type *newAlloc;
			size_type new_cap = (_capacity * 2 >= _size + count) ? _capacity * 2 : _size + count;

			try
			{
				if (_size + count > _capacity) {
					newAlloc = _alloc.allocate(new_cap);

					for (size_type i = 0; i < (_size - index); i++)
						_alloc.construct(newAlloc + i, _data[i]);

					for (size_type i = 0; i < count; i++) {
						_alloc.construct(newAlloc + index + i, *(first));
						first++;
					}
					for (size_type i = index; i < _size; i++)
						_alloc.construct(newAlloc + i + count, _data[i]);

					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_data + i);
					if (_data)
						_alloc.deallocate(_data, _capacity);

					_data = newAlloc;
					_capacity = new_cap;
				}
				else
				{
					for (size_type i = _size; i > index; i--)
					{
						_alloc.destroy(_data + i + count - 1);
						_alloc.construct(_data + i + count - 1, _data[i - 1]);
					}
					for (size_type i = index; i < index + count; i++) {
						_alloc.destroy(_data + i);
						_alloc.construct(_data + i, *first);
						first++;
					}
				}
				_size += count;
			}
			catch(...)
			{
				for(size_type i = 0; i < count; i++)
					_alloc.destroy(newAlloc + i +index);
				_alloc.deallocate(newAlloc, new_cap);
				throw;
			}

		}

		
		void reserve (size_type n)
		{
			if (n < _capacity)
				return;
			
			if (n > max_size())
				throw std::length_error("vector::reserve");
			
			value_type* _temp_data = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(_temp_data + i, _data[i]);
				_alloc.destroy(_data + i);
			}
			if (_data)
				_alloc.deallocate(_data, _capacity);
			_capacity = n;
			_data = _temp_data;	
		}

		
		void resize (size_type n, value_type val = value_type())
		{
			if (n < _size)
			{
				for (int i = _size; i >= n; i--)
					_alloc.destroy(_data + i);
			}
			else if (n > _size)
			{
				if (n > _capacity && n > _size * 2)
					reserve(n);
				else if (n > _capacity && n <= _size * 2)
					reserve(_size * 2);
				for (size_type i = _size; i < n; i++)
					_alloc.construct(_data + i, val);
			}
			_size = n;
		}
		
	};
	
	template < class T, class Alloc >
	bool operator==( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs ){

		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template < class T, class Alloc >
	bool operator!=( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs ){

		return !(lhs == rhs);
	}

	template < class T, class Alloc >
	bool operator<( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs ){

		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template < class T, class Alloc >
	bool operator>( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs ){

		return rhs < lhs;
	}

	template < class T, class Alloc >
	bool operator<=( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs ){

		return !(lhs > rhs);
	}

	template < class T, class Alloc >
	bool operator>=( const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs ){

		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y){
		x.swap(y);
	}
}

#endif
