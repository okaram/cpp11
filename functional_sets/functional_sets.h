#ifndef _FUNCTIONAL_SETS_H_
#define _FUNCTIONAL_SETS_H_
#include <functional>

// a set is a function, that when given an int tells me whether it's in the set
typedef std::function<bool(int)> Set;

// and a predicate is pretty much the same :) without the 'in' semantics :)
typedef std::function<bool(int)> Predicate;

// this function, when given a set, and an element, returns true if the element is in the set
// we can simply apply the set to the element, since the set is a function :)
bool contains(const Set&s, int elem) ;

// this function creates and returns a set containing just one element
// notice we're returning a closure ! C++ 11 supports lambdas and closures ! yipee
Set singletonSet(int val) ;

// this function returns a new set, which is the union of its two parameters
// basically, we return a new function /closure which checks whether the element is in either of the two sets
Set set_union(Set s1, Set s2);

// this function returns a new set, which is the intersection of its two parameters
// basically, we return a new function /closure which checks whether the element is in BOTH of the two sets
Set set_intersection(Set s1, Set s2);

// this function returns true if the predicate is true for every element in the set
// notice that, since we can't get a list of all elements in the set, we need to use a 'grounding' set
// in this case, we use [-1000,1000] as the grounding set
bool forall(Set s, Predicate p);

bool exists(Set s, Predicate p) ;


#endif
