#include "solution.h"
#include <iostream>

int main(int argc, char *argv[])
{
  
  vector<string> vs;
  string str[] = {"2", "1", "+", "3", "*"};
  string str2[] = {"4", "13", "5", "/", "+"};
  for (size_t i = 0; i < 5; i++)
  {
    vs.push_back(str[i]);
  }
  
  Solution s;
  std::cout << s.evalRPN(vs) <<endl;
  return 0;
}
