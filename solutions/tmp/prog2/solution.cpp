#include "solution.h"
int Solution::maxDepth(TreeNode *root)
{
  if (root->left && root->right)
  {
    return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left) : maxDepth(root->right);
  }

  else if (root->left) return (1 + maxDepth(root->left));
  else if (root->right) return (1+ maxDepth(root->right));

  else return 1;
}

