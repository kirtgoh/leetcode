#include <gtest/gtest.h>
#include <Reverse_Integer.h>

class ReverseInteger : public :: testing :: Test
{
public:
  Solution slu;
  ReverseInteger()
  {
  }

  void TearDown()
  {
  }
  
};

TEST_F(ReverseInteger, reverse)
{
  ASSERT_EQ(slu.reverse(123), 321);
  ASSERT_EQ(slu.reverse(-123), -321);

  ASSERT_EQ(slu.reverse(100), 1);
  // overflow test 
  // ASSERT_EQ(slu.reverse(1000000003), 3000000001);
}
