#include <gtest/gtest.h>
#include <Search_Insert_Position.h>

class SearchInsertPosition : public :: testing :: Test
{
public:
  Solution slu;
  SearchInsertPosition ()
  {
  }

};


TEST_F(SearchInsertPosition, searchInsert)
{
  int A[] = {1,3,5,6};

  ASSERT_EQ(slu.searchInsert(A,4,5), 2);
  ASSERT_EQ(slu.searchInsert(A,4,2), 1);
  ASSERT_EQ(slu.searchInsert(A,4,7), 4);
  ASSERT_EQ(slu.searchInsert(A,4,0), 0);
}
