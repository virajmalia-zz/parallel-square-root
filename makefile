
EXAMPLE=sqrt
CPP_SRC=main.cpp
ISPC_SRC=sqrt.ispc
ISPC_IA_TARGETS=sse2-i32x4,sse4-i32x4,avx1-i32x8,avx2-i32x8,avx512knl-i32x16,avx512skx-i32x16
ISPC_ARM_TARGETS=neon

include common.mk
