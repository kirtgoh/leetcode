/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 01, 2014
 *  Problem:     	Binary Tree Zigzag Traversal
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 *
 *  Notes:
 *  For example:
 *  Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *  
 *  return its zigzag level order traversal as:
 *   [
 *    [3],
 *    [20,9],
 *    [15,7]
 *   ]
 *
 *  Solution: 		
*********************************************************************************/

#ifndef ZIGZAG_LEVEL_H
#define ZIGZAG_LEVEL_H

#include <vector>
#include <algorithm>
#include <bintree.h>

using namespace std;

class Solution
{
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root);
};

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode *root)
{
  vector<vector<int> > res;
  if (!root) return res;

  // for level access
  queue<TreeNode *> queue;
  queue.push(root);

  int currNodes = 1;
  int nextNodes = 0;

  // left to right access, need to reverse level vector 
  bool l2r = true;  

  vector<int> level;
  while(!queue.empty())
  {
    TreeNode *p = queue.front();
    queue.pop();

    currNodes--;

    if(p)
    {
      level.push_back(p->val);
      queue.push(p->right);
      queue.push(p->left);
      nextNodes += 2;
    }

    // note null nodes
    if (currNodes == 0 && level.size())
    { 
      if (l2r)
        reverse(level.begin(), level.end());
      res.push_back(level);
      level.clear();
      currNodes = nextNodes;
      nextNodes = 0;
      l2r = !l2r;
    }
  }
  return res;
}
#endif /* ZIGZAG_LEVEL_H */

