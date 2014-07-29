/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Jul 29, 2014
 *  Problem:     	Reverse Polish Notation
 *  Difficulty:  	Easy
 *  Source:
 *  https://oj.leetcode.com/problems/evaluate-reverse-polish-notation
 *
 *  Notes:
 * 	Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * 	Valid operators are +, -, *, /. Each operand may be an integer or another
 * 	expression.
 *
 * 	Some examples:
 * 	  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * 	  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 *  Solution: 		
*********************************************************************************/

#ifndef REVERSE_POLISH_NOTATION_H
#define REVERSE_POLISH_NOTATION_H

#include <vector>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens);
};

int Solution::evalRPN(vector<string> &tokens)
{
  stack<int> s;

  for (size_t i = 0; i < tokens.size(); i++)
  {
    int op1, op2;
    if (tokens[i] == "+")
    {
      op1 = s.top(); s.pop();
      op2 = s.top(); s.pop();

      s.push(op2 + op1);
    }
    else if (tokens[i] == "-")
    {
      op1 = s.top(); s.pop();
      op2 = s.top(); s.pop();

      s.push(op2 - op1);
    }
    else if (tokens[i] == "*")
    {
      op1 = s.top(); s.pop();
      op2 = s.top(); s.pop();

      s.push(op2 * op1);
    }
    else if (tokens[i] == "/")
    {
      op1 = s.top(); s.pop();
      op2 = s.top(); s.pop();

      s.push(op2 / op1);
    }
    else
      s.push(atoi(tokens[i].c_str()));
  }

  return s.top();
}
#endif /* REVERSE_POLISH_NOTATION_H */
