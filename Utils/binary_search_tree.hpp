#ifndef BST_HPP
#define BST_GPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <iostream>
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "bst_iterator.hpp"


enum Color
{
	BLACK,
	RED
};

template <class T>
class Node
{
	public:
		typedef T		value_type;
		Node 			*left;
		Node 			*right;
		Node 			*parent;
		T 		val;
		int 			color;
	
	public:
	
	


	Node(): left(NULL), right(NULL), parent(NULL), val(), color(BLACK){}
	
	Node(const T &data) : left(NULL), right(NULL), val(data), color(BLACK) {}

	Node(const T &val, Node *left, Node *right, Node *parent, int color)
		: left(left), right(right), parent(parent), val(val), color(color){}

	~Node(){};

	Node(const Node &other)
		: left(other.left), right(other.right), parent(other.parent), val(other.val),  color(other.color){}

	Node& operator=(const Node &other)
	{
		if (this == &other)
			return *this;
		left = other.left;
		right = other.right;
		parent = other.parent;
		val = other.val;
		color = other.color;
		return *this;
		
	}
};

template <class T, class Key, class Compare, class Allocator, class Pair>
class Tree
{
	public:

		typedef Compare 												key_compare;
		typedef std::size_t 											size_type;
		
		typedef Node<Pair>													Node;
		typedef typename Allocator::template rebind<Node>::other		allocator_type;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		
		typedef ft::bst_iterator<Node, Pair>								iterator;
		typedef ft::bst_iterator<Node, Pair>								const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

	private:
		pointer 			root;
		pointer 			nil;
		size_type			size;
		allocator_type 		alloc;
		key_compare 		comp;
		
	public:
	
		Tree(key_compare const& cmp = key_compare()): comp(cmp), size(0)
		{
			nil = alloc.allocate(1);
			alloc.construct(nil, Node());
			root = nil;
		}
		
		~Tree()
		{
			rclear(root);
			alloc.destroy(nil);
			alloc.deallocate(nil, 1);
		}
		
		Tree (const Tree &other)
		{
			*this = other;
		}
		
		void rclear(pointer root)
		{
			if (root == nil)
				return ;
			rclear(root->left);
			rclear(root->right);
			alloc.destroy(root);
			alloc.deallocate(root, 1);
			size--;
			root = nil;
		}
		
		iterator lower_bound(const Pair& key)
		{
			pointer tmp = root;
			iterator res;

			iterator endit = end();
			endit--;

			while (tmp != nil){
				if (!comp(tmp->val, key)){
					res = iterator(tmp, root);
					tmp = tmp->left;
				}else
					tmp = tmp->right;
			}
			if (!comp(key, *endit))
				return iterator(nil, root);

			return res;
		}
		
		const_iterator lower_bound(const Pair& key) const
		{
			pointer tmp = root;
			iterator res;

			iterator endit = end();
			endit--;

			while (tmp != nil){
				if (!comp(tmp->val, key)){
					res = const_iterator(tmp, root);
					tmp = tmp->left;
				}else
					tmp = tmp->right;
			}
			if (!comp(key, *endit))
				return const_iterator(nil, root);

			return res;
		}
		
		iterator upper_bound(const Pair& key)
		{
			pointer tmp = root;
			iterator res;

			iterator endit = end();
			endit--;

			while (tmp != nil)
			{
				if (comp(key, tmp->val))
				{
					res = iterator(tmp, root);
					tmp = tmp->left;
				}
				else
					tmp = tmp->right;
			}
			if (!comp(key, *endit))
				return iterator(nil, root);

			return res;
		}

		const_iterator upper_bound(const Pair& key) const
		{
			pointer tmp = root;
			const_iterator res;

			const_iterator endit = end();
			endit--;

			while (tmp != nil){
				if (comp(key, tmp->val)){
					res = const_iterator(tmp, root);
					tmp = tmp->left;
				}else
					tmp = tmp->right;
			}
			if (!comp(key, *endit))
				return const_iterator(nil, root);

			return res;
		}
		
