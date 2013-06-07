#include <iostream>
#include <functional>
#include <set>
#include <string>
using namespace std;

//template<typename State_T> std::function<State_T(State_T,char)> delta_func;
/*
template <typename State_T>
struct fsm_types {
	typename std::function<State_T(State_T, char)> dfa_delta;
	
};
*/

template<typename State_T>
struct DFA {
	set<State_T> Q,F; // all states, and accepting states
	State_T q0; // the starting state
	set<char> sigma;
	std::function<State_T(State_T, char)> delta;
	
	DFA(set<State_T> p_Q,
		set<State_T> p_F, 
		State_T p_q0, 
		set<char> p_sigma,
		std::function<State_T(State_T, char)> p_delta
	): Q(p_Q), F(p_F),q0(p_q0),sigma(p_sigma), delta(p_delta) {}
	
	State_T delta_hat(State_T q, string str)
	{
		State_T theState=q;
		for(char c : str) {
			cout << "at " << theState << " seeing " << c ;
			theState=delta(theState,c);
			cout << " went to " << theState << endl;
		}
		return theState;
	}
	
	bool accepts(string str)
	{
		return contains(F,delta_hat(q0,str));
	}
};

template<typename T>
bool contains(const set<T>& all,const T& elem)
{
	return all.find(elem) != all.end();
}

template<typename State_T>
struct NFA {
	set<State_T> Q,F; // all states, and accepting states
	State_T q0; // the starting state
	set<char> sigma;
	std::function<set<State_T>(State_T, char)> delta;
	
	NFA(set<State_T> p_Q,
		set<State_T> p_F, 
		State_T p_q0, 
		set<char> p_sigma,
		std::function<State_T(set<State_T>, char)> p_delta
	): Q(p_Q), F(p_F),q0(p_q0),sigma(p_sigma), delta(p_delta) {}
	
/*
	set<State_T> delta_hat(State_T q, string str)
	{
		set<State_T> theStates={q};
		for(char c : str) {
			theState=delta(theState,c);
		}
		return theState;
	}
	
	bool accepts(string str)
	{
		return F.contains(delta_hat(q0,str));
	}
	*/
};

unsigned delta1(unsigned state, char input)
{
	if(state==0)
		if (input=='1')
			return 0;
		else // input=='0'
			return 1;
	else {// state==1
			return 1;
	}
}



int main(int argc, char* argv[])
{
	set<unsigned> Qs {0,1};
	set<unsigned> Fs {1};
	set<char> Sigma {'0','1'};
	
	DFA<unsigned> dfa1=DFA<unsigned>(Qs,Fs,0,Sigma,delta1);
	
	int from=atoi(argv[1]);
	string str(argv[2]);
	cout << dfa1.delta_hat(from,argv[2]) << endl;
	cout << boolalpha << dfa1.accepts(str) << endl;
}
