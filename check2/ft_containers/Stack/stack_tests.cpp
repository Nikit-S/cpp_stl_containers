#include "stack.hpp"
#include <stack>
#include <string>

void separator(std::string str)
{
	std::cout << "\n----- " << str << " ------" << std::endl;
}

template <typename T>
void s (T &stck)
{
	std::cout << "Size: " << stck.size() << std::endl;
}

template <typename T>
std::string s (T *stck)
{
	std::cout << "Size: " << stck->size() << std::endl;
}

template <typename T>
void values (T stck)
{
	if (!stck.size())
		return ;
	T tmp = stck;
	
	while(tmp.size() > 0)
	{
		std::cout << tmp.top();
		if (tmp.size() > 1)
			std::cout << "\n";
		tmp.pop();
	}
	std::cout << std::endl;
}

void	testNonMember()
{
	separator("relations");
	
	
	ft::stack<int> foo; // three ints with a value of 100
	foo.push(100);
	foo.push(100);
	foo.push(100);
	ft::stack<int> bar ; // two ints with a value of 200
	bar.push(200);
	bar.push(200);
	ft::stack<int> tmp = foo;
	
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	
	separator("relations 2");
	foo = bar;
	bar = tmp;
	
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	
	separator("relations 3");
	foo = bar;
	
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}


int main ()
{
	ft::stack<char> stck_c;
	ft::stack<char> *stck_p = new ft::stack<char>;
	std::cout << stck_c.empty() << std::endl;
	stck_c.push('A');
	stck_c.push('A' + 1);
	stck_c.push('A' + 2);
	
	ft::stack<char> stck_c1 = stck_c;
	std::cout << stck_c1.empty() << std::endl;
	
	stck_c.pop();
	
	s(stck_c);
	std::cout << "TOP: " << stck_c.top() << " -> ";
	values(stck_c);
	
	s(stck_c1);
	std::cout << "TOP: " << stck_c1.top() << " -> ";
	values(stck_c1);
	
	*stck_p = stck_c1;
	s(*stck_p);
	std::cout << "TOP: " << stck_p->top() << " -> ";
	values(*stck_p);
	
	ft::stack<char> *stck_p2 = new ft::stack<char>;
	*stck_p2 = *stck_p;
	delete stck_p;
	s(*stck_p2);
	std::cout << "TOP: " << stck_p2->top() << " -> ";
	values(*stck_p2);
	delete stck_p2;
	
	testNonMember();
}