		Tree& operator=(const Tree& other)
		{
			if (this == &other)
				return *this;

			rclear(root);
			alloc.destroy(nil);
			alloc.deallocate(nil, 1);
			
			alloc = other.alloc;
			comp = other.comp;
			nil = alloc.allocate(1);
			alloc.construct(nil, Node());
			root = nil;
			deepCopy(other.root, other.nil);
			return *this;
		}
		
		void deepCopy(pointer rootPtr, pointer nilPtr){
		if (rootPtr != nilPtr){
			insert(rootPtr->val);
			deepCopy(rootPtr->right, nilPtr);
			deepCopy(rootPtr->left, nilPtr);
		}
	}
		
		bool insert( const Pair& par ) {
			
			pointer newNode = alloc.allocate(1);
			alloc.construct(newNode, Node(par, nil, nil, NULL, RED));

			pointer y = nil;
			pointer x = this->root;
			while (x != nil) {
				y = x;
				if (comp(newNode->val, x->val))
					x = x->left;
				else if (comp(x->val, newNode->val))
					x = x->right;
				else{
					alloc.destroy(newNode);
					alloc.deallocate(newNode, 1);
					return false;
				}
			}

			newNode->parent = y;

			if (y == nil)
				root = newNode;
			else if (comp(newNode->val, y->val))
				y->left = newNode;
			else
				y->right = newNode;

			size++;

			if (newNode->parent == nil) {
				newNode->color = BLACK;
				return true;
			}

			if (newNode->parent->parent == nil)
				return true;

			fixInsertion(newNode);
			return  true;
		}
		
