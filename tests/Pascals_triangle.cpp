#include <gtest/gtest.h>

#include <Pascals_Triangle.h>

class PascalsTriangleTest : public :: testing :: Test
{
public:
  Solution slu;

};

TEST_F(PascalsTriangleTest, generate)
{

	vector<vector<int> > tri = slu.generate(5);
	// for (size_t i = 0; i < tri.size(); i++)
	// {
	// 	for (size_t j = 0; j < tri[i].size(); j++)
	// 	{
	// 		cout << tri[i][j] << " ";	
	// 	}
	// 	cout << endl;
	// 		
	// }
	
}

