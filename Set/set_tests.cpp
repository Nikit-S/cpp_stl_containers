#include "set.hpp"
#include <set>
#include <vector>

struct mycomp{
	bool operator()(const int &x, const int &y) const{
		return x > y;
	}
};

void testGeneral(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - Element access"  << std::endl;
	ft::set<int> a;
	a.insert(3);
	a.insert(5);
	a.insert(20);
	a.insert(200);
	a.insert(18);
	a.insert(12);
	a.insert(18);
	a.insert(12);
	a.insert(22);
	a.insert(24);
	a.insert(-30);
	a.insert(120);

	for (ft::set<int>::iterator it = a.begin(); it != a.end(); it++){
		std::cout << *it << std::endl;
	}

	ft::set<char> b;
	b.insert('a');
	b.insert('b');
	b.insert('c');
	b.insert('d');

	for (ft::set<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << *it << std::endl;
	}
}

void testDelete(){
	ft::set<int> a;

	a.insert(0);
	a.insert(56);
	a.insert(0);
	a.insert(45);
	a.insert(8);
	a.insert(2);
	a.insert(2);
	a.insert(781);
	a.insert(36);

	ft::set<int>::iterator first = a.begin();
	ft::set<int>::iterator  last = a.end();

	last--;
	last--;
	last--;

	a.erase(first, last);
	for (ft::set<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;

	a.insert(22);
	a.insert(3);
	a.insert(4);

	for (ft::set<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
}


void testCapacity(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - empty()"  << std::endl;
	ft::set<int> a;
	std::cout << a.empty() <<std::endl;
	a.insert(22);
	std::cout << a.empty() <<std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - size()"  << std::endl;

	std::cout << a.size() << std::endl;
	a.insert(22);
	a.insert(22);
	std::cout << a.size() << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - max_size()"  << std::endl;
	std::cout << a.max_size() << std::endl;
}

void testLookUp(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - count()"  << std::endl;

	ft::set<int> a;

	a.insert(10);
	a.insert(5);
	a.insert(20);
	a.insert(1);
	a.insert(18);
	a.insert(12);
	a.insert(22);
	a.insert(3);
	a.insert(4);

	std::cout << a.count(4545) << std::endl;
	std::cout << a.count(1) << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - lower upper equal bounds()"  << std::endl;

	std::cout << *a.lower_bound(10) << std::endl;
	std::cout << *a.lower_bound(5) << std::endl;
	std::cout << *a.lower_bound(20) << std::endl;
	std::cout << *a.lower_bound(1) << std::endl;
	std::cout << *a.lower_bound(18) << std::endl;
	std::cout << *a.lower_bound(12) << std::endl;
	std::cout << *a.lower_bound(3) << std::endl;
	std::cout << *a.lower_bound(4) << std::endl;

	std::cout << *a.upper_bound(10) << std::endl;
	std::cout << *a.upper_bound(5) << std::endl;
	std::cout << *a.upper_bound(20) << std::endl;
	std::cout << *a.upper_bound(1) << std::endl;
	std::cout << *a.upper_bound(18) << std::endl;
	std::cout << *a.upper_bound(12) << std::endl;
	std::cout << *a.upper_bound(3) << std::endl;
	std::cout << *a.upper_bound(4) << std::endl;


	std::cout << *a.equal_range(10).first << std::endl;
	std::cout << *a.equal_range(10).second << std::endl;

	std::cout << *a.equal_range(5).first << std::endl;
	std::cout << *a.equal_range(5).second << std::endl;

	std::cout << *a.equal_range(20).first << std::endl;
	std::cout << *a.equal_range(20).second << std::endl;

	std::cout << *a.equal_range(1).first << std::endl;
	std::cout << *a.equal_range(1).second << std::endl;

	std::cout << *a.equal_range(18).first << std::endl;
	std::cout << *a.equal_range(18).second << std::endl;

	std::cout << *a.equal_range(12).first << std::endl;
	std::cout << *a.equal_range(12).second << std::endl;


	std::cout << *a.equal_range(3).first << std::endl;
	std::cout << *a.equal_range(3).second << std::endl;

	std::cout << *a.equal_range(4).first << std::endl;
	std::cout << *a.equal_range(4).second << std::endl;

	ft::pair<ft::set<int>::const_iterator , ft::set<int>::const_iterator> pr =  a.equal_range(4);
	std::cout << *pr.first << std::endl;

	const ft::pair<ft::set<int>::const_iterator , ft::set<int>::const_iterator> pr2 =  a.equal_range(4);
	std::cout << *pr2.first << std::endl;
}

void testComparators(){
	ft::set<int, mycomp> a;
	a.insert(5);
	a.insert(10);
	a.insert(56);
	a.insert(78);
	a.insert(2);
	a.insert(708);
	a.insert(5656);
	a.insert(1);
	a.insert(-1001);
	a.insert(12);

	for (ft::set<int>::iterator it = a.begin(); it != a.end(); it++){
		std::cout << *it << std::endl;
	}
}


int main(){
	testGeneral();
	testCapacity();
	testDelete();
	testLookUp();
	testComparators();
}
