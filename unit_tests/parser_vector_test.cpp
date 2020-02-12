#include "../header/Parser.h"
#include "gtest/gtest.h"

TEST(parser_vector_test,oneInput ){
    Parser parse("$ wass");
    string val;
    parse->cmndInput >> val;
     EXPECT_EQ();

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

