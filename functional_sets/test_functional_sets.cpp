// test min
#include <gtest/gtest.h>
#include "functional_sets.h"
using namespace std;
class TestFunctionalSets : public ::testing::Test{
protected:
	Set s1,s2,s3;
public:
	TestFunctionalSets() {
		s1=singletonSet(1);
		s2=singletonSet(2);
		s3=singletonSet(3);
	}
	
};

// global !! ugh :)
int total=0;
void add_to_total(int& i) { total+=i;}

TEST_F(TestFunctionalSets,singletonSet) {
	ASSERT_TRUE(contains(s1,1));
	ASSERT_TRUE(contains(s2,2));
	ASSERT_TRUE(!contains(s1,2));
	ASSERT_TRUE(!contains(s2,1));	
}

// union is a keyword in C++, so using set_union :)
TEST_F(TestFunctionalSets,set_union) {
	Set s=set_union(s1,s2);
	ASSERT_TRUE(contains(s,1));
	ASSERT_TRUE(contains(s,2));
	ASSERT_TRUE(!contains(s,3));
	s=set_union(s,s3);
	ASSERT_TRUE(contains(s,1));
	ASSERT_TRUE(contains(s,2));
	ASSERT_TRUE(contains(s,3));
}


TEST_F(TestFunctionalSets,set_intersection) {
	Set s=set_intersection(s1,s2);
	ASSERT_TRUE(!contains(s,1));
	ASSERT_TRUE(!contains(s,2));

	s=set_intersection(set_union(s1,s2),set_union(s2,s3));
	ASSERT_TRUE(!contains(s,1));
	ASSERT_TRUE(contains(s,2));
	ASSERT_TRUE(!contains(s,3));
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
