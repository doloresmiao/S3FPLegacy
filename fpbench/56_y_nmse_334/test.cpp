
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
__device__ double ret;

__global__
#else
double ret;
#endif
// modify parameter here
void compute(double var_1) {//, double var_2, double var_3) {
  // modify function + parameter here
  double comp = nmse_334(var_1);//, var_2, var_3);
  ret = comp;
}

int main(int argc, char** argv) {
/* Program variables */
  char *iname = argv[1]; 
  char *oname = argv[2]; 
    
  FILE *ifile = fopen(iname, "r"); 
  FILE *ofile = fopen(oname, "w"); 

  double tmp_1; fread(&tmp_1, sizeof(double), 1, ifile);

  compute
  #ifdef CUDA_COMPILE
  <<<1,1>>>
  #endif
  // modify parameter here
  (tmp_1);//, tmp_2, tmp_3);
  #ifdef CUDA_COMPILE
  cudaDeviceSynchronize();
  #endif

  __float128 ret128 = ret;
  fwrite(&ret128, sizeof(__float128), 1, ofile);

  fclose(ifile);
  fclose(ofile);

  return 0;
}
