/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Jul 27, 2014
 *  Problem:     	Reverse Words in a String
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/reverse-words-in-a-string/
 *
 *  Notes:
 *  Given an input string, reverse the string word by word.
 *  For example,
 *  Given s = "the sky is blue",
 *  return "blue is sky the".
 *
 *  Clarification:
 *  What constitutes a word?
 *  A sequence of non-space characters constitutes a word.
 *  Could the input string contain leading or trailing spaces?
 *  Yes. However, your reversed string should not contain leading or trailing
 *  spaces.
 *
 *  How about multiple spaces between two words?
 *  Reduce them to a single space in the reversed string.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef REVERSE_WORDS_H 
#define REVERSE_WORDS_H

#include <algorithm>  // std::reverse
#include <string>

using namespace std;

class Solution
{
public:
  void reverseWords(string &s);
};

void Solution::reverseWords(string &s)
{
    string rs; 
    for (int i = s.length() - 1; i >= 0; --i)                                                                                        
    {
      // skip whitespaces
      while(i >= 0 && s[i] == ' ')
          --i;
      if (i < 0) break;

      // get a word, and reverse it
      string t;
      while(i >= 0 && s[i] != ' ')
        t.push_back(s[i--]);
      reverse(t.begin(), t.end());

      if (!rs.empty())
          rs.push_back(' ');
      rs.append(t);
    }
    s = rs;
}

#endif /* REVERSE_WORDS_H */
