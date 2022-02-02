#include <iostream>
#include <iterator>
#include <typeinfo>
#include "random_access_iterator.hpp"
#include "binary_search_tree.hpp"
#include <vector>
#include <algorithm>
#include <type_traits>

void sep(std::string str)
{
	std::cout << "\n------" << str << "------" << std::endl;
}

template <typename T>
T next (T pt, T nil)
{
	T next;
	
	if (pt->right == nil) {
						// Node has no right child
						next = pt;
						while (next->parent != nil && next == next->parent->right)
								next = next->parent;
						next = next->parent;
				} else {
						// Find the leftmost node in the right subtree
						next = pt->right;
						while (next->left != nil && next->left != NULL)
								next = next->left;
				}

				return next;
}

template <typename T>
void display(T &tr, typename T::pointer pt)
{
	std::cout << "Size: " << tr.size << std::endl;
	
	typename T::pointer temp = pt;
	
	while (temp != tr.nil)
	{
		std::cout << temp->val << " ";
		
		temp = next(temp, tr.nil);
		
	}
	std::cout << std::endl;
}

int iterator_traits_ch() {
	typedef ft::iterator_traits<int*> traits;
	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator";
	std::cout << std::endl;
	
	if (typeid(traits::difference_type)==typeid(std::ptrdiff_t))
		std::cout << "int* difference_type is ptrdiff_t";
	std::cout << std::endl;
	
	if (typeid(traits::value_type)==typeid(int))
		std::cout << "int* value_type is T";
	std::cout << std::endl;
	
	if (typeid(traits::pointer)==typeid(int *))
		std::cout << "int* value_type is T*";
	std::cout << std::endl;
	
	if (typeid(traits::reference)==typeid(int &))
		std::cout << "int* value_type is T&";
	std::cout << std::endl;
	
	return 0;
}

int const_iterator_traits_ch() {
	typedef ft::iterator_traits<const int*> traits;
	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator";
	std::cout << std::endl;
	
	if (typeid(traits::difference_type)==typeid(std::ptrdiff_t))
		std::cout << "int* difference_type is ptrdiff_t";
	std::cout << std::endl;
	
	if (typeid(traits::value_type)==typeid(int))
		std::cout << "int* value_type is const int";
	std::cout << std::endl;
	
	if (typeid(traits::pointer)==typeid(const int *))
		std::cout << "int* value_type is const int *";
	std::cout << std::endl;
	
	if (typeid(traits::reference)==typeid(const int &))
		std::cout << "int* value_type is const int &";
	std::cout << std::endl;
	
	return 0;
}

void iterator_traits_fun()
{
	sep("iterator_traits_ch()");
	iterator_traits_ch();
	sep("const_iterator_traits_ch()");
	const_iterator_traits_ch();
}

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename ft::enable_if<ft::is_integral<T>::value,bool>::type
	is_odd (T i) {return bool(i%2);}

// 2. the second template argument is only valid if T is an integral type:
template < class T,
					 class = typename ft::enable_if<ft::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}

int enable_if_ch() {

	short int i = 1;		// code does not compile if type of i is not integral

	std::cout << std::boolalpha;
	std::cout << "i is odd: " << is_odd(i) << std::endl;
	std::cout << "i is even: " << is_even(i) << std::endl;

	return 0;
}

void enable_if_fun()
{
	sep("enable_if_ch()");
	enable_if_ch();
}

bool mypredicate (int i, int j) {
	return (i==j);
}

int equal_ch ()
{
	int myints[] = {20,40,60,80,100}; //	 myints: 20 40 60 80 100
	std::vector<int>myvector (myints,myints+5);		 // myvector: 20 40 60 80 100

	// using default comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;																 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	return 0;
}

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

int lexi_ch ()
{
	char foo[]="Apple";
	char bar[]="apartment";

	std::cout << std::boolalpha;

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	std::cout << '\n';

	return 0;
}

void equal_lexi_fun()
{
	sep("equal_ch()");
	equal_ch();
	sep("lexi_ch()");
	lexi_ch();
}

int constfun()
{
	ft::pair <std::string,double> product1;										 // default constructor
	ft::pair <std::string,double> product2 ("tomatoes",2.30);	 // value init
	ft::pair <std::string,double> product3 (product2);					// copy constructor

	product1 = ft::make_pair(std::string("lightbulbs"),0.99);	 // using make_pair (move)

	product2.first = "shoes";									// the type of first is string
	product2.second = 39.90;									 // the type of second is double

	std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	return 0;
}

int operator_equal_ch () {
	ft::pair <std::string,int> planet, homeplanet;

	planet = ft::make_pair("Earth",6371);

	homeplanet = planet;

	std::cout << "Home planet: " << homeplanet.first << '\n';
	std::cout << "Planet size: " << homeplanet.second << '\n';
	return 0;
}

void MemberFun()
{
	sep("constfun()");
	constfun();
	sep("operator_equal_ch()");
	operator_equal_ch();
}

void NonMemberFun()
{
	ft::pair<int,char> foo (10,'z');
	ft::pair<int,char> bar (90,'a');

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void makepairfun()
{
	ft::pair <int,int> foo;
	ft::pair <int,int> bar;

	foo = ft::make_pair (10,20);
	bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';

 
}

void pairs_fun()
{
	sep("MemberFun()");
	MemberFun();
	sep("NonMemberFun()");
	NonMemberFun();
	sep("makepairfun()");
	makepairfun();
}

int main()
{
	sep("!!! iterator_traits_fun() !!!");
	iterator_traits_fun();
	sep("!!! enable_if_fun() !!!");
	enable_if_fun();
	sep("!!! equal_lexi_fun() !!!");
	equal_lexi_fun();
	sep("!!! pairs_fun() !!!");
	pairs_fun();
}
