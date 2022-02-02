#ifndef SET_HPP
#define SET_HPP

#include "../Utils/binary_search_tree.hpp"

namespace ft{
	template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class Set{


			/* * * * * * * * * * * * * * *
			* 		MEMBER TYPES
			* * * * * * * * * * * * * * */


	public:
		typedef Key									key_type;
		typedef Key									value_type;
		typedef std::size_t 						size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef Compare								key_compare;
		typedef Compare								value_compare;
		typedef Allocator							allocator_type;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;

	private:
		typedef Tree<value_type, key_type, key_compare, allocator_type, value_type> Tree;

	public:
		typedef typename Tree::iterator 				iterator;
		typedef typename Tree::const_iterator			const_iterator;
		typedef typename Tree::reverse_iterator			reverse_iterator;
		typedef typename Tree::const_reverse_iterator	const_reverse_iterator;

	private:
		Tree		 		_tree;
		allocator_type		_alloc;
		key_compare			_compare;


			/* * * * * * * * * * * * * * * * *
			* 	Constructors & Other Methods
			* * * * * * * * * * * * * * * * */


	public:

		explicit Set(const Compare& comp = key_compare(), const Allocator& alloc = Allocator())
		: _tree(), _alloc(alloc), _compare(comp){

		}

		template< class InputIt >
		Set(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()){
			_alloc = alloc;
			_compare = comp;
			while (first != last) {
				_tree.insert(*first);
				first++;
			}
		}

		Set(const Set& other){
			*this = other;
		}

		~Set(){}

		Set& operator=(const Set& other){
			if (this == &other)
				return *this;

			_tree = other._tree;
			_compare = other._compare;
			_alloc = other._alloc;
			return *this;
		}

		allocator_type get_allocator() const{
			return _alloc;
		}


			/* * * * * * * * * * * * * * * * *
			* 		     Iterators
			* * * * * * * * * * * * * * * * */


		iterator					begin() {return	_tree.begin(); }
		const_iterator 				begin() const {return	_tree.begin(); }
		iterator					end() {return	_tree.end(); }
		const_iterator				end() const {return	_tree.end(); }
		reverse_iterator 			rbegin() {return	_tree.rbegin(); }
		const_reverse_iterator 		rbegin() const {return	_tree.rbegin(); }
		reverse_iterator			rend() {return	_tree.rend(); }
		const_reverse_iterator		rend() const {return	_tree.rend(); }


			/* * * * * * * * * * * * * * * * *
			* 		     Capacity
			* * * * * * * * * * * * * * * * */


		bool empty() const{
			return (size() == 0);
		}

		size_type size() const{
			return _tree.getSize();
		}

		size_type max_size() const{
			return _tree.max_size();
		}


			/* * * * * * * * * * * * * * * * *
			* 		     Modifiers
			* * * * * * * * * * * * * * * * */


		void clear(){
			_tree.rclear(_tree.getRoot());
		}

		ft::pair<iterator, bool> insert(const value_type& value){
			bool isInserted = _tree.insert(value);
			return ft::make_pair(find(value), isInserted);
		}

		iterator insert(iterator hint, const value_type& value){
			(void)hint;
			insert(value);
			return find(value);
		}

		template< class InputIt >
		void insert(InputIt first, InputIt last){
			while (first != last){
				insert(*first);
				first++;
			}
		}

		void erase(iterator pos){
			erase(*pos);
		}

		void erase(iterator first, iterator last ){
			while(first != last){
				first = find(*first);
				erase(*(first++));
			}
		}

		size_type erase(const Key& key){
			return _tree.erase(key);
		}

		void swap(Set& other){
			_tree.swap(other._tree);
		}


			/* * * * * * * * * * * * * * * * *
			* 		     Lookup
			* * * * * * * * * * * * * * * * */


		size_type count( const Key& key ) const{
			return (find(key) != end());
		}

		iterator find(const Key& key){
			return iterator(_tree.find(key), _tree.getRoot());
		}

		const_iterator find( const Key& key ) const{
			return const_iterator(_tree.find(key), _tree.getRoot());
		}

		iterator lower_bound(const Key& key){
			return _tree.lower_bound(key);
		}

		const_iterator lower_bound(const Key& key) const{
			return _tree.lower_bound(key);
		}

		iterator upper_bound(const Key& key){
			return _tree.upper_bound(key);
		}

		const_iterator upper_bound(const Key& key) const{
			return _tree.upper_bound(key);
		}

		ft::pair<iterator,iterator> equal_range(const Key& key){
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator,const_iterator> equal_range(const Key& key) const{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}


			/* * * * * * * * * * * * * * * * *
			* 		     Observers
			* * * * * * * * * * * * * * * * */


		key_compare key_comp() const{
			return key_compare();
		}

		value_compare value_comp() const{
			return key_compare();
		}
	};


			/* * * * * * * * * * * * * * * * *
			* 		Non Member Functions
			* * * * * * * * * * * * * * * * */

		template< class Key, class Compare, class Alloc >
		bool operator==(const ft::Set<Key,Compare,Alloc>& lhs, const ft::Set<Key,Compare,Alloc>& rhs ){
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template< class Key, class Compare, class Alloc >
		bool operator!=(const ft::Set<Key,Compare,Alloc>& lhs, const ft::Set<Key,Compare,Alloc>& rhs ){
			return !(lhs == rhs);
		}

		template< class Key, class Compare, class Alloc >
		bool operator<(const ft::Set<Key,Compare,Alloc>& lhs, const ft::Set<Key,Compare,Alloc>& rhs ){
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template< class Key, class Compare, class Alloc >
		bool operator<=(const ft::Set<Key,Compare,Alloc>& lhs, const ft::Set<Key,Compare,Alloc>& rhs ){
			return !(rhs < lhs);
		}

		template< class Key, class Compare, class Alloc >
		bool operator>(const ft::Set<Key,Compare,Alloc>& lhs, const ft::Set<Key,Compare,Alloc>& rhs ){
			return rhs < lhs;

		}
		template< class Key, class Compare, class Alloc >
		bool operator>=(const ft::Set<Key,Compare,Alloc>& lhs, const ft::Set<Key,Compare,Alloc>& rhs ){
			return !(rhs > lhs);
		}

		template< class Key, class Compare, class Alloc >
		void swap(ft::Set<Key,Compare,Alloc>& lhs, ft::Set<Key,Compare,Alloc>& rhs ){
			lhs.swap(rhs);
		}
}


#endif
