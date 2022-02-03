#ifndef MAP_HPP
#define MAP_HPP

#include "../Utils/binary_search_tree.hpp"

namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		
		public:
			
		typedef Key										key_type;
		typedef T 										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		
		class value_compare
		{
			protected:
				typedef key_compare comp;

			public:
				bool operator()(const value_type& lhs, const value_type& rhs) const
				{
					return comp()(lhs.first, rhs.first);
				}
		};
		
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		
		
		private:
		
		typedef Tree <T, Key, value_compare, Alloc, value_type> tree;
		
		
		public:
		
		typedef typename tree::iterator						iterator;
		typedef typename tree::const_iterator				const_iterator;
		typedef typename tree::reverse_iterator				reverse_iterator;
		typedef typename tree::const_reverse_iterator		const_reverse_iterator;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;
		typedef std::size_t									size_type;
		
		
		private:
		
		tree _tree;
		allocator_type _alloc;
		key_compare _compare;
		value_compare _value_compare;
		
		
		public:
		
		explicit map (const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()):
		_tree(), _alloc(alloc), _compare(comp), _value_compare(value_compare()) {}
		
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type()):
		_tree(), _alloc(alloc), _compare(comp), _value_compare(value_compare())
		{
			for (;first != last; first++)
				_tree.insert(*first);
		}
		
		map (const map& x)
		{
			*this = x;
		}
		
		map& operator=(const map& other)
		{
			if (this == &other)
				return *this;

			_tree = other._tree;
			_compare = other._compare;
			_alloc = other._alloc;
			_value_compare = other._value_compare;
			return *this;
		}
		
		
		~map(){}
		
		iterator					begin() {return	_tree.begin(); }
		const_iterator 				begin() const {return	_tree.begin(); }
		iterator					end() {return	_tree.end(); }
		const_iterator				end() const {return	_tree.end(); }
		reverse_iterator 			rbegin() {return	_tree.rbegin(); }
		const_reverse_iterator 		rbegin() const {return	_tree.rbegin(); }
		reverse_iterator			rend() {return	_tree.rend(); }
		const_reverse_iterator		rend() const {return	_tree.rend(); }
				
				
		ft::pair<iterator, bool> insert( const value_type& value )
		{
			bool isInserted = _tree.insert(value);
			return ft::make_pair(find(value.first), isInserted);
		}

		template< class InputIt >
		void insert( InputIt first, InputIt last )
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		iterator insert(iterator hint, const value_type& value)
		{
			(void)hint;
			insert(value);
			return find(value.first);
		}
			
		iterator find(const key_type &key)
		{
			return iterator( _tree.find(ft::make_pair(key, mapped_type())), _tree.getRoot());
		}

		const_iterator find(const Key& key ) const
		{
			return const_iterator( _tree.find(ft::make_pair(key, mapped_type())), _tree.getRoot());
		}
		
		size_type count(const Key& key) const
		{
			return find(key) != end();
		}
		
		bool empty() const
		{
			return (size() == 0);
		}

		size_type size() const
		{
			return _tree.getSize();
		}

		size_type max_size() const
		{
			return _tree.max_size();
		}
		
		bool erase(iterator position)
		{
			return(_tree.erase(*position));
		}
		
		bool erase(const Key &key)
		{
			return(_tree.erase(ft::make_pair(key, mapped_type())));
		}

		void erase (iterator first, iterator last)
		{
			for (iterator tmp = first; first != last;)
			{
				tmp = first;
				tmp++;
				_tree.erase(*first);
				first = tmp;
				
			}
		}
		
		mapped_type& operator[](const Key& key)
		{
			insert(ft::make_pair(key, mapped_type()));
			iterator res = find(key);
			return (*res).second;
		}
		
		void clear()
		{
			_tree.rclear(_tree.getRoot());
			_tree.nilRoot();
		}
		
		key_compare key_comp() const
		{
			return key_compare();
		}

		value_compare value_comp() const
		{
			return value_compare();
		}
		
		void swap (map& x)
		{
			_tree.swap(x._tree);
		}
		
		iterator lower_bound(const Key& key)
		{
			return _tree.lower_bound(ft::make_pair(key, mapped_type()));
		}

		const_iterator lower_bound(const Key& key) const
		{
			return _tree.lower_bound(ft::make_pair(key, mapped_type()));
		}

		iterator upper_bound(const Key& key)
		{
			return _tree.upper_bound(ft::make_pair(key, mapped_type()));
		}

		const_iterator upper_bound(const Key& key) const
		{
			return _tree.upper_bound(ft::make_pair(key, mapped_type()));
		}

		ft::pair<iterator, iterator> equal_range(const Key& key)
		{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const
		{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}
		
		allocator_type get_allocator() const
		{
			return _alloc;
		}
	};
}
#endif
