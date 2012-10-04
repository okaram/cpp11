// test min
#include <gtest/gtest.h>
#include <vector>
#include "vector_funcs_extra.h"
#include <stdexcept>

using namespace std;
class MyTest : public ::testing::Test{};

// global !! ugh :)
int total=0;
void add_to_total(int& i) { total+=i;}


TEST_F(MyTest,apply_all) {
	vector<int> v{1,3,3};
	total=0;
	apply_all(v,add_to_total);
	ASSERT_EQ(7,total);
}

TEST_F(MyTest,apply_all_lambda) {
	vector<int> v{10,3,3};
	total=0;
	apply_all(v,[](int& i) {total+=i; return;}); // can't capture, since type of lambda w/capture is NOT func pointer :(, not sure if portable
	ASSERT_EQ(16,total);
}


TEST_F(MyTest,map) {
	vector<int> v {10,20,30};
	vector<int> v2=map(v,[](int i){return 2*i;});
	
	ASSERT_EQ(20,v2[0]);
	ASSERT_EQ(40,v2[1]);
	ASSERT_EQ(60,v2[2]);
}

int add(int i,int j) {return i+j;}
TEST_F(MyTest,reduce) {
	vector<int> v {10,20,30};
	ASSERT_EQ(60, reduce(v,0, [](int i,int j){return i+j;}    ));
}

int main(int argc, char **argv) 
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
