make CC=gcc OPT_LEVEL=0 && mv ./test ./test_gcc_0
make CC=gcc OPT_LEVEL=3 FASTMATH=1 && mv ./test ./test_gcc_3
make CC=clang OPT_LEVEL=0 && mv ./test ./test_clang_0
make CC=clang OPT_LEVEL=3 FASTMATH=1 && mv ./test ./test_clang_3
make CC=nvcc OPT_LEVEL=0 && mv ./test ./test_nvcc_0
make CC=nvcc OPT_LEVEL=3 FASTMATH=1 && mv ./test ./test_nvcc_3