#include <functional>
#include "functional_sets.h"

using namespace std;

// this function, when given a set, and an element, returns true if the element is in the set
// we can simply apply the set to the element, since the set is a function :)
bool contains(const Set&s, int elem) 
{
	return s(elem);
}

// this function creates and returns a set containing just one element
// notice we're returning a closure ! C++ 11 supports lambdas and closures ! yipee
Set singletonSet(int val) 
{
	return [=](int x){return x==val;} ;
}

// this function returns a new set, which is the union of its two parameters
// basically, we return a new function /closure which checks whether the element is in either of the two sets
Set set_union(Set s1, Set s2)
{
	return [=](int x){return contains(s1,x) || contains(s2,x);};
}

// this function returns a new set, which is the intersection of its two parameters
// basically, we return a new function /closure which checks whether the element is in BOTH of the two sets
Set set_intersection(Set s1, Set s2)
{
	return [=](int x){return contains(s1,x) && contains(s2,x);};	
}

// this function returns true if the predicate is true for every element in the set
// notice that, since we can't get a list of all elements in the set, we need to use a 'grounding' set
// in this case, we use [-1000,1000] as the grounding set
bool foreach(Set s, Predicate p)
{
	for(unsigned i=-1000; i<=1000;++i) {
		if(contains(s,i) && !p(i))
			return false;
	}
	return true;
}

bool exists(Set s, Predicate p) 
{
	Predicate notP=[=](int x){return !p(x);};	
	return !foreach(s,notP);
}


