#include <iostream>
#include "functional_sets.h"

using namespace std;


void demo_union(void)
{
	Set s1=singletonSet(1);
	Set s2=singletonSet(2);
	Set s3=singletonSet(3);
	
	Set un=set_union(s1,s2);
	Set all=set_union(s1,set_union(s2,s3));

	cout << contains(s1,2) << endl; // this should print 0 (meaning false :)
	cout << contains(s2,2) << endl; // this should print 1 (meaning true :)
	cout << contains(all,3) << endl; // this should print 1 (meaning true :)
	
}

void demo_intersection(void) 
{
	Set s1=singletonSet(1);
	Set s2=singletonSet(2);
	Set s3=singletonSet(3);
	
	Set all=set_union(s1,set_union(s2,s3));
	Set s1b=set_intersection(all,s1); // back to s1, since it is the intersection of all=(s1 U s2 U s3)
	Set empty=set_intersection(s1,s2); // empty set !
	
	cout << contains(s1b,1) << endl; // what would this print ?
}

bool isOdd(int i) 
{
	return i%2!=0;
}


void demo_forall_exists(void)
{
	Set s1=singletonSet(1);
	Set s2=singletonSet(2);
	Set s3=singletonSet(3);
	
	Set all=set_union(s1,set_union(s2,s3));
	
	cout << forall(all,isOdd) << endl; // what would this print and why?
	cout << exists(all,isOdd) << endl; // what would this print and why?
}

int main(void)
{
	demo_union();
	demo_intersection();
	demo_forall_exists();
	
}
