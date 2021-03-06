#include "vector.hpp"
#include <vector>
#include <string>


void sep(std::string str)
{
	std::cout << "\n----- " << str << " ------" << std::endl;
}



void testConstructors()
{

	sep("!!! testConstructors !!!");
	sep("Constructor");
	
	// constructors used in the same order as described above:
	ft::vector<int> first;																// empty vector of ints
	ft::vector<int> second (4,100);											 // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());	// iterating through second
	ft::vector<int> fourth (third);											 // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents are:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	
	sep("operator=");
	
	
	ft::vector<int> foo (3,0);
	ft::vector<int> bar (5,0);

	bar = foo;
	foo = ft::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void begin_ch()
{
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void end_ch()
{
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void rbegin_ch()
{
	ft::vector<int> myvector (5);	// 5 default-constructed ints

	int i=0;

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void rend_ch()
{
	ft::vector<int> myvector (5);	// 5 default-constructed ints

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i=0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void const_begin_ch()
{
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (ft::vector<int>::const_iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void const_end_ch()
{
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (ft::vector<int>::const_iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void const_rbegin_ch()
{
	ft::vector<int> myvector (5);	// 5 default-constructed ints

	int i=0;

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (ft::vector<int>::const_iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void const_rend_ch()
{
	ft::vector<int> myvector (5);	// 5 default-constructed ints

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i=0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (ft::vector<int>::const_iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void testIterators()
{
	sep("!!! testIterators !!!");
	sep("begin_ch()");
	begin_ch();
	const_begin_ch();
	sep("end_ch()");
	end_ch();
	const_end_ch();
	sep("rbegin_ch()");
	rbegin_ch();
	const_rbegin_ch();
	sep("rend_ch()");
	rend_ch();
	const_rend_ch();
}

void size_ch()
{
	ft::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void max_size_ch()
{
	ft::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

void resize_ch()
{
	ft::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	std::cout << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	
	myvector.resize(8,100);
	std::cout << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	
	myvector.resize(12);
	std::cout << "myvector contains:";
	for (int i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	
	ft::vector<int> myvector1;

	// set some initial content:

	myvector1.resize(5);
	std::cout << "myvector contains:";
	for (int i=0;i<myvector1.size();i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
	
	myvector1.resize(8,100);
	std::cout << "myvector contains:";
	for (int i=0;i<myvector1.size();i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
	
	myvector1.resize(12);
	std::cout << "myvector contains:";
	for (int i=0;i<myvector1.size();i++)
		std::cout << ' ' << myvector1[i];
	std::cout << '\n';
	
	
	ft::vector<int> vct;
	int _ratio = 1000;
    ft::vector<int> v;
    vct.assign(9900 * _ratio, 1);
    vct.resize(5000 * _ratio);
    vct.reserve(5000 * _ratio);
    v.push_back(vct.size());
    v.push_back(vct.capacity());
    vct.resize(7000 * _ratio);
    v.push_back(vct.size());
    v.push_back(vct.capacity());
    vct.resize(15300 * _ratio, int());
    v.push_back(vct.size());
    v.push_back(vct.capacity());
    v.push_back(vct[65]);
	std::cout << "vct contains:";
	int il = 0;
	for (ft::vector<int>::iterator it = vct.begin(); it!=vct.end(); ++it)
	{
		if (il % 921 == 0)
			std::cout << ' ' <<  *it;
		il++;
	}
	std::cout << '\n';
	
	std::cout << "vct1 contains:";
	for (ft::vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

}

void capacity_ch()
{
	ft::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}

void empty_ch()
{
	ft::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		 sum += myvector.back();
		 myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
}

void reserve_ch()
{
	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);	 // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	
	try {bar.reserve(bar.max_size() + 1);}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void testCapacity()
{
	sep("!!! testCapacity !!!");
	sep("size_ch()");
	size_ch();
	sep("max_size_ch()");
	max_size_ch();
	sep("resize_ch()");
	resize_ch();
	sep("capacity_ch()");
	capacity_ch();
	sep("empty_ch()");
	empty_ch();
	sep("reserve_ch()");
	reserve_ch();

	
}

void operator_sqr_ch()
{
	ft::vector<int> myvector (10);	 // 10 zero-initialized elements

	ft::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}
	
	ft::vector<int> const myvectorconst(myvector);
	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvectorconst[i];
	std::cout << '\n';
}

void at_ch()
{
	ft::vector<int> myvector (10);	 // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	ft::vector<int> const myvectorconst(myvector);
	std::cout << "myvectorconst contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvectorconst.at(i);
	std::cout << '\n';
	
	
	
	try {myvector.at(10);}
	catch (std::exception &e)
	{ std::cout << e.what() << std::endl;}
	
	try {myvector.at(-10);}
	catch (std::exception &e)
	{ std::cout << e.what() << std::endl;}
}

void front_ch()
{
	ft::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
	
	ft::vector<int> const myvectorconst(myvector);
	std::cout << "myvector.front() is now " << myvectorconst.front() << '\n';
}

void back_ch()
{
	ft::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	
	ft::vector<int> const myvectorconst(myvector);
	std::cout << "myvectorconst contains:";
	for (unsigned i=0; i<myvectorconst.size() ; i++)
		std::cout << ' ' << myvectorconst[i];
	std::cout << '\n';
}



void testAccess()
{
	sep("!!! testAccess !!!");
	sep("operator_sqr_ch()");
	operator_sqr_ch();
	sep("at_ch()");
	at_ch();
	sep("front_ch()");
	front_ch();
	sep("back_ch()");
	back_ch();
}

void assign_ch()
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);						 // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);	 // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}

void push_back_ch()
{
	ft::vector<int> myvector;
	int myint;

	//std::cout << "Please enter some integers (enter 0 to end):\n";

	for (unsigned i=0; i<10; i++) myvector.push_back(i);

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
}

void pop_back_ch()
{
	ft::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
}

void insert_ch()
{
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	std::cout << "2 inserts" << std::endl;
	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	std::cout << "3 inserts" << std::endl;
	
	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "4 inserts" << std::endl;
	
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	
	ft::vector<int> *vector = new ft::vector<int>;
	vector->assign(1500, 1);
	//std::cout << "val of it: " << *(vector.insert(vector.end() - 800, 44)) << std::endl;
	ft::vector<int>::iterator::pointer testpt =  vector->insert(vector->end() - 800, 44).base();
	std::cout << "--VECTOR-- contains:";
	for (it=vector->begin(); it<vector->end(); it++)
	{
		if (testpt == it.base())
			std::cout << *it << " address is true ";
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
	delete vector;
	//while (1);
}

void erase_ch()
{
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	std::cout << *(myvector.erase (myvector.begin()+5)) << std::endl;

	// erase the first 3 elements:
	std::cout << *(myvector.erase (myvector.begin(),myvector.begin()+3)) << std::endl;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void swap_ch()
{
	ft::vector<int> foo (3,100);	 // three ints with a value of 100
	ft::vector<int> bar (5,200);	 // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
}

void clear_ch()
{
	ft::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}


void testModifiers()
{
	sep("!!! testModifiers !!!");
	
	sep("assign_ch()");
	assign_ch();
	sep("push_back_ch()");
	push_back_ch();
	sep("pop_back_ch()");
	pop_back_ch();
	sep("insert_ch()");
	insert_ch();
	sep("erase_ch()");
	erase_ch();
	sep("swap_ch()");
	swap_ch();
	sep("clear_ch()");
	clear_ch();

}

void	testAllocator()
{
	
	sep("!!! testAllocator !!!");
	sep("get_allocator_ch()");

	ft::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void operators_ch()
{
	ft::vector<int> foo (3,100);	 // three ints with a value of 100
	ft::vector<int> bar (2,200);	 // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

void non_swap_ch()
{
	unsigned int i;
	ft::vector<int> foo (3,100);	 // three ints with a value of 100
	ft::vector<int> bar (5,200);	 // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testNonMember()
{
	sep("!!! testNonMember !!!");
	sep("operators_ch()");
	operators_ch();
	sep("non_swap_ch()");
	non_swap_ch();
}

int main()
{
	testConstructors();
	testIterators();
	testCapacity();
	testAccess();
	testModifiers();
	testAllocator();
	testNonMember();
}


