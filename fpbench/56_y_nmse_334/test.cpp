
/* This is a automatically generated test. Do not modify */
#ifdef __CUDACC__
#define CUDA_COMPILE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "common.h"
#include "benchmarks.h"

#ifdef CUDA_COMPILE
__global__
#endif
// modify parameter here
void compute(double var_1) {//, double var_2, double var_3) {
  // modify function + parameter here
  double comp = nmse_334(var_1);//, var_2, var_3);
  printf("%.17g\n", comp);
}

int main(int argc, char** argv) {
/* Program variables */

  double tmp_1 = atof(argv[1]);
  //double tmp_2 = atof(argv[2]);
  //double tmp_3 = atof(argv[3]);

  compute
  #ifdef CUDA_COMPILE
  <<<1,1>>>
  #endif
  // modify parameter here
  (tmp_1);//, tmp_2, tmp_3);
  #ifdef CUDA_COMPILE
  cudaDeviceSynchronize();
  #endif

  return 0;
}
