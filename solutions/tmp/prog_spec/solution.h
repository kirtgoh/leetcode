#ifndef SPEC_BENCH_H
#define SPEC_BENCH_H

#include <string>

using namespace std;

struct bench_t {
  string name;
  string cat;     // cint or  cfp
  string lan;     // c c++ fortron 
  float ipc;
  float mkpi;
  float rbhr;
};

class Solution
{
public:
  void mergeSort(bench_t b[], int low, int high);
  void merge(bench_t b[], int low, int mid, int high); 

private:
  /* data */
};


#endif /* SPEC_BENCH_H */
