#include <iostream>
#include <map>
#include <functional>
using namespace std;

// factorial function
unsigned factorial(unsigned n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}

// naive fibonacci number function
unsigned fibo(unsigned n)
{
	if(n<=1)
		return n; 
	return fibo(n-1)+fibo(n-2);
}

unsigned fibo_memo(unsigned n)
{
	static map<unsigned,unsigned> memo;
	if(n<=1)
		return n;
	if(memo.count(n)>0)
		return memo[n];
	// otherwise
	unsigned ret=fibo_memo(n-1)+fibo_memo(n-2);
	memo[n]=ret;
	return ret;
}

template<class InType, class OutType>
std::function<OutType(InType)> memoize(std::function<OutType(InType)> foo)
{
	return [foo](InType n){
		static 	map<InType,OutType> memo;

		OutType ret;
		if(memo.count(n)>0) {
			ret =memo[n];
			return ret;
		}
		ret=foo(n);
		memo[n]=ret;
		return ret;
	};
}

std::function<unsigned(unsigned)> fibo1=[](unsigned n){
	if(n<=1)
		return n; 
	return fibo1(n-1)+fibo1(n-2);
};


int main(int argc, char*argv[])
{
	fibo1=memoize(fibo1);
	cout << argv[1] << " ->" << fibo1(atoi(argv[1])) << endl;
}
