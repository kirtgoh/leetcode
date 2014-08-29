/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 18, 2014
 *  Problem:     	Word Ladder
 *  Difficulty:  	Difficult	
 *  Source:      	https://oj.leetcode.com/problems/word-ladder/Notes/
 *
 *  Notes:
 * 	Given two words (start and end), and a dictionary, find the length of
 * 	shortest transformation sequence from start to end, such that:
 *
 * 	Only one letter can be changed at a time
 * 	Each intermediate word must exist in the dictionary
 * 	For example,
 *
 * 	Given:
 * 	start = "hit"
 * 	end = "cog"
 * 	dict = ["hot","dot","dog","lot","log"]
 * 	As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * 	return its length 5.
 *
 * 	Note:
 * 	Return 0 if there is no such transformation sequence.
 * 	All words have the same length.
 * 	All words contain only lowercase alphabetic characters.
 *
 *  Solution: 		BFS
*********************************************************************************/

#ifndef WORD_LADDER_H
#define WORD_LADDER_H

#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict);
};

int Solution::ladderLength(string start, string end, unordered_set<string> &dict)
{

	queue<pair<string, int>> q;
	q.push(make_pair(start,1));

	while (!q.empty())
	{
		pair<string, int> front = q.front();
		q.pop();

		string word = front.first;
		// change every char on word, and see if match end
		// otherwise, if find in the dict, push it
		for (size_t i = 0; i < word.size(); i++)
		{
			char before = word[i];
			for (char c = 'a'; c <= 'z'; c++)
			{
				word[i] = c;
				if (word == end)
					return front.second + 1;
				if (dict.find(word) != dict.end())
				{
					q.push(make_pair(word, front.second + 1));
					dict.erase(word);
				}
			}
			word[i] = before;
		}
	}

	return 0;
}

#endif /* WORD_LADDER_H */

