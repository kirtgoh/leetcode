/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Jul 29, 2014
 *  Problem:      Reverse an Integer	
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/reverse-integer
 *
 *  Notes:
 * 	Reverse digits of an integer.
 *
 * 	Example1: x = 123, return 321
 * 	Example2: x = -123, return -321
 *
 * 	Have you thought about this?
 * 	Here are some good questions to ask before coding. Bonus points for you if
 * 	you have already thought through this!
 *
 * 	If the integer's last digit is 0, what should the output be? ie, cases such
 * 	as 10, 100.
 *
 * 	Did you notice that the reversed integer might overflow? Assume the input is
 * 	a 32-bit integer, then the reverse of 1000000003 overflows. How should you
 * 	handle such cases?
 *
 * 	Throw an exception? Good, but what if throwing an exception is not an
 * 	option? You would then have to re-design the function (ie, add an extra
 * 	parameter).
 *
 *  Solution: 		
*********************************************************************************/

#ifndef REVERSE_INTEGER_H
#define REVERSE_INTEGER_H

class Solution {
public:
  int reverse(int x);
};

int Solution::reverse(int x)
{
  int ri = 0;
  while (x)
  {
    int t = x % 10;
    ri *= 10;
    ri += t;
    x /= 10;
  }

  return ri;
}

#endif /* REVERSE_INTEGER_H */
