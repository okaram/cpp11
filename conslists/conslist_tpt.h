#include <memory>
#include <iostream>

template<typename T> class ConsNode;
template<typename T> class ConsList;

template <typename T>
class ConsList {
public:
	operator bool() const {return (bool)list;}

	// constructors
	ConsList(){}
	ConsList(const T& car, const ConsList<T>&cdr=ConsList<T>() ) {
		list=std::make_shared<ConsNode<T> > (car,cdr);
	}
	
	//data
	std::shared_ptr<ConsNode<T> > list;
};


template<typename T>
struct ConsNode {
public:
	ConsNode(T car, ConsList<T> cdr=ConsList<T>() ):_car(car),_cdr(cdr) {}
	
	T _car;
	ConsList<T> _cdr;
};


template<typename T>
ConsList<T> cons(T car) 
{
	return ConsList<T>(car);
}

template<typename T>
ConsList<T> cons(T car, const ConsList<T>& cdr) 
{
	return ConsList<T>(car,cdr);
}

template<typename T>
T car(const ConsList<T>&l)
{
	return l.list->_car;
}

template<class T>
bool isEmpty(const ConsList<T>&l)
{
	return l;
}

template<typename T>
const ConsList<T>& cdr(const ConsList<T>&l)
{
	return l.list->_cdr;
}

template<class T>
std::ostream& operator<<(std::ostream& o, const ConsList<T>&l)
{
	if(l)
		o << car(l) << " " << cdr(l);
	return o;
}

