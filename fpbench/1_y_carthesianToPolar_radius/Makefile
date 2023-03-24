ifndef $(CC)
CC = clang++
endif

OPT = -O0

ifeq ($(OPT_LEVEL), 0)
OPT = -O0
endif

ifeq ($(OPT_LEVEL), 1)
OPT = -O1
endif

ifeq ($(OPT_LEVEL), 2)
OPT = -O2
endif

ifeq ($(OPT_LEVEL), 3)
OPT = -O3
endif

ifeq ($(FASTMATH), 1)
ifeq ($(CC), nvcc)
OPT += -use_fast_math
else
OPT += -ffast-math
endif
endif

ifndef $(LIBS)
ifeq ($(CC), clang++)
LIBS = -lcudart_static -ldl -lrt -lpthread
else ifeq ($(CC), nvcc)
LIBS = -lcudart_static -ldl -lrt -lpthread
else
LIBS = -lm
endif
endif

ifeq ($(CC), clang++)
CUDAFLAGS = -x cuda --cuda-gpu-arch=$(CUDA_CC_VERSION) -L/usr/local/cuda/lib64
else ifeq ($(CC), nvcc)
CUDAFLAGS = -arch=$(CUDA_CC_VERSION) --expt-relaxed-constexpr
endif

CFLAGS = 
LDFLAGS = $(LIBS)

default: main

run:
	cat input.txt | ./test `xargs`

main:
	$(CC) test.cpp -o test $(CUDAFLAGS) $(OPT) $(LDFLAGS) 

clean:
	rm -rf *.o test *.out
	rm -rf workspace

func_analysis: mk_workspace
	clang -Xclang -load -Xclang Superliner-plugin.so -Xclang -plugin -Xclang -pliner-gpu-function-analysis -c ./test.cpp --cuda-gpu-arch=$(CUDA_CC_VERSION) -x cuda -emit-llvm

raise_precision: 
	clang -Xclang -load -Xclang Superliner-plugin.so -Xclang -plugin -Xclang -pliner-gpu-expand-precision -c ./test.cpp --cuda-gpu-arch=$(CUDA_CC_VERSION) -x cuda -emit-llvm

print_results: 
	clang -Xclang -load -Xclang Superliner-plugin.so -Xclang -plugin -Xclang -pliner-gpu-print-results -c ./test.cpp --cuda-gpu-arch=$(CUDA_CC_VERSION) -x cuda -emit-llvm