#include "solution.h"
#include <algorithm>

void Solution::reverseWords(string &s)
{
  string rs;
  for (int i = s.length() - 1; i >= 0; --i)
  {
    // skip whitespaces
    while(i >= 0 && s[i] == ' ') --i;
    if (i < 0) break;

    // get a word, and reverse it
    string t;
    while(i >= 0 && s[i] != ' ') t.push_back(s[i--]);
    reverse(t.begin(), t.end());

    if (!rs.empty()) rs.push_back(' ');
    rs.append(t);
  }
  s = rs;
}

