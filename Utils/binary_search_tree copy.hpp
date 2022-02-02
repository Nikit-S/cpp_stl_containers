
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
		: left(other.left), right(other.right), parent(other.parent), val(other.val), height(other.height) {}

	Node& operator=(const Node &other)
	{
		if (this == &other)
			return *this;
		left = other.left;
		right = other.right;
		parent = other.parent;
		val = other.val;
		height = other.height;
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
			size = other.size;
			return *this;
		}
		
		bool insert (iterator position, const Pair& value)
		{
			(void) position;
			return insert(value);
		}
		
		bool insert (const Pair& value)
		{
			pointer newNode = alloc.allocate(1);
			alloc.construct(newNode, Node(value, nil, nil, NULL));
			
			pointer tmp = root;
			pointer saver = NULL;
			
			//std::cout << "Value: " << tmp->val << std::endl;
			//std::cout << "gona insert" << std::endl;
			
			while (tmp != nil)
			{
				//std::cout << "in cycle" << std::endl;
				//std::cout << comp(value, saver->val) << std::endl;
				
				saver = tmp;
				if (comp(tmp->val, value))
					tmp = tmp->right;
				else if (comp(value, tmp->val))
					tmp = tmp->left;
				else
				{
					//std::cout << "everything is a lie" << std::endl;
					
					alloc.destroy(newNode);
					alloc.deallocate(newNode, 1);
					return (false);
				}
			}
			
			
			//std::cout << "gona insert" << std::endl;
			if (tmp == root)
			{
				//std::cout << "saver == root" << std::endl;
				root = newNode;
				saver = nil;
			}
			else if (comp(saver->val, value))
			{
				//std::cout << comp(value, saver->val) << std::endl;
				saver->right = newNode;
			}
			else if (comp(value, saver->val))
			{
				//std::cout << comp(value, saver->val) << std::endl;
				saver->left = newNode;
				
			}
			newNode->parent = saver;
			
			//std::cout << "Value: " << newNode->val << " Left: " << newNode->left->val << " Right: " << newNode->right->val << " Parent: " << newNode->parent->val << std::endl;
			
			size++;
			fixInsertion(newNode);
			return (true);
		}
		
		void fixInsertion(pointer node)
		{
				if (node == root)
					return ;
				if (node->parent == node->parent->parent->right) 
				{
					if (node == node->parent->left)
					{
						node = node->parent;
						rightRotate(node);
					}
					leftRotate(node->parent->parent);
					
				} 
				else if (node->parent == node->parent->parent->left) 
				{
					if (node == node->parent->right)
					{
						node = node->parent;
						leftRotate(node);
					}
					rightRotate(node->parent->parent);
				}
				//
				//	break;
			
		}
		
		void leftRotate(pointer x)
		{			
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

		void rightRotate(pointer x)
		{
			
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
		
		bool erase (iterator position)
		{
			pointer tmp = position.base();
			if (tmp == nil)
				return false;
			return(erase(tmp));
		}
		
		bool erase(Key const &key)
		{
			pointer tmp = find(ft::make_pair(key, T()));
			if (tmp == nil)
				return false;
			return (erase(tmp));
			
		}
		
		
		
		
		bool erase(pointer const &pt)
		{
			pointer tmp = pt;
			pointer tmp_clr = pt;
			if (tmp == nil)
				return false;
			ft::pair<int, pointer> pr = count_children(tmp);
			switch (pr.first)
			{
				case 0:
				{
					if (tmp->parent->left == tmp)
						tmp->parent->left = nil;
					else
						tmp->parent->right = nil;
					pr.second->parent = tmp->parent;
					break;
					
				}
				case 1:
				{
					replace(tmp, pr.second);
					break;
				}
				case 3:
				{
					leftparent(pr.second);
					replace(tmp, getMin(pr.second));
					
					pr.second->left = tmp_clr->left;
					pr.second->right = tmp_clr->right;
					pr.second->left->parent = pr.second->left == nil ? nil : pr.second;
					pr.second->right->parent = pr.second->right == nil ? nil : pr.second;
					break;
				}
			}
			
			alloc.destroy(tmp_clr);
			alloc.deallocate(tmp_clr, 1);
			size--;
			if (size == 0)
				root = nil;
			return true;
		}
		
		void fixDeletion(pointer node)
		{
			
		}
		
		void leftparent(pointer p)
		{
			if (p->parent == nil)
				return;
			if (p->parent->left == p)
				p->parent->left = nil;
			else if (p->parent->right == p)
				p->parent->right = nil;
			/*std::cout 
			<< "-r:" << p->parent->right->val.second
			<< " -l:" << p->parent->left->val.second
			<< std::endl;*/
		}
		
		void replace (pointer p1, pointer p2)
		{
			if (p1->parent == nil)
			{
				root = p2;
			}
			else if (p1 == p1->parent->left)
				p1->parent->left = p2;
			else
				p1->parent->right = p2;

			p2->parent = p1->parent;
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
