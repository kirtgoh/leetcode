#include "solution.h"
#include <stack>
#include <cstdlib>

int Solution::evalRPN(vector<string> &tokens)
{
  std::stack<int> s;
  int result = 0;

  for (size_t i = 0; i < tokens.size(); i++)
  {
    int op1, op2;
    if (tokens[i] == "+")
    {
      op1 = s.top();
      s.pop();

      op2 = s.top();
      s.pop();

      s.push(op1 + op2);
    }
    else if (tokens[i] == "-")
    {
      op1 = s.top();
      s.pop();

      op2 = s.top();
      s.pop();

      s.push(op2 - op1);
      
    }
    else if (tokens[i] == "*")
    {
      op1 = s.top();
      s.pop();

      op2 = s.top();
      s.pop();

      s.push(op1 * op2);
      /* else */
    }
    else if (tokens[i] == "/")
    {
      op1 = s.top();
      s.pop();

      op2 = s.top();
      s.pop();

      s.push(op2 / op1);
    }
    else
      s.push(atoi(tokens[i].c_str()));
  }

  result = s.top();
  return result;
}
