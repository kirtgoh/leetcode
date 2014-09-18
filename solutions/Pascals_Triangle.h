/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Sep 19, 2014
 *  Problem:     	Pascals Triangle
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/pascals-triangle/
 *
 *  Notes:
 * 	Given numRows, generate the first numRows of Pascal's triangle.
 *
 * 	For example, given numRows = 5,
 * 	Return
 *
 * 	[
 * 	     [1],
 * 	    [1,1],
 * 	   [1,2,1],
 * 	  [1,3,3,1],
 * 	 [1,4,6,4,1]
 * 	]
 *
 *  Solution: 		
*********************************************************************************/

#ifndef PASCALS_TRIANGLE
#define PASCALS_TRIANGLE

#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows);
};

vector<vector<int> > Solution::generate(int numRows)
{
	vector<vector<int> > tri(numRows);

	for (int i = 0; i < numRows; i++)
	{
		tri[i].push_back(1);
		for (int j = 1; j < i; j++)
			tri[i].push_back(tri[i-1][j-1] + tri[i-1][j]);

		if (i >=1) tri[i].push_back(1);
	}

	return tri;
	
}

#endif /* PASCALS_TRIANGLE */
