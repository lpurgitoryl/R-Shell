#include "../header/Parser.h"
#include <vector>
//#include "gtest/gtest.h"
#include "../googletest/googletest/include/gtest/gtest.h"

TEST(parser_vector_test2, oneConnectorINput ){
	Parser parsse("$ ||");
	vector<ARGBase*> tokens = parsse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"||");

}
TEST(parser_vector_test2, CommentInputSize){
	Parser parsse("$ echo # wass up");
	vector<ARGBase*> tokens = parsse.parse();

	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.size() , 1);
	//EXPECT_EQ(tokens.at(2)->getARGValue(),"echo");

}

TEST(parser_vector_test2, CommentInputInsideValue){
	Parser parsse("$ echo wass# up");
	vector<ARGBase*> tokens = parsse.parse();
	
	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.size() , 3);
	//EXPECT_EQ(tokens.at(2)->getARGValue(),"echo");

}
TEST(parser_vector_test2, inputsize1_withnewline ){
	Parser parsse("$ ls");
	vector<ARGBase*> tokens = parsse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"ls");
	EXPECT_EQ(tokens.size(), 1);

}
TEST(parser_vector_test2, size2_withcomment){
	Parser parsse("$ echo sup #my dude");
	vector<ARGBase*> tokens = parsse.parse();
	EXPECT_EQ(tokens.at(0)->getARGValue(),"echo");
	EXPECT_EQ(tokens.at(1)->getARGValue(),"sup");
	EXPECT_EQ(tokens.size() , 2);
	

}


// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }

