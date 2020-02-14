#include "../header/Parser.h"
#include "gtest/gtest.h"

TEST(parser_vector_test,oneInput ){
	Parser parse("$ wass");
	vector<ARGBase*> tokens = parse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"wass");

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

