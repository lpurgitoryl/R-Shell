#include "../header/Parser.h"
#include <vector>
//#include "gtest/gtest.h"
#include "../googletest/googletest/include/gtest/gtest.h"
TEST(parser_vector_test,oneInput ){
	Parser parsse("$ wass");
	vector<ARGBase*> tokens = parsse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"wass");

}
TEST(parser_vector_test, twoInput ){
	Parser parsse("$ echo hello");
	vector<ARGBase*> tokens = parsse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.at(1)->getARGValue(),"hello");
	//EXPECT_EQ(tokens.at(2)->getARGValue(),"echo");

}
TEST(parser_vector_test,threeInput ){
	Parser parsse("$ echo sup my");
	vector<ARGBase*> tokens = parsse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.at(1)->getARGValue(),"sup");
	EXPECT_EQ(tokens.at(2)->getARGValue(),"my");

}
TEST(parser_vector_test,fourInput ){
	Parser parsse("$ echo sup my dude");
	vector<ARGBase*> tokens = parsse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.at(1)->getARGValue(),"sup");
	EXPECT_EQ(tokens.at(2)->getARGValue(),"my");
	EXPECT_EQ(tokens.at(3)->getARGValue(),"dude");

}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

