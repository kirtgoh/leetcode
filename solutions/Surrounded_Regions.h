/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 17, 2014
 *  Problem:        Surrounded Regions	
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/surrounded-regions/
 *
 *  Notes:
 * 	Given a 2D board containing 'X' and 'O', capture all regions surrounded by
 * 	'X'.
 *
 * 	A region is captured by flipping all 'O's into 'X's in that surrounded
 * 	region.
 *
 * 	For example,
 * 	X X X X
 * 	X O O X
 * 	X X O X
 * 	X O X X
 * 	After running your function, the board should be:
 *
 * 	X X X X
 * 	X X X X
 * 	X X X X
 * 	X O X X
 *
 *  Solution: 		
*********************************************************************************/

#ifndef SURROUNDED_REGIONS_H
#define SURROUNDED_REGIONS_H

#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board);
    void dfs(int row, int col, vector<vector<char>> &board);
};

void Solution::solve(vector<vector<char>> &board)
{
    if (board.size() == 0 || board[0].size() == 0) return;

    int top = 0;
    int bottom = board.size() - 1;
    int left = 0;
    int right = board[0].size() - 1;

    for (int col = left; col <= right; col++)
    {
        dfs(top, col, board);
        dfs(bottom, col, board);
    }
    
    for (int row = top; row <= bottom; row++)
    {
        dfs(row, left, board);
        dfs(row, right, board);
    }

    for (int row = top; row <= bottom; row++)
    {
        for (int col = left; col <= right; col++)
        {
            if (board[row][col] == 'O') board[row][col] = 'X';
            if (board[row][col] == '+') board[row][col] = 'O';
        }
    }
}

void Solution::dfs(int row, int col, vector<vector<char>> &board)
{
    int top = 0;
    int bottom = board.size() - 1;
    int left = 0;
    int right = board[0].size() - 1;

    if (row < top || row > bottom || col < left || col > right) return;
    if (board[row][col] != 'O') return;

    board[row][col] = '+';
    dfs(row - 1, col, board);
    dfs(row + 1, col, board);
    dfs(row, col - 1, board);
    dfs(row, col + 1, board);
}

#endif /* SURROUNDED_REGIONS_H */
