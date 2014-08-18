/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 17, 2014
 *  Problem:     	Longest Consecutive Sequence
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/longest-consecutive-sequence/
 *
 *  Notes:
 * 	Given an unsorted array of integers, find the length of the longest
 * 	consecutive elements sequence.
 *
 * 	For example,
 * 	Given [100, 4, 200, 1, 3, 2],
 * 	The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
 * 	length: 4.
 *
 * 	Your algorithm should run in O(n) complexity.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef LONGEST_CONSECUTIVE_SEQUENCE_H
#define LONGEST_CONSECUTIVE_SEQUENCE_H

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num);

};

int Solution::longestConsecutive(vector<int> &num)
{
	unordered_set<int> hash;	
	int max(0);

	// setup a hash table, except duplicated
	for (size_t i = 0; i < num.size(); i++)
	{
		if (hash.find(num[i]) == hash.end())
			hash.insert(num[i]);
	}

	// count number of greater and smaller than num[i]
	for (size_t i = 0; i < num.size(); i++)
	{
		int mi(0);
		if (hash.find(num[i]) != hash.end())
		{
			mi = 1;
			hash.erase(num[i]);

			int g = num[i] + 1;
			while (hash.find(g) != hash.end())
			{
				hash.erase(g);
				mi++;
				g++;
			}

			int s = num[i] - 1;
			while (hash.find(s) != hash.end())
			{
				hash.erase(s);
				mi++;
				s--;
			}

			if (mi > max) max = mi;
		}
	}
	
	return max;
}

#endif /* LONGEST_CONSECUTIVE_SEQUENCE_H */

