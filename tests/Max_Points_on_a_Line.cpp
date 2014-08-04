#include <gtest/gtest.h>
#include <point.h>

#include <Max_Points_on_a_Line.h>

class MaxPointsOnLine : public :: testing :: Test
{
public:
  Solution slu;  
  MaxPointsOnLine() {}
};

TEST_F(MaxPointsOnLine, maxPoints)
{
  vector<Point> p1 = {Point(0,0),
                      Point(0,0)};

  vector<Point> p2 = {Point(84,250),
                      Point(0,0),
                      Point(1,0),
                      Point(0,-70),
                      Point(0,-70),
                      Point(1,-1),
                      Point(21,10),
                      Point(42,90),
                      Point(-42,-230)};

  vector<Point> p3= {Point(0,9),
                     Point(138,429),
                     Point(115,359),
                     Point(115,359),
                     Point(-30,-102),
                     Point(230,709),
                     Point(-150,-686),
                     Point(-135,-613),
                     Point(-60,-248),
                     Point(-161,-481),
                     Point(207,639),
                     Point(23,79),
                     Point(-230,-691),
                     Point(-115,-341),
                     Point(92,289),
                     Point(60,336),
                     Point(-105,-467),
                     Point(135,701),
                     Point(-90,-394),
                     Point(-184,-551),
                     Point(150,774),
                     Point(115,359),
                     Point(115,359)};

  ASSERT_EQ(slu.maxPoints(p1),2);
  ASSERT_EQ(slu.maxPoints(p2),6);
  ASSERT_EQ(slu.maxPoints(p3),14);
}
