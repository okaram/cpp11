#include <memory>
#include <iostream>
#include "conslist_tpt.h"

using namespace std;
template<class T>
unsigned len(const ConsList<T>&l)
{
	if(!isEmpty(l))
		return 0;
	return 1+len(cdr(l));
}


int main(void)
{
	ConsList<int> l=cons(3,cons(4,cons(7)));
	ConsList<int> l2=cons(9,l); // l2 shares the last few elements with l !
	cout << car(l) << car(cdr(l)) << endl;
	cout << len(l) << endl;
	cout << l << endl;
	cout << l2 << endl;
}
