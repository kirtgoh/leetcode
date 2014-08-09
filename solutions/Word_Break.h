/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 09, 2014
 *  Problem:     	Word Break
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/word-break/
 *
 *  Notes:
 * 	Given a string s and a dictionary of words dict, determine if s can be
 * 	segmented into a space-separated sequence of one or more dictionary words.
 *
 * 	For example, given
 * 	s = "leetcode",
 * 	dict = ["leet", "code"].
 *
 * 	Return true because "leetcode" can be segmented as "leet code".
 *
 *  Solution: 		
*********************************************************************************/

#ifndef WORD_BREAK_H
#define WORD_BREAK_H

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict);
};

bool Solution::wordBreak(string s, unordered_set<string> &dict)
{
  size_t N = s.size();
  vector<bool> canBreak(N + 1, false);

  canBreak[0]= true;
  for (size_t i = 1; i <= N; i++)
  { // Test if 1..N th letter can break
    for (size_t j = 0; j < i; j++)
    { // If j can break, test if j..i can break, j (0..i-1)
      // NOTE: i is 1..N, pos is 0..N-1
      if (canBreak[j] && dict.find(s.substr(j, i-j)) != dict.end()) 
      {
        canBreak[i] = true; break;
      }
    }
  }
  return canBreak[N];
}

#endif /* WORD_BREAK_H */
