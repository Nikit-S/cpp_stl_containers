#include <stdlib.h>
#include "../Utils/reverse_iterator.hpp"
namespace ft
{
	template <typename NodeP, typename Pair>
	class bst_iterator
	{
		public:
			typedef NodeP *npointer;
			typedef Pair &reference;
			typedef Pair *pointer;
			
			typedef Pair value_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename std::bidirectional_iterator_tag	iterator_category;
		private:
			npointer ptr;
			npointer root;
			npointer nil;
		
		public:
		
		bst_iterator(): ptr(NULL), root(NULL), nil(NULL) {}
		
		bst_iterator(npointer p, npointer r): ptr(p), root(r), nil(r->parent) {}
		
		bst_iterator(bst_iterator const &p)
		{
			*this = p;
		}
		
		~bst_iterator(){}
		
		npointer base() const { return ptr; }
		
		template <typename U, typename P1>
		bst_iterator(const bst_iterator<U,P1> &u)
		{
			ptr = *u.getPtr();
			root = *u.getRoot();
			nil = *u.getNil();
		}
		
		bst_iterator &operator= (bst_iterator const &p)
		{
			if (&p == this)
				return (*this);
			ptr = p.getPtr();
			root = p.getRoot();
			nil = p.getNil();
			return (*this);
		}
		
		npointer getPtr() const
		{
			return (ptr);
		}
		
		npointer getRoot() const
		{
			return (root);
		}
		
		npointer getNil() const
		{
			return (nil);
		}
		
		
		//hardcore operators
		
		npointer getMax(npointer pt)
		{
			while (pt && pt->right != nil)
				pt = pt->right;
			return pt;
		}

		npointer getMin(npointer pt)
		{
			//std::cout << "pt: " << pt->val.second << std::endl;
			//std::cout << "pt->left: " << pt->left << std::endl;
			//std::cout << "nil: " << nil << std::endl;
			while (pt && pt->left != nil)
				pt = pt->left;
			//std::cout << "pt: " << pt << std::endl;

			
			return pt;
		}
		
		bst_iterator &operator++ ()
		{	
			
			//std::cout << "finding" << std::endl;
			
			if ((ptr == root && ptr->left == nil && ptr->right == nil) || ptr == nil)
				ptr = ptr->left;
			else
			{
				//std::cout << "non empty root" << std::endl;
				if (ptr->right != nil)
					ptr = getMin(ptr->right);
				else
				{
					//std::cout << "right = nil" << std::endl;
					npointer temp = ptr->parent;
					while (temp != nil && ptr == temp->right)
					{
						ptr = temp;
						temp = temp->parent;
					}
					ptr = temp;
				}
			}
			//std::cout << "found:" << ptr << std::endl;
			
			return *this;
		}
		
		bst_iterator operator++(int)
		{
			bst_iterator tmp = *this;
			operator++();
			return tmp;
		}
		
		bst_iterator &operator--()
		{	
			if (ptr == nil)
			{
				ptr = getMax(root);
				return *this;
			}
			if (ptr->left != nil)
				ptr = getMax(ptr->left);
			else
			{
				npointer tmp = ptr->parent;
				while (tmp != nil && ptr == tmp->left)
				{
					ptr = tmp;
					tmp = tmp->parent;
				}
				ptr = tmp;
			}
			return *this;
		}
		
		bst_iterator operator--(int)
		{
			bst_iterator 	tmp = *this;
			operator--();
			return tmp;
		}
		
		bool operator==(const bst_iterator &rbt) const
		{
			return ptr == rbt.ptr;
		}

		bool operator!=(const bst_iterator &rbt) const
		{
			return ptr != rbt.ptr;
		}

		reference operator*() const
		{
			return ptr->val;
		}

		pointer operator->() const
		{
			return &ptr->val;
		}
	};
}
