# CUDA C/C++ Programs

This section contains programming code under `.cu` suffix. Using `nvcc` instead of `gcc` or `g++` to compile.

For code using CURAND, CUBLAS, Thrust library, using `-lcublas`, `-lcurand` to load library headers.

## Numerical Linear Algebra Algorithms
 
  1. __Matrix multiplication__ using __CURAND__, __CUBLAS__ and __Thrust__

     see `mat_mul_cublas.cu` and `mat_mul_thrust.cu` 