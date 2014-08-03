#include <gtest/gtest.h>

#include <Triangle.h>

class TriangleTest : public :: testing :: Test
{
public:
  Solution slu;
  // TriangleTest();

};

TEST_F(TriangleTest, minimumTotal)
{
  vector<vector<int> > triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
  vector<vector<int> > triangle1 = {
                                    {-1},
                                    {2,3},
                                    {1,-1,-3}
                                   };

  ASSERT_EQ(slu.minimumTotal(triangle), 11);
  ASSERT_EQ(slu.minimumTotal(triangle1), -1);
}
