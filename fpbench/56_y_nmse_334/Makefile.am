
# binary targets 
bin_PROGRAMS = p56_gcc_O0 p56_gcc_O3f p56_clang_O0 p56_clang_O3f p56_nvcc_O0 p56_nvcc_O3f

# ==== examples ====

p56_gcc_O0_SOURCES = test.cpp
p56_gcc_O0_CPPFLAGS = -O0
p56_gcc_O0_LDFLAGS = 
p56_gcc_O0_LDADD = -lquadmath -lm

p56_gcc_O3f_SOURCES = test.cpp
p56_gcc_O3f_CPPFLAGS = -O3 -ffast-math
p56_gcc_O3f_LDFLAGS = 
p56_gcc_O3f_LDADD = -lquadmath -lm

p56_clang_O0_SOURCES = test.cpp
p56_clang_O0_CPPFLAGS = -O0
p56_clang_O0_LDFLAGS = 
p56_clang_O0_LDADD = -lquadmath -lm

p56_clang_O3f_SOURCES = test.cpp
p56_clang_O3f_CPPFLAGS = -O3 -ffast-math
p56_clang_O3f_LDFLAGS = 
p56_clang_O3f_LDADD = -lquadmath -lm

p56_nvcc_O0_SOURCES = test.cpp
p56_nvcc_O0_CPPFLAGS = -O0 -arch=$(CUDA_CC_VERSION) --expt-relaxed-constexpr
p56_nvcc_O0_LDFLAGS = 
p56_nvcc_O0_LDADD = -lquadmath -lcudart_static -ldl -lrt -lpthread

p56_nvcc_O3f_SOURCES = test.cpp
p56_nvcc_O3f_CPPFLAGS = -O3 -use_fast_math -arch=$(CUDA_CC_VERSION) --expt-relaxed-constexpr
p56_nvcc_O3f_LDFLAGS = 
p56_nvcc_O3f_LDADD = -lquadmath -lcudart_static -ldl -lrt -lpthread
