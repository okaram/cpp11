#include <memory>
#include <iostream>
#include "conslist_toonew_tpt.h" // modify to include other versions if desired :)

using namespace std;

template<typename T>
unsigned len(const ConsList<T>&l)
{
	if(!isEmpty(l))
		return 0;
	return 1+len(cdr(l));
}

template<typename T>
T sum(const ConsList<T>& l)
{
	if(isEmpty(l))
		return 0;
	return car(l)+sum(cdr(l));
}

int main(void)
{
	ConsList<int> l=cons(3,cons(4,cons(7)));
	ConsList<int> l2=cons(9,cons(5,l)); // l2 shares the last 3 elements with l 
	ConsList<int> l3=cons(11,cdr(l2)); // l3 shares with l2, and also with l
	cout << car(l) << " " << car(cdr(l)) << endl;
	cout << len(l2) << " " << sum(l2) << endl;
	cout << l2 << endl;
	cout << l3 << endl;
}
