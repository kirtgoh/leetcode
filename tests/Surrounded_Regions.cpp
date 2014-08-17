#include <gtest/gtest.h>
#include <Surrounded_Regions.h>

class SurroundedRegionsTest : public :: testing :: Test
{
public:
    Solution slu;
    SurroundedRegionsTest() {}
};

TEST_F(SurroundedRegionsTest, solve)
{
    vector<vector<char>> board = {{'X','X','X','X'},
                                    {'X', 'O', 'O', 'X'},
                                    {'X', 'X', 'O', 'X'},
                                    {'X', 'O', 'X', 'X'}};

    slu.solve(board);

    // for (size_t i = 0; i < board.size(); i++)
    // {
    //    for (size_t j = 0; j < board[0].size(); j++)
    //    {
    //       cout << board[i][j] << ' '; 
    //    }
    //    cout << endl; 
    // }
    
}
