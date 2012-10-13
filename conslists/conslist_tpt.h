#include <memory>
#include <iostream>

template<typename T> class ConsNode;
template<typename T> class ConsList;

/*
// will work with the new standard, need g++4.7 or better, avoiding for now
template <typename T>
using ConsList= std::shared_ptr<ConsNode <T> >;
*/

template<typename T>
T car(const ConsList<T>&l);

template<typename T>
const ConsList<T>& cdr(const ConsList<T>&l);
template<typename T>
ConsList<T> cons(T car) ;

template<typename T>
ConsList<T> cons(T car, const ConsList<T>& cdr) ;

template<class T>
bool isEmpty(const ConsList<T>&l);

template <typename T>
class ConsList {
public:
	operator bool() const {return (bool)list;}

private:
	// constructors
	ConsList(){}
	ConsList(const T& car) {
		list=std::make_shared<ConsNode<T> > (car);
	}
	ConsList(const T& car, const ConsList<T>&cdr) {
		list=std::make_shared<ConsNode<T> > (car,cdr);
	}
	
	//data
	std::shared_ptr<ConsNode<T> > list;

	// friends
	friend T car<>(const ConsList<T> &l);
	friend const ConsList<T>& cdr<>(const ConsList<T> &l);
	friend ConsList<T> cons<>(T car) ;
	friend ConsList<T> cons<>(T car, const ConsList<T>& cdr) ;	
	friend class ConsNode<T>;
	friend bool isEmpty<>(const ConsList<T>&);

};


template<typename T>
struct ConsNode {
public:
	ConsNode(T car, ConsList<T> cdr):_car(car),_cdr(cdr) {}
	ConsNode(T car):_car(car){}
private:
	T _car;
	ConsList<T> _cdr;

	friend T car<>(const ConsList<T> &l);
	friend const ConsList<T>& cdr<>(const ConsList<T> &l);
	friend ConsList<T> cons<>(T car, const ConsList<T>& cdr) ;
	friend class ConsList<T>;
	
};


template<typename T>
ConsList<T> cons(T car) {
	return ConsList<T>(car);
}

template<typename T>
ConsList<T> cons(T car, const ConsList<T>& cdr) {
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

