/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */
extern signed int a[100];
extern signed int b[100];
extern signed int c_gold[100];
extern signed int c[100];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void mat_rand(signed int *llvm_cbe_mat, signed int llvm_cbe_n);
void mul_test(signed int *llvm_cbe_a, signed int *llvm_cbe_b, signed int *llvm_cbe_c,  char llvm_cbe_n);
signed int main(void);
void AESL_WRAP_mul(signed int *, signed int *, signed int *,  char );


/* Global Variable Definitions and Initialization */
signed int a[100] __ATTRIBUTE_WEAK__;
signed int b[100] __ATTRIBUTE_WEAK__;
signed int c_gold[100] __ATTRIBUTE_WEAK__;
signed int c[100] __ATTRIBUTE_WEAK__;
static  char aesl_internal__OC_str[17] = "Test %i failed.\n";
static  char aesl_internal__OC_str1[31] = "**************\nTest completed\n";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void mat_rand(signed int *llvm_cbe_mat, signed int llvm_cbe_n) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  signed int *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @mat_rand\n");
  if ((((signed int )llvm_cbe_n) > ((signed int )0u))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%3, %%2 ], [ 0, %%0  for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__1);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul nsw i32 %%storemerge3.us, %%n, !dbg !6 for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__7 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) * ((unsigned int )(llvm_cbe_n&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__7&4294967295ull)));
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__8;

llvm_cbe_tmp__9:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add nsw i32 %%storemerge3.us, 1, !dbg !7 for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__1&4294967295ull)));
  if (((llvm_cbe_tmp__1&4294967295U) == (llvm_cbe_n&4294967295U))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__1;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__8:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%9, %%4  for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 @rand() nounwind, !dbg !6 for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__2 = (unsigned int ) /*tail*/ rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge12.us, %%10, !dbg !6 for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !6 for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__4 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i32* %%mat, i64 %%7, !dbg !6 for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__5 = (signed int *)(&llvm_cbe_mat[(((signed long long )llvm_cbe_tmp__4))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__4));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%5, i32* %%8, align 4, !dbg !6 for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_23_count);
  *llvm_cbe_tmp__5 = llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge12.us, 1, !dbg !7 for 0x%I64xth hint within @mat_rand  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
  if (((llvm_cbe_tmp__6&4294967295U) == (llvm_cbe_n&4294967295U))) {
    goto llvm_cbe_tmp__9;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__6;   /* for PHI node */
    goto llvm_cbe_tmp__8;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge4:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @mat_rand}\n");
  return;
}