		void fixInsertion(pointer node){
		pointer uncle;
		while (node->parent->color == RED){
			if (node->parent == node->parent->parent->right) {
				uncle = node->parent->parent->left;
				if (uncle->color == RED) {
					uncle->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->left){
						node = node->parent;
						rightRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					leftRotate(node->parent->parent);
				}
			} else{
				uncle = node->parent->parent->right;
				if (uncle->color == RED){
					uncle->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}else{
					if (node == node->parent->right){
						node = node->parent;
						leftRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					rightRotate(node->parent->parent);
				}
			}
			if (node == root)
				break;
		}
		root->color = BLACK;
	}
		
		
		ft::pair<int, pointer> count_children(pointer & pt)
		{
			if (pt->left == nil && pt->right == nil)
				return ft::make_pair(0, nil);
			else if (pt->left == nil && pt->right != nil)
				return ft::make_pair(1, pt->right);
			else if (pt->left != nil && pt->right == nil)
				return ft::make_pair(1, pt->left);
			else
				return ft::make_pair(3, getMin(pt->right));

				
		}
		
		
		
		bool erase(const Pair &key){
			pointer node = root;
			pointer x, y, z;
			z = nil;

			while (node != nil){
				if (comp(node->val, key))
					node = node->right;
				else if (comp(key, node->val))
					node = node->left;
				else {
					z = node;
					break;
				}
			}

			if (z == nil)
				return false;

			y = z;
			int originalColor = y->color;

			if (y->left == nil){
				x = z->right;
				replace(z, z->right);
			}else if (z->right == nil){
				x = z->left;
				replace(z, z->left);
			}else{
				y = getMin(z->right);
				originalColor = y->color;
				x = y->right;

				if (y->parent == z)
					x->parent = y;
				else{
					replace(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				replace(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}

			alloc.destroy(z);
			alloc.deallocate(z, 1);

			if(originalColor == BLACK)
				fixDeletion(x);

			size--;
			return true;
		}
		
		void fixDeletion(pointer node){
		pointer sibling;

		while (node != root && node->color == BLACK){
			if (node == node->parent->left){
				sibling = node->parent->right;
				if (sibling->color == RED){
					sibling->color = BLACK;
					node->parent->color = RED;
					leftRotate(node->parent);
					sibling = node->parent->right;
				}
				if (sibling->left->color == BLACK && sibling->right->color == BLACK){
					sibling->color = RED;
					node = node->parent;
				}else{
					if (sibling->right->color == BLACK){
						sibling->left->color = BLACK;
						sibling->color = RED;
						rightRotate(sibling);
						sibling = node->parent->right;
					}
					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->right->color = BLACK;
					leftRotate(node->parent);
					node = root;
				}
			}else{
				sibling = node->parent->left;
				if (sibling->color == RED){
					sibling->color = BLACK;
					node->parent->color = RED;
					rightRotate(node->parent);
					sibling = node->parent->left;
				}

				if (sibling->right->color == BLACK && sibling->right->color == BLACK){
					sibling->color = RED;
					node = node->parent;
				}else{
					if (sibling->left->color == BLACK){
						sibling->right->color = BLACK;
						sibling->color = RED;
						leftRotate(sibling);
						sibling = node->parent->left;
					}

					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->left->color = BLACK;
					rightRotate(node->parent);
					node = root;
				}

			}
		}
		node->color = BLACK;
	}
		
		/*void leftparent(pointer p)
		{
			if (p->parent == nil)
				return;
			if (p->parent->left == p)
				p->parent->left = nil;
			else if (p->parent->right == p)
				p->parent->right = nil;
			std::cout 
			<< "-r:" << p->parent->right->val.second
			<< " -l:" << p->parent->left->val.second
			<< std::endl;
		}*/
		
		void leftRotate(pointer x){
		pointer  y = x->right;

		x->right = y->left;
		if (y->left != nil)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == nil)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	void rightRotate(pointer x){
		pointer  y = x->left;

		x->left = y->right;
		if (y->right != nil)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == nil)
			this->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;
	}

	void replace(pointer x, pointer y){
		if (x->parent == nil)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->parent = x->parent;
	}
		
		pointer getMin(pointer node)
		{
			if (node == nil || node == NULL)
				return nil;

			while (node->left != nil)
				node = node->left;

			return node;
		}

		pointer getMin() const
		{
			if (root == NULL || root == nil)
				return nil;

			pointer tmp = root;
			//std::cout << tmp->left->val << std::endl;
			while (tmp->left != nil)
			{
				tmp = tmp->left;
			//std::cout << tmp->val << std::endl;
				
			}
			return tmp;
		}
		
		size_type max_size() const
		{
			return alloc.max_size();
		}
		
		pointer find(Pair const &key) const
		{
			pointer tmp = root;
			while (tmp != nil){
				if (comp(key, tmp->val))
					tmp = tmp->left;
				else if(comp(tmp->val, key))
					tmp = tmp->right;
				else
					return tmp;
			}
			return nil;
		}
	
		void swap(Tree &other){
			std::swap(root, other.root);
			std::swap(nil, other.nil);
			std::swap(size, other.size);
			std::swap(alloc, other.alloc);
			std::swap(comp, other.comp);
		}
		
		iterator		begin()
		{
			return       iterator(getMin(), root);
		}

		const_iterator		begin() const
		{
			return       const_iterator(getMin(), root);
		}

		iterator		end()
		{
			return       iterator(nil, root);
		}

		const_iterator		end() const
		{
			return       const_iterator(nil, root);
		}

		reverse_iterator		rbegin()
		{
			return       	reverse_iterator(end());
		}

		const_reverse_iterator		rbegin() const
		{
			return       	const_reverse_iterator(end());
		}

		reverse_iterator		rend()
		{
			return       	reverse_iterator(begin());
		}

		const_reverse_iterator		rend() const
		{
			return       	const_reverse_iterator(begin());
		}
		
		pointer const getRoot() const {return (root);}
		pointer const getNil() const {return (nil);}
		size_type const getSize() const {return (size);}
		void nilRoot() {root = nil;}

		
};

#endif
