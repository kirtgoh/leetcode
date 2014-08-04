/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 04, 2014
 *  Problem:     	find the maximum number of points
 *  Difficulty:  	Medium
 *  Source:      	https://oj.leetcode.com/problems/max-points-on-a-line/
 *
 *  Notes:
 * 	Given n points on a 2D plane, find the maximum number of points that lie on
 * 	the same straight line.
 *
 *  Solution:
*********************************************************************************/

#ifndef MAX_POINTS_H
#define MAX_POINTS_H

#include <point.h>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
  int maxPoints(vector<Point> &points);
};

int Solution::maxPoints(vector<Point> &points)
{
  int ret = 0;

  unordered_map<double, int> hash;
  // NOTE: veritcal situation, and duplicated points
  for (size_t i = 0; i < points.size(); i++)
  {
    hash.clear();
    double slope = 0.0; int vert = 0; int same = 0; int maximum = 0;

    for (size_t j = 0; j < points.size(); j++)
    {
      if (points[i].x == points[j].x)
      {
        if (points[i].y == points[j].y)
        {
          //refer itself and duplicated points
          same++;
        }
        else
        {
          vert++;
        }
      }
      // calculate slope
      else
      {
        slope = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);
        hash[slope]++;
        maximum = max(maximum, hash[slope]);
      }
    }
    ret = max(ret, max(maximum, vert) + same);
  }
  return ret;
}

#endif /* MAX_POINTS_H */
