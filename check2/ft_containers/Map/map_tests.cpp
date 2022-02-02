#include "map.hpp"
#include <map>
#include <iostream>
#include <string>
#include <vector>

void sep(std::string str)
{
	std::cout << "------" << str << "------" << std::endl;
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp
{
	bool operator() (const char& lhs, const char& rhs) const
	{
		return lhs<rhs;
	}
};

int constructors ()
{
	ft::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	ft::map<char,int> second (first.begin(),first.end());

	ft::map<char,int> *third = new ft::map<char,int>(second);

	ft::map<char,int,classcomp> fourth; // class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

	delete third;
	return 0;
}

int copyop ()
{
	ft::map<char,int> first;
	ft::map<char,int> *second = new ft::map<char,int>;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	*second=first; // second now contains 3 ints
	first=ft::map<char,int>();	// and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second->size() << '\n';
	ft::map<char,int> *third = new ft::map<char,int>;
	*third = *second;
	delete second;
	std::cout << "Size of third: " << third->size() << '\n';
	std::cout << "'x': " << (*third)['x'] << '\n';
	delete third;
	return 0;
}

void MemberFun()
{
	sep("!!! MemberFun !!!");
	sep("constructors");
	constructors();
	sep("copyop");
	copyop();
}

int begin_ch ()
{
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}

int const_begin_ch ()
{
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (ft::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}

int end_ch ()
{
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}

int const_end_ch ()
{
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (ft::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}

int rbegin_ch ()
{
	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

	return 0;
}

int const_rbegin_ch ()
{
	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::const_reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

	return 0;
}

int rend_ch ()
{
	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

	return 0;
}

int const_rend_ch ()
{
	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	ft::map<char,int>::const_reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';

	return 0;
}

void IteratorFun()
{
	sep("!!! IteratorFun !!!");
	sep("begin_ch()");
	begin_ch();
	sep("const_begin_ch()");
	const_begin_ch();
	sep("end_ch()");
	end_ch();
	sep("const_end_ch()");
	const_end_ch();
	sep("rbegin_ch()");
	rbegin_ch();
	sep("const_rbegin_ch()");
	const_rbegin_ch();
	sep("rend_ch()");
	rend_ch();
	sep("const_rend_ch()");
	const_rend_ch();


}

int empty_ch ()
{
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}

	return 0;
}

int size_ch ()
{
	ft::map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';

	return 0;
}

int max_size_ch ()
{
	int i;
	ft::map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map could contain 1000 elements. (" << mymap.max_size() <<")\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";

	return 0;
}

void CapacityFun()
{
	sep("!!! CapacityFun !!!");
	sep("empty_ch()");
	empty_ch();
	sep("size_ch()");
	size_ch();
	sep("max_size_ch()");
	max_size_ch();
	
}

int operator_sqr_ch()
{
	ft::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	return (0);
}

void ElemacFun()
{
	sep("!!! ElemacFun !!!");
	sep("operator[]");
	operator_sqr_ch();
}

int insert_ch ()
{
	ft::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));	// max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));	// no max efficiency inserting
	
	// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	
	ft::map<int, char> mp;
	typedef ft::pair<int,char> par;
	
	int arr[] = {3, 2, 1, 0};
	
	mp.insert(par(arr[0], arr[0] + 'A'));
	std::cout << "MYYmap contains:\n";
	for (ft::map<int,char>::iterator it=mp.begin(); it!=mp.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
		
	mp.insert(par(arr[1], arr[1] + 'A'));
	std::cout << "MYYmap contains:\n";
	for (ft::map<int,char>::iterator it=mp.begin(); it!=mp.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	
	mp.insert(par(arr[2], arr[3] + 'A'));
	std::cout << "MYYmap contains:\n";
	for (ft::map<int,char>::iterator it=mp.begin(); it!=mp.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	
	
	ft::map<int,int> mpa;
	int i[] = {2, 5, 8, 10, 15, 12, 18, 20, 30, 25, 22, 27, 35, 32, 31, 40, 0};
	for (int l =0; i[l] != 0; l++ )
		mpa[i[l]] = i[l];
	
	
	std::cout << "mpa contains:\n";
	for (ft::map<int,int>::iterator it=mpa.begin(); it!=mpa.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	return 0;
}

int erase_ch ()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);									 // erasing by iterator

	mymap.erase ('c');									// erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );		// erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';


	ft::map<int,int> mp;
	int i[] = {20, 10, 30, 5, 15, 25, 35, 2, 8, 12, 18, 22, 27, 32, 40, 31, 0};
	for (int l =0; i[l] != 0; l++ )
		mp[i[l]] = i[l];
	
	
	std::cout << "MYYmap contains:\n";
	for (ft::map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
		
	
	mp.erase(27);
	mp.erase(22);
	//mp.erase(25);
	std::cout << "MYYmap contains:\n";
	for (ft::map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	
	return 0;
}

int swap_ch ()
{
	ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}

int clear_ch ()
{
	ft::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}

void ModifiersFun()
{
	sep("!!! ModifiersFun !!!");
	sep("insert_ch()");
	insert_ch();
	sep("erase_ch()");
	erase_ch();
	sep("swap_ch()");
	swap_ch();
	sep("clear_ch()");
	clear_ch();
}

int key_comp_ch ()
{
	ft::map<char,int> mymap;

	ft::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;		 // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

	return 0;
}

int value_comp_ch ()
{
	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	ft::pair<char,int> highest = *mymap.rbegin();					// last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );

	return 0;
}

void ObserversFun()
{
	sep("!!! ObserversFun !!!");
	sep("key_comp_ch()");
	key_comp_ch();
	sep("value_comp_ch()");
	value_comp_ch();
}

int find_ch ()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';

	return 0;
}

int const_find_ch ()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::const_iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "b => " << it->second << '\n';

	return 0;
}

int count_ch ()
{
	ft::map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else 
			std::cout << " is not an element of mymap.\n";
	}

	return 0;
}

int lower_upper_bound ()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');	// itlow points to b
	itup=mymap.upper_bound ('d');	 // itup points to e (not d!)

	mymap.erase(itlow,itup);				// erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}

int equal_range_ch ()
{
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	return 0;
}

int const_equal_range_ch ()
{
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	ft::pair<ft::map<char,int>::const_iterator,ft::map<char,int>::const_iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	return 0;
}

void OperationsFun()
{
	sep("!!! OperationsFun !!!");
	sep("find_ch()");
	find_ch();
	const_find_ch();
	sep("count_ch()");
	count_ch();
	sep("lower_upper_bound()");
	lower_upper_bound();
	sep("equal_range_ch");
	equal_range_ch();
	
}

int get_allocator ()
{
	int psize;
	ft::map<char,int> mymap;
	ft::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(ft::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);

	return 0;
}

void AllocatorFun()
{
	sep("!!! AllocatorFun !!!");
	sep("get_allocator()");
	get_allocator();
}




int main ()
{
	MemberFun();
	IteratorFun();
	CapacityFun();
	ElemacFun();
	ModifiersFun();
	ObserversFun();
	OperationsFun();
	AllocatorFun();
	return (0);
}
