#include "../header/ARGBase.h"
#include "../header/Colon.h"
#include "../header/Or.h"
#include "../header/And.h"
#include "../header/User_Cmnds.h"
#include "../header/Connector.h"
#include "../header/parser.h"



#include "../googletest/googletest/include/gtest/gtest.h"


TEST(ARGBaseObj, testingORConnector ){
    Or test = Or();
    string val = test.getARGValue();
    EXPECT_EQ( val , "||");
}
TEST(ARGBaseObj, testingANDConnector ){
    And test = And();
    string val = test.getARGValue();
    EXPECT_EQ( val , "&&");
}
TEST(ARGBaseObj, testingCOLONConnector ){
    Colon test = Colon();
    string val = test.getARGValue();
    EXPECT_EQ( val , ";");
    
}

TEST(ARGBaseObj, testingUser ){
    User_Cmnds test = User_Cmnds("hai");
    string val = test.getARGValue();
    EXPECT_EQ( val , "hai");
}
// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }

