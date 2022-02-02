#include "vector.hpp"

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

void testConstructors(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - Constructors"  << std::endl;

	ft::Vector<int> int_vector;
	std::cout << "Size: " << int_vector.size() << ", Capacity: " << int_vector.capacity() << std::endl;

	std::cout  << "\nFill without value\n";
	ft::Vector<int> fill_wout_value(10);
	std::cout << "Size: " << fill_wout_value.size() << ", Capacity: " << fill_wout_value.capacity() << std::endl;
	for (ft::Vector<int>::iterator it = fill_wout_value.begin(); it != fill_wout_value.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::cout  << "\nFill with value\n";
	ft::Vector<int> fill_with_value(20, 12);
	std::cout << "Size: " << fill_with_value.size() << ", Capacity: " << fill_with_value.capacity() << std::endl;
	for (ft::Vector<int>::iterator it = fill_with_value.begin(); it != fill_with_value.end(); it++)
		std::cout << *it << " ";



	std::cout << std::endl;

	std::cout  << "\nFill with range\n";
	ft::Vector<int>::iterator it_begin = fill_with_value.begin();
	ft::Vector<int>::iterator it_end = fill_with_value.end();
	it_begin++;
	it_begin++;
	it_begin++;

	ft::Vector<int> fill_with_range(it_begin, it_end);
	std::cout << "Size: " << fill_with_range.size() << ", Capacity: " << fill_with_range.capacity() << std::endl;
	for (ft::Vector<int>::iterator it = fill_with_range.begin(); it != fill_with_range.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::cout  << "\nCopy constructor\n";
	ft::Vector<int> copy_vector(fill_with_range);
	for (ft::Vector<int>::iterator it = copy_vector.begin(); it != copy_vector.end(); it++) {

		std::cout << *it << " ";
	}

	std::cout << std::endl;
}

void testIterators(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - Iterators"  << std::endl;
	std::cout  << "\nCopy and Assignation\n";

	ft::Vector<int> a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(90);
	a.push_back(34);
	a.push_back(12);
	a.push_back(67);
	a.push_back(93);
	a.push_back(25);
	a.push_back(89);
	a.push_back(545);
	a.push_back(781);
	a.push_back(6321);
	a.push_back(88);

	ft::Vector<int>::iterator beginIt = a.begin();
	ft::Vector<int>::iterator endIt = a.end();

	ft::Vector<int>::iterator copyBeg = beginIt;
	ft::Vector<int>::iterator copyEnd(endIt);

	for (ft::Vector<int>::iterator it = copyBeg; it != copyEnd; it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - Base"  << std::endl;
	int *base = beginIt.base();
	std::cout << *base << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - Arithmetic Operatations"  << std::endl;

	std::cout << *(beginIt++) << std::endl;
	std::cout << *(++beginIt) << std::endl;
	std::cout << *(beginIt--) << std::endl;
	std::cout << *(--beginIt) << std::endl;
	std::cout << *(beginIt + 2) << std::endl;
	std::cout << *(2 + beginIt) << std::endl;
	std::cout << *(beginIt - 1) << std::endl;
	beginIt -= 1;
	std::cout << *(beginIt) << std::endl;
	beginIt += 3;
	std::cout << *(beginIt) << std::endl;
	std::cout << endIt - beginIt << std::endl;
	std::cout << beginIt[1] << std::endl;

	std::cout << endIt - beginIt << std::endl;

	if (beginIt > endIt)
		std::cout << "begin > end" << std::endl;
	if (beginIt >= endIt)
		std::cout << "begin >= end" << std::endl;
	if (beginIt < endIt)
		std::cout << "begin < end" << std::endl;
	if (beginIt <= endIt)
		std::cout << "begin <= end" << std::endl;
	if (beginIt == endIt)
		std::cout << "begin == end" << std::endl;
	if (beginIt != endIt)
		std::cout << "begin != end" << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - Const Iterator"  << std::endl;


	for (ft::Vector<int>::const_iterator it = a.begin(); it != a.end(); it++){
		std::cout << *(it) << std::endl;
//		*(it) = 10;  // our iterator is const, so we can not modify it
	}

	std::cout  << "- - - - - - - - - - - - - - - - - - - Reverse Iterator"  << std::endl;

	ft::Vector<int>::reverse_iterator reverseBeginIt = a.rbegin();
	ft::Vector<int>::reverse_iterator reverseEndIt = a.rend();

	for(ft::Vector<int>::reverse_iterator rIt = a.rbegin(); rIt != a.rend(); rIt++)
		std::cout << *rIt << " " << std::endl;

	std::cout << std::endl;

	std::cout << *(reverseBeginIt++) << std::endl;
	std::cout << *(++reverseBeginIt) << std::endl;
	std::cout << *(reverseBeginIt + 2) << std::endl;
	std::cout << *(reverseBeginIt - 1) << std::endl;
	std::cout << *(2 + reverseBeginIt) << std::endl;
	std::cout << *reverseBeginIt++ << std::endl;

	if (reverseBeginIt > reverseEndIt)
		std::cout << "begin > end" << std::endl;
	if (reverseBeginIt >= reverseEndIt)
		std::cout << "begin >= end" << std::endl;
	if (reverseBeginIt < reverseEndIt)
		std::cout << "begin < end" << std::endl;
	if (reverseBeginIt <= reverseEndIt)
		std::cout << "begin <= end" << std::endl;
	if (reverseBeginIt == reverseEndIt)
		std::cout << "begin == end" << std::endl;
	if (reverseBeginIt != reverseEndIt)
		std::cout << "begin != end" << std::endl;

	std::cout << reverseEndIt - reverseBeginIt << std::endl;
	std::cout << *reverseBeginIt << std::endl;
	std::cout << *reverseEndIt << std::endl;
	std::cout << reverseBeginIt[2] << std::endl;
	std::cout << reverseBeginIt[1] << std::endl;
	std::cout << reverseBeginIt[4] << std::endl;
	std::cout << reverseEndIt[4] << std::endl;
	std::cout << reverseEndIt[2] << std::endl;
	std::cout << reverseEndIt[1] << std::endl;
	std::cout << reverseEndIt[0] << std::endl;
	std::cout << *reverseEndIt.base().base() << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - Const Reverse Iterator"  << std::endl;

//	ft::Vector<int>::const_reverse_iterator constReverseBeginIt = a.rbegin();
//	ft::Vector<int>::const_reverse_iterator constReverseEndIt = a.rend();

	for(ft::Vector<int>::const_reverse_iterator constRevIt = a.rbegin(); constRevIt != a.rend(); constRevIt++) {
//		*constRevIt = 1;
		std::cout << *constRevIt << " ";
	}
	std::cout << std::endl;
}

void testPushBack(){
	ft::Vector<int> a;

	for (int i=0; i < 10000000; i++)
		a.push_back(i);

	for (ft::Vector<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void testElementAcess(){

	std::cout  << "- - - - - - - - - - - - - - - - - - - .at()"  << std::endl;

	ft::Vector<std::string> strs;
	strs.push_back("abs");
	strs.push_back("aahs");
	strs.push_back("askjnajs");
	strs.push_back("aasjbhjas");
	strs.push_back("ejajnk");
	strs.push_back("askajnjasnj");

	std::cout << strs.at(0) << std::endl;
	std::cout << strs.at(1) << std::endl;
	std::cout << strs.at(2) << std::endl;
	std::cout << strs.at(3) << std::endl;
	std::cout << strs.at(4) << std::endl;
	std::cout << strs.at(5) << std::endl;
	try{
		std::cout << strs.at(6) << std::endl;
	}catch (std::exception &ex){

	}

	const ft::Vector<int> a(10);
	const int const_ref = a.at(2);
	std::cout << const_ref << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - [])"  << std::endl;

	strs[2] = "modified";
	for (ft::Vector<std::string>::iterator it = strs.begin(); it != strs.end(); it++)
		std::cout << *it << std::endl;

	std::cout << strs[0] << std::endl;
	std::cout << strs[1] << std::endl;
	std::cout << strs[2] << std::endl;
	std::cout << strs[3] << std::endl;
	std::cout << strs[4] << std::endl;
	std::cout << strs[5] << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - frond & back"  << std::endl;

	std::cout << strs.front() << std::endl;
	std::cout << a.front() << std::endl;
	std::cout << strs.back() << std::endl;
	std::cout << a.back() << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - data"  << std::endl;

	//std::cout << *strs.data() << std::endl;
	//std::cout << *a.data()<< std::endl;

	//ft::Vector<int> empty;
	//std::cout << empty.data() << std::endl;


}

void testCapacity(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - empty"  << std::endl;
	ft::Vector<int> a;
	ft::Vector<int> b;
	ft::Vector<int> c(100);
	a.push_back(1);
	std::cout << a.empty() << std::endl;
	std::cout << b.empty() << std::endl;
	std::cout << c.empty() << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - size & capacity & max size"  << std::endl;

	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a.max_size() << std::endl;
	std::cout << b.size() << std::endl;
	std::cout << b.max_size() << std::endl;
	std::cout << b.capacity() << std::endl;
	std::cout << c.size() << std::endl;
	std::cout << c.max_size() << std::endl;
	std::cout << c.capacity() << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - reserve"  << std::endl;
	a.reserve(100);
	std::cout << a.capacity() << std::endl;
	b.push_back(10);
	b.push_back(20);
	b.push_back(30);
	b.push_back(40);
	b.reserve(2);
	for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	b.reserve(200);
	for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;


}

void testModifiers(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - clear"  << std::endl;

	ft::Vector<int> a;
	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);

	a.clear();
	for (ft::Vector<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
	std::cout << a.size() << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - insert"  << std::endl;
	// 1 element

	a.push_back(10);
	a.push_back(11);
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
	a.push_back(15);
//	a.push_back(15);
//	a.push_back(15);

	ft::Vector<int>::iterator it = a.begin();
	it += 2;

	std::cout << a.capacity() << std::endl;
	std::cout << *a.insert(it, 90) << std::endl;
	std::cout << a.capacity() << std::endl;

	for (ft::Vector<int>::iterator it = a.begin(); it != a.end(); it ++)
		std::cout << *it << std::endl;

	ft::Vector<int> b(1000);

	for (int i = 0; i < 1000; i++)
		b.push_back(i);

	ft::Vector<int>::iterator itB = b.begin();
	itB += 400;
	std::cout << *b.insert(itB, 9999) << std::endl;

	for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;


	//count
	ft::Vector<int>::iterator itB2 = b.begin();

	b.insert(itB2, 5, 20);
	for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;


	//range
	a.clear();
	for (int i = 0; i < 250; i++)
		a.push_back(i);

	b.clear();
	for (int i = 300; i < 500; i++)
		b.push_back(i);

	ft::Vector<int>::iterator first = b.begin();
	ft::Vector<int>::iterator last = b.end();
	ft::Vector<int>::iterator pos = a.begin();

	a.insert(pos+4, first + 10, last);
	for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	std::cout << *a.erase(a.begin() + 10) << std::endl;
	for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "here\n";
	std::cout << *a.erase(a.begin() + 10, a.end() - 100) << std::endl;
	for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	std::cout << *a.erase(a.begin(), a.end()) << std::endl;
	for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	//push back

	ft::Vector<int> y;
	for (int i = 0; i < 1000; i++){
		y.push_back(i);
		std::cout << y.size() << " ";
		std::cout << y.capacity() << std::endl;
	}

	for (ft::Vector<int>::iterator it = y.begin(); it != y.end(); it++)
		std::cout << *it << std::endl;


	for (int i = 0; i < 300; i++){
		y.pop_back();
		std::cout << y.size() << " ";
		std::cout << y.capacity() << std::endl;
	}

	for (ft::Vector<int>::iterator it = y.begin(); it != y.end(); it++)
		std::cout << *it << std::endl;

	// resize

	y.resize(10, 777);
	for (ft::Vector<int>::iterator it = y.begin(); it != y.end(); it++)
		std::cout << *it << std::endl;

	y.resize(100, 777);
	for (ft::Vector<int>::iterator it = y.begin(); it != y.end(); it++)
		std::cout << *it << std::endl;


	//assign

	y.assign(10, 90);
	for (ft::Vector<int>::iterator it = y.begin(); it != y.end(); it++)
		std::cout << *it << std::endl;

	ft::Vector<int> x;
	for (int i = 0; i < 1000; i++)
		x.push_back(i);

	y.assign(x.begin() + 100, x.end() - 100);

	for (ft::Vector<int>::iterator it = y.begin(); it != y.end(); it++)
		std::cout << *it << std::endl;


}

void 	testOperators(){
	ft::Vector<int> a;
	a.push_back(12);
	a.push_back(13);
	a.push_back(14);

	ft::Vector<int> b;
	b.push_back(12);
	b.push_back(13);
	b.push_back(14);

	if (a == b)
		std::cout << "a == b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;

}

int main() {

	testConstructors();
	testIterators();
	testElementAcess();
	testCapacity();
	testModifiers();
	testOperators();
}
