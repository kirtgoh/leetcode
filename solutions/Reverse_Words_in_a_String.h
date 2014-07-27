//=====================================================================================
// Reverse_Words_in_a_String.h
//
// Copyright (C) 2014 Kirt Goh <kirtgoh@gmail.com>
//=====================================================================================
//
// Given an input string, reverse the string word by word.
//
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
//
// Clarification:
// What constitutes a word?
//
// A sequence of non-space characters constitutes a word.
// Could the input string contain leading or trailing spaces?
// Yes. However, your reversed string should not contain leading or trailing
// spaces.
//
// How about multiple spaces between two words?
//
// Reduce them to a single space in the reversed string.
//
#ifndef REVERSE_WORDS_H 
#define REVERSE_WORDS_H

#include <string>
#include <algorithm>  // std::reverse

using namespace std;

class Solution
{
public:
  // Given an input string, reverse the string word by word.
  void reverseWords(string &s);
};

#endif /* REVERSE_WORDS_H */
