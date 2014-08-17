/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 16, 2014
 *  Problem:     	Palindrome Partitioning
 *  Difficulty:  	Difficult
 *  Source:      	https://oj.leetcode.com/problems/palindrome-partitioning/
 *
 *  Notes:
 * 	Given a string s, partition s such that every substring of the partition is
 * 	a palindrome.
 *
 * 	Return all possible palindrome partitioning of s.
 *
 * 	For example, given s = "aab",
 * 	Return
 *
 * 	  [
 * 	    ["aa","b"],
 * 	    ["a","a","b"]
 * 	  ]
 *
 *  Solution: 		
*********************************************************************************/

#ifndef PALINDROME_PARTITION_H
#define PALINDROME_PARTITION_H

#include <vector>
#include <string>
#include <iostream>
#include <PrintMacros.h>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s);
    bool isPalindrome(string s);
    void dfs(string s, size_t start,vector<vector<bool> > map ,vector<string> part, vector<vector<string> > &result);
};

vector<vector<string> > Solution::partition(string s)
{
    // setp-1: map[i][j]  = true ( s[i] --> s[j] is palindrom)
    int N = s.size();
    vector<vector<bool> > map(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (isPalindrome(s.substr(i, j - i + 1)))
                map[i][j] = true;
        }
    }

    // setp-2: construct all possible part, eg. {'a,'a','b'} is one of partition
    vector<string> part;
    vector<vector<string> > result;
    dfs(s, 0, map, part, result);

    return result;
}

void Solution::dfs(string s, size_t start, vector<vector<bool> > map ,vector<string> part, vector<vector<string> > &result)
{
    if (start == s.size())
    {
        result.push_back(part);
        return;
    }

    for (size_t j = start; j < s.size(); j++)
    {
        if (map[start][j])
        {
            // PRINT("find map[" << start << "][" << j << "]");
            part.push_back(string(s.substr(start, j - start + 1)));
            dfs(s, j + 1, map, part, result);
            part.pop_back();
        }
    }
}

bool Solution::isPalindrome(string s)
{
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j]) return false;
        i++; j--;
    }

    return true;
}

#endif /* PALINDROME_PARTITION_H */
