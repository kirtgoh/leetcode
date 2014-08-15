/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 13, 2014
 *  Problem:     	Minimum candies you give
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/
 *
 *  Notes:
 *  There are N children standing in a line. Each child is assigned a rating
 *  value.
 *
 *  You are giving candies to these children subjected to the following
 *  requirements:
 *
 *  Each child must have at least one candy.
 *  Children with a higher rating get more candies than their neighbors.
 *  What is the minimum candies you must give?	
 *
 *  Solution: 		
*********************************************************************************/

#ifndef CANDY_H
#define CANDY_H

#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings);
};

int Solution::candy(vector<int> &ratings)
{
    int N = ratings.size();

    vector<int> l2r(N, 0);
    vector<int> r2l(N, 0);

    l2r[0] = 1;
    for (int i = 1; i < N; i++)
    {
        if (ratings[i-1] < ratings[i])
            l2r[i] = l2r[i-1] + 1;
        else
            l2r[i] = 1;
    }

    r2l[N - 1] = 1;
    for (int j = N - 2; j >= 0 ; j--)
    {
        if (ratings[j] > ratings[j + 1])
            r2l[j] = r2l[j + 1] + 1;
        else
            r2l[j] = 1;
    }
    
    int min = 0;
    for (int m = 0; m < N; m++)
    {
        min += l2r[m] >= r2l[m] ? l2r[m] : r2l[m];
    }
    
    return min;
}

#endif /* CANDY_H */
