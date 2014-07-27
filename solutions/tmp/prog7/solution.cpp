#include "solution.h"

int Solution::binaryInsert(int A[], int s, int e, int target)
{
  // FIXME: pos is difficult to locate 
  if(s == e) return s + 1;

  int mid= (s + e) / 2;
  if (A[mid] == target) return mid;
  else if (A[mid] > target)
    return binaryInsert(A, s, mid-1, target);
  else
    return binaryInsert(A, mid+1, e, target);
}

int Solution::searchInsert(int A[], int n, int target)
{
  return binaryInsert(A, 0, n-1, target);
}

