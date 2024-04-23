#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(StringCalculatorTestSuite,GivenEmptyStringZeroIsExpected){
    //Arrange
    StringCalculator objUnderTest;
    string input="";
    int expectedValue=0;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,GivenStringOneIsExpected){
    //Arrange
    StringCalculator objUnderTest;
    string input="1";
    int expectedValue=1;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,whenpassedmultiplecommadelimitednumbers){
    //Arrange
    StringCalculator objUnderTest;
    string input="1,2";
    int expectedValue=3;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,whendelimitedwithenewlineandcomma){
    //Arrange
    StringCalculator objUnderTest;
    string input="//;\n1;2";
    int expectedValue=3;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
//Data -> Parameterize -> (inputDataDrivenTestFixture:testing::Test
// Data Representation
//Value Provider -> Data Source
//How to pass data -> TestCase
#include "StringCalculator.h"
#include <gtest/gtest.h>
class DataDrivenTestFixture:public testing::Test{
  protected:
  StringCalculator objUnderTest;
 
};
class DataDriveTestFixtureWithParam:
                 public DataDrivenTestFixture,
                 public testing::WithParamInterface<std::tuple<string,int>>{
 
};
 INSTANTIATE_TEST_SUITE_P(
                          ValidInputDataSource,
                          DataDriveTestFixtureWithParam,
                           testing::Values(
                            std::make_tuple("",0),
                            std::make_tuple("0",0),
                            std::make_tuple("1,2",3),
                            std::make_tuple("1\n2,3",6)
                            ));
 
TEST_F(DataDrivenTestFixture,GivenEmptyStringZeroIsExpected){
   
    string input="";
    int expectedValue=10;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
 
TEST_P(DataDriveTestFixtureWithParam,ParameterizedTestCase){
    string input=std::get<0>(GetParam());
    int expectedValue=std::get<1>(GetParam());
    //Act
    int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
 
 
 
