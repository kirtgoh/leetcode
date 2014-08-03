/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 03, 2014
 *  Problem:      Find the Minimum Path Sum
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/triangle/
 *
 *  Notes:
 * 	Given a triangle, find the minimum path sum from top to bottom. Each step
 * 	you may move to adjacent numbers on the row below.
 *
 * 	For example, given the following triangle
 * 	[
 *       [2],
 *      [3,4],
 *     [6,5,7],
 *    [4,1,8,3]
 * 	]
 * 	The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * 	Note:
 * 	Bonus point if you are able to do this using only O(n) extra space,
 * 	where n is the total number of rows in the triangle.
 *
 *  Solution:
 *********************************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int> > &triangle);
};

int Solution::minimumTotal(vector<vector<int> > &triangle)
{
  for(int row = triangle.size() - 2; row >= 0; row--)
    for (int col = 0; col <= row; col++)
      triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);

  return triangle[0][0];
}

#endif /* TRIANGLE_H */

