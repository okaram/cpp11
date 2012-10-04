#include <functional>
//#include <memory>
#include <iostream>
//#include <vector>
using namespace std;

typedef std::function<bool(int)> Set;
typedef std::function<bool(int)> Predicate;

Set singletonSet(int val) {
	return [=](int x){return x==val;} ;
}

bool contains(const Set&s, int elem) {return s(elem);}

// union is a reserved word in c++ :)
Set set_union(Set s1, Set s2)
{
	return [=](int x){return contains(s1,x) || contains(s2,x);};
}

Set set_intersection(Set s1, Set s2)
{
	return [&](int x){return contains(s1,x) && contains(s2,x);};	
}

bool foreach(Set s, Predicate p)
{
	for(unsigned i=-1000; i<=1000;++i) {
		if(contains(s,i) && !p(i))
			return false;
	}
	return true;
}

int main(void)
{
	Set s1=singletonSet(1);
	Set s2=singletonSet(2);
	Set un=set_union(s1,s2);
	Set in=set_intersection(s1,s2);
	std::cout << contains(un,1) << std::endl;
	std::cout << contains(in,1) << std::endl;
}
