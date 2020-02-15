#include "../header/Parser.h"
#include "gtest/gtest.h"

TEST(parser_vector_test,oneInput ){
	Parser parse("$ wass");
	vector<ARGBase*> tokens = parse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"wass");

}
TEST(parser_vector_test, twoInput ){
	Parser parse("$ echo hello");
	vector<ARGBase*> tokens = parse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.at(1)->getARGValue(),"hello");
	//EXPECT_EQ(tokens.at(2)->getARGValue(),"echo");

}
TEST(parser_vector_test,threeInput ){
	Parser parse("$ echo sup my");
	vector<ARGBase*> tokens = parse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.at(1)->getARGValue(),"sup");
	EXPECT_EQ(tokens.at(2)->getARGValue(),"my");

}
TEST(parser_vector_test,fourInput ){
	Parser parse("$ echo sup my dude");
	vector<ARGBase*> tokens = parse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.at(1)->getARGValue(),"sup");
	EXPECT_EQ(tokens.at(2)->getARGValue(),"my");
	EXPECT_EQ(tokens.at(2)->getARGValue(),"dude");

}
TEST(parser_vector_test, noInput ){
	Parser parse("$ \n");
	vector<ARGBase*> tokens = parse.parse();
	//EXPECT_EQ(tokens.at(0) == null,0);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