void mul_test(signed int *llvm_cbe_a, signed int *llvm_cbe_b, signed int *llvm_cbe_c,  char llvm_cbe_n) {
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  signed int *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_2e_us_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge15_2e_us_2e_us;
  unsigned int llvm_cbe_storemerge15_2e_us_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_2e_us_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge23_2e_us_2e_us;
  unsigned int llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__16;
  unsigned int llvm_cbe_tmp__16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  signed int *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  signed int *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge7_2e_us;
  unsigned int llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @mul_test\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i8 %%n to i32, !dbg !7 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_n&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
  if (((llvm_cbe_n&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e__crit_edge8;
  } else {
    llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us_2e_us;
  }

  do {     /* Syntactic loop '.preheader.lr.ph.split.us.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7.us = phi i32 [ %%3, %%._crit_edge6.us-lcssa.us.us ], [ 0, %%0  for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_storemerge7_2e_us_count);
  llvm_cbe_storemerge7_2e_us = (unsigned int )llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7.us = 0x%X",llvm_cbe_storemerge7_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__11);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = mul nsw i32 %%storemerge7.us, 10, !dbg !7 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge7_2e_us&4294967295ull)) * ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
  llvm_cbe_storemerge15_2e_us_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_us_2e_us;

llvm_cbe__2e__crit_edge6_2e_us_2d_lcssa_2e_us_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add nsw i32 %%storemerge7.us, 1, !dbg !8 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__11 = (unsigned int )((unsigned int )(llvm_cbe_storemerge7_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__11&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__11) < ((signed int )llvm_cbe_tmp__10))) {
    llvm_cbe_storemerge7_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__11;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge8;
  }

  do {     /* Syntactic loop '.lr.ph.us.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15.us.us = phi i32 [ 0, %%.preheader.lr.ph.split.us.us ], [ %%9, %%5  for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_storemerge15_2e_us_2e_us_count);
  llvm_cbe_storemerge15_2e_us_2e_us = (unsigned int )llvm_cbe_storemerge15_2e_us_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15.us.us = 0x%X",llvm_cbe_storemerge15_2e_us_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__15);
}
  llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__16__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__30;

llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge15.us.us, %%26, !dbg !7 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15_2e_us_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__29&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !7 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__13 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i32* %%c, i64 %%7, !dbg !7 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__14 = (signed int *)(&llvm_cbe_c[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%23, i32* %%8, align 4, !dbg !7 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_65_count);
  *llvm_cbe_tmp__14 = llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge15.us.us, 1, !dbg !8 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15_2e_us_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__15&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__15) < ((signed int )llvm_cbe_tmp__10))) {
    llvm_cbe_storemerge15_2e_us_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__15;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge6_2e_us_2d_lcssa_2e_us_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__30:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23.us.us = phi i32 [ 0, %%.lr.ph.us.us ], [ %%24, %%11  for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_storemerge23_2e_us_2e_us_count);
  llvm_cbe_storemerge23_2e_us_2e_us = (unsigned int )llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23.us.us = 0x%X",llvm_cbe_storemerge23_2e_us_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i32 [ 0, %%.lr.ph.us.us ], [ %%23, %%11  for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__16 = (unsigned int )llvm_cbe_tmp__16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge23.us.us, %%26, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_storemerge23_2e_us_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__29&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%13 to i64, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__18 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i32* %%a, i64 %%14, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__19 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__18))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%15, align 4, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__20 = (unsigned int )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = mul nsw i32 %%storemerge23.us.us, 10, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(llvm_cbe_storemerge23_2e_us_2e_us&4294967295ull)) * ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__21&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%17, %%storemerge15.us.us, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_tmp__21&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge15_2e_us_2e_us&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%18 to i64, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__23 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i32* %%b, i64 %%19, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__24 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__23))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%20, align 4, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__25 = (unsigned int )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = mul nsw i32 %%21, %%16, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(llvm_cbe_tmp__25&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__20&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__26&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%22, %%12, !dbg !6 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(llvm_cbe_tmp__26&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__16&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__27&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%storemerge23.us.us, 1, !dbg !8 for 0x%I64xth hint within @mul_test  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_storemerge23_2e_us_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__28) < ((signed int )llvm_cbe_tmp__10))) {
    llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__28;   /* for PHI node */
    llvm_cbe_tmp__16__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__27;   /* for PHI node */
    goto llvm_cbe_tmp__30;
  } else {
    goto llvm_cbe_tmp__31;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us.us' */
  } while (1); /* end of syntactic loop '.preheader.lr.ph.split.us.us' */
llvm_cbe__2e__crit_edge8:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @mul_test}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned char llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned char llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned char llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned long long llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned long long llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__49;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%18, %%17  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 @rand() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__32 = (unsigned int ) /*tail*/ rand();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i32 %%2 to i8, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__33 = (unsigned char )((unsigned char )llvm_cbe_tmp__32&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = urem i8 %%3, 5, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__34 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(llvm_cbe_tmp__33&255ull)) % ((unsigned char )(((unsigned char )5)&255ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__34&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i8 %%4 to i32, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__34&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%5, 5, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__36 = (unsigned int )((unsigned int )(llvm_cbe_tmp__35&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__36&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = trunc i32 %%6 to i8, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__37 = (unsigned char )((unsigned char )llvm_cbe_tmp__36&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @mul_test(i32* getelementptr inbounds ([100 x i32]* @a, i64 0, i64 0), i32* getelementptr inbounds ([100 x i32]* @b, i64 0, i64 0), i32* getelementptr inbounds ([100 x i32]* @c_gold, i64 0, i64 0), i8 zeroext %%7), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_125_count);
   /*tail*/ mul_test((signed int *)((&a[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
])), (signed int *)((&b[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
])), (signed int *)((&c_gold[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
])), llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @AESL_WRAP_mul(i32* getelementptr inbounds ([100 x i32]* @a, i64 0, i64 0), i32* getelementptr inbounds ([100 x i32]* @b, i64 0, i64 0), i32* getelementptr inbounds ([100 x i32]* @c, i64 0, i64 0), i8 zeroext %%7) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_126_count);
   /*tail*/ AESL_WRAP_mul((signed int *)((&a[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
])), (signed int *)((&b[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
])), (signed int *)((&c[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
])), llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul i32 %%6, %%6, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__38 = (unsigned int )((unsigned int )(llvm_cbe_tmp__36&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__36&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__38&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__39 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__38&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = shl nuw nsw i64 %%9, 2, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__40 = (unsigned long long )llvm_cbe_tmp__39 << 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call i32 @memcmp(i8* bitcast ([100 x i32]* @c to i8*), i8* bitcast ([100 x i32]* @c_gold to i8*), i64 %%10) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__41 = (unsigned int ) /*tail*/ memcmp(( char *)(( char *)(&c)), ( char *)(( char *)(&c_gold)), llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__40);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
  if (((llvm_cbe_tmp__41&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__50;
  } else {
    goto llvm_cbe_tmp__51;
  }

llvm_cbe_tmp__50:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__45 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__45&4294967295ull)));
  if (((llvm_cbe_tmp__45&4294967295U) == (100u&4294967295U))) {
    goto llvm_cbe_tmp__52;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__45;   /* for PHI node */
    goto llvm_cbe_tmp__49;
  }

llvm_cbe_tmp__51:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__42 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct._iobuf* %%14, i64 1, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__43 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__42[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%15, i8* getelementptr inbounds ([17 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%storemerge1) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_135_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__43, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 17
#endif
])), llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__44);
}
  goto llvm_cbe_tmp__50;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__52:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__46 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__46);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct._iobuf* %%20, i64 1, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__47 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__46[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = tail call i64 @fwrite(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_.str1, i64 0, i64 0), i64 30, i64 1, %%struct._iobuf* %%21), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_145_count);
   /*tail*/ fwrite(( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])), 30ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",30ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__48);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

