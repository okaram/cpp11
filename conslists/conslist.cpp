#include <memory>
#include <iostream>

template<typename T> class ConsNode;
template <typename T>
using ConsList= std::shared_ptr<ConsNode <T> >;

template<typename T>
T car(const ConsList<T>&l);

template<typename T>
const ConsList<T>& cdr(const ConsList<T>&l);

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
	return l;
}

template<class T>
unsigned len(const ConsList<T>&l)
{
	if(!l)
		return 0;
	return 1+len(cdr(l));
}

template<class T>
std::ostream& operator<<(std::ostream& o, const ConsList<T>&l)
{
	if(l)
		o << car(l) << " " << cdr(l);
	return o;
}
 
int main(void)
{
	ConsList<int> l=cons(3,cons(4,cons(7)));
	std::cout << car(l) << car(cdr(l)) << std::endl;
	std::cout << len(l) << std::endl;
	std::cout << l << std::endl;
}
