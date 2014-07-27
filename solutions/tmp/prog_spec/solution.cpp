#include "solution.h"

void Solution::merge(bench_t b[], int low, int mid, int high)
{
  bench_t *t = new bench_t[high - low + 1];
  int i = left;
  int j = mid + 1;
  int k = 0;

  while(i < mid && j <= high) {
   if (b[i] <= b[j])
    t[k++] = b[i++];
   else
    t[k++] = a[j++];
  }

  if ( i = mid + 1)
  {
    while(j <= high) {
      t[k++] = b[j++];
    } 
  }
  else
  {
    while (i <= mid)
     t[k++] = b[i++];
  } 

  for (i = low, k = 0; i < high; i++, k++)
    b[i] = t[k];

  delete [] t;
}

void Solution::mergeSort(bench_t b[], int low, int high)
{
}


