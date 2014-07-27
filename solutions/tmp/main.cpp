#include <iostream>
#include <string>
#include "solution.h"

std::string str("a");

int main(int argc, char *argv[])
{
  Solution slu;
  slu.reverseWords(str);

  std::cout << str;

  return 0;
}
