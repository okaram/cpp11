#include <memory>
#include <iostream>

// forward declaration needed
template<typename T> class ConsNode;

template <typename T>
using ConsList= std::shared_ptr<ConsNode <T> >;


// we need to declare these, to allow us to make them friends of ConsNode
template<typename T>
T car(const ConsList<T>&l);

template<typename T>
const ConsList<T>& cdr(const ConsList<T>&l);

template<typename T>
struct ConsNode {
public:
	ConsNode(T car=T(), ConsList<T> cdr=ConsList<T>()):_car(car),_cdr(cdr) {}

private:
	T _car;
	ConsList<T> _cdr;
	friend T car<>(const ConsList<T> &l);
	friend const ConsList<T>& cdr<>(const ConsList<T> &l);	
};

template<typename T>
ConsList<T> cons(T car) {
	return std::make_shared<ConsNode<T> > (car);
}

template<typename T>
ConsList<T> cons(T car, const ConsList<T>& cdr) {
	return std::make_shared<ConsNode<T> > (car,cdr);
}

template<typename T>
T car(const ConsList<T>&l)
{
	return l->_car;
}

template<typename T>
const ConsList<T>& cdr(const ConsList<T>&l)
{
	return l->_cdr;
}

template<class T>
bool isEmpty(const ConsList<T>&l)
{
	return !l;
}


template<class T>
std::ostream& operator<<(std::ostream& o, const ConsList<T>&l)
{
	if(!isEmpty(l))
		o << car(l) << " " << cdr(l);
	return o;
}
 
