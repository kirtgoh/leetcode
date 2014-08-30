/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 30, 2014
 *  Problem:     	Valid Palindrome
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/valid-palidrome/
 *
 *  Notes:
 * 	Given a string, determine if it is a palindrome, considering only
 * 	alphanumeric characters and ignoring cases.
 *
 * 	For example,
 * 	"A man, a plan, a canal: Panama" is a palindrome.
 * 	"race a car" is not a palindrome.
 *
 * 	Note:
 * 	Have you consider that the string might be empty? This is a good question to
 * 	ask during an interview.
 *
 * 	For the purpose of this problem, we define empty string as valid palindrome.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef VALID_PALINDROME_H
#define VALID_PALINDROME_H

#include <string>
// #include <cctype> isalnum(), isupper() and tolower() be better.

using namespace std;

class Solution {
public:
	bool isPalindrome1(string s);
};

// gtest name duplicated
bool Solution::isPalindrome1(string s)
{
	// setp-1: trim the string
	// NOTE: not necessary
	string trim;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]) || isdigit(s[i]))
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				trim.push_back(s[i] - ('Z' - 'z'));
			else
				trim.push_back(s[i]);
		}
	}

	int i = 0;
	int j = trim.length() - 1;

	while (i < j)
	{
		if (trim[i] != trim[j]) return false;
		i++;
		j--;
	}

	return true;
	
}

#endif /* VALID_PALINDROME_H */
