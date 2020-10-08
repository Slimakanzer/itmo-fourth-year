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

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void mul(signed int *llvm_cbe_a, signed int *llvm_cbe_b, signed int *llvm_cbe_c,  char llvm_cbe_n);


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

void mul(signed int *llvm_cbe_a, signed int *llvm_cbe_b, signed int *llvm_cbe_c,  char llvm_cbe_n) {
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
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned char llvm_cbe_storemerge6;
  unsigned char llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  signed int *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned char llvm_cbe_storemerge15;
  unsigned char llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  signed int *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  signed int *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  signed int *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  signed int *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  signed int *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  signed int *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned long long llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  signed int *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  signed int *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned long long llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  signed int *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  signed int *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned long long llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  signed int *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  signed int *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  signed int *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  signed int *llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  signed int *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned int llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  unsigned long long llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  signed int *llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  unsigned int llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  signed int *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  unsigned int llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned long long llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  signed int *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  unsigned int llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned int llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  signed int *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  unsigned int llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned int llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  signed int *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned char llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned char llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond7_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @mul\n");
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe__2e_preheader4;

  do {     /* Syntactic loop '.preheader4' to make GCC happy */
llvm_cbe__2e_preheader4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i8 [ 0, %%0 ], [ %%106, %%105  for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned char )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__105);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i8 %%storemerge6 to i32, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge6&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = mul nsw i32 %%1, 10, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) * ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__3 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__2&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i32* %%a, i64 %%3, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__4 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__3))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__3));
}
  llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__106:
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = add i8 %%storemerge6, 1, !dbg !4 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__105 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge6&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__105&255ull)));
  if (((llvm_cbe_tmp__105&255U) == (((unsigned char )10)&255U))) {
    goto llvm_cbe_tmp__107;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__105;   /* for PHI node */
    goto llvm_cbe__2e_preheader4;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i8 [ 0, %%.preheader4 ], [ %%104, %%.preheader  for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned char )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%X",llvm_cbe_storemerge15);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__104);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = zext i8 %%storemerge15 to i32, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_storemerge15&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%4, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__6 = (unsigned int )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i8 %%storemerge15 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__7 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_storemerge15&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i32* %%b, i64 %%7, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__8 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__7))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i32* %%8, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__9 = (unsigned int )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = mul nsw i32 %%9, %%6, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__6&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = or i32 %%2, 1, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__11 = (unsigned int )llvm_cbe_tmp__2 | 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i32 %%11 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__12 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__11&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i32* %%a, i64 %%12, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__13 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__12))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%13, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__14 = (unsigned int )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add nsw i32 %%5, 10, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__15&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i32 %%15 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__16 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__15&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i32* %%b, i64 %%16, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__17 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__16))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__16));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__18 = (unsigned int )*llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = mul nsw i32 %%18, %%14, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__19 = (unsigned int )((unsigned int )(llvm_cbe_tmp__18&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__14&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__19&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add nsw i32 %%19, %%10, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_tmp__19&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__10&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add nsw i32 %%2, 2, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__21&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i32 %%21 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__22 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__21&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds i32* %%a, i64 %%22, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__23 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__22))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__22));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i32* %%23, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__24 = (unsigned int )*llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%5, 20, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(20u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = zext i32 %%25 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__26 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__25&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i32* %%b, i64 %%26, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__27 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__26))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__26));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i32* %%27, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__28 = (unsigned int )*llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = mul nsw i32 %%28, %%24, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_tmp__28&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__24&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add nsw i32 %%29, %%20, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(llvm_cbe_tmp__29&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__20&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__30&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%2, 3, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i32 %%31 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__32 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__31&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i32* %%a, i64 %%32, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__33 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__32))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__32));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i32* %%33, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__34 = (unsigned int )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add nsw i32 %%5, 30, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(30u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = zext i32 %%35 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__36 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__35&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i32* %%b, i64 %%36, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__37 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__36))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__36));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%37, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__38 = (unsigned int )*llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = mul nsw i32 %%38, %%34, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_tmp__38&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__34&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add nsw i32 %%39, %%30, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__40 = (unsigned int )((unsigned int )(llvm_cbe_tmp__39&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__30&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__40&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add nsw i32 %%2, 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(4u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = zext i32 %%41 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__42 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__41&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds i32* %%a, i64 %%42, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__43 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__42))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__42));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i32* %%43, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__44 = (unsigned int )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add nsw i32 %%5, 40, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__45 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(40u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__45&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = zext i32 %%45 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__46 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__45&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds i32* %%b, i64 %%46, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__47 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__46))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__46));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = load i32* %%47, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__48 = (unsigned int )*llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = mul nsw i32 %%48, %%44, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__49 = (unsigned int )((unsigned int )(llvm_cbe_tmp__48&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__44&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__49&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add nsw i32 %%49, %%40, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__50 = (unsigned int )((unsigned int )(llvm_cbe_tmp__49&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__40&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__50&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add nsw i32 %%2, 5, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__51 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(5u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__51&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = zext i32 %%51 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__52 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__51&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds i32* %%a, i64 %%52, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__53 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__52))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__52));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i32* %%53, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__54 = (unsigned int )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add nsw i32 %%5, 50, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(50u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__55&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = zext i32 %%55 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__56 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__55&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds i32* %%b, i64 %%56, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__57 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__56))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__56));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = load i32* %%57, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__58 = (unsigned int )*llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = mul nsw i32 %%58, %%54, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_tmp__58&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__54&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = add nsw i32 %%59, %%50, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__60 = (unsigned int )((unsigned int )(llvm_cbe_tmp__59&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__50&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__60&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = add nsw i32 %%2, 6, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__61 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(6u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__61&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = zext i32 %%61 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__62 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__61&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds i32* %%a, i64 %%62, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__63 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__62))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__62));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load i32* %%63, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__64 = (unsigned int )*llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add nsw i32 %%5, 60, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__65 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(60u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__65&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = zext i32 %%65 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__66 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__65&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = getelementptr inbounds i32* %%b, i64 %%66, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__67 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__66))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__66));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = load i32* %%67, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__68 = (unsigned int )*llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = mul nsw i32 %%68, %%64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(llvm_cbe_tmp__68&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__64&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__69&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = add nsw i32 %%69, %%60, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__70 = (unsigned int )((unsigned int )(llvm_cbe_tmp__69&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__60&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__70&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = add nsw i32 %%2, 7, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__71 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(7u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__71&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = zext i32 %%71 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__72 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__71&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds i32* %%a, i64 %%72, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__73 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__72))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__72));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i32* %%73, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__74 = (unsigned int )*llvm_cbe_tmp__73;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add nsw i32 %%5, 70, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__75 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(70u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__75&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = zext i32 %%75 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__76 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__75&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = getelementptr inbounds i32* %%b, i64 %%76, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__77 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__76))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__76));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = load i32* %%77, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__78 = (unsigned int )*llvm_cbe_tmp__77;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = mul nsw i32 %%78, %%74, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__79 = (unsigned int )((unsigned int )(llvm_cbe_tmp__78&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__74&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__79&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = add nsw i32 %%79, %%70, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__80 = (unsigned int )((unsigned int )(llvm_cbe_tmp__79&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__70&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__80&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = add nsw i32 %%2, 8, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__81 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(8u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__81&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = zext i32 %%81 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__82 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__81&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = getelementptr inbounds i32* %%a, i64 %%82, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__83 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__82))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__82));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = load i32* %%83, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__84 = (unsigned int )*llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = add nsw i32 %%5, 80, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__85 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(80u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__85&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = zext i32 %%85 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__86 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__85&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = getelementptr inbounds i32* %%b, i64 %%86, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_173_count);
  llvm_cbe_tmp__87 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__86))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__86));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = load i32* %%87, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__88 = (unsigned int )*llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = mul nsw i32 %%88, %%84, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__89 = (unsigned int )((unsigned int )(llvm_cbe_tmp__88&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__84&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__89&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = add nsw i32 %%89, %%80, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__90 = (unsigned int )((unsigned int )(llvm_cbe_tmp__89&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__80&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__90&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = add nsw i32 %%2, 9, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__91 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(9u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__91&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = zext i32 %%91 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__92 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__91&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = getelementptr inbounds i32* %%a, i64 %%92, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__93 = (signed int *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__92))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__92));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = load i32* %%93, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__94 = (unsigned int )*llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = add nsw i32 %%5, 90, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__95 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(90u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__95&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = zext i32 %%95 to i64, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__96 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__95&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = getelementptr inbounds i32* %%b, i64 %%96, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__97 = (signed int *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__96))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__96));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = load i32* %%97, align 4, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_192_count);
  llvm_cbe_tmp__98 = (unsigned int )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = mul nsw i32 %%98, %%94, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__99 = (unsigned int )((unsigned int )(llvm_cbe_tmp__98&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__94&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__99&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = add nsw i32 %%99, %%90, !dbg !2 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__100 = (unsigned int )((unsigned int )(llvm_cbe_tmp__99&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__90&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__100&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = add nsw i32 %%5, %%2, !dbg !3 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__101 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__2&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__101&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = sext i32 %%101 to i64, !dbg !3 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__102 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = getelementptr inbounds i32* %%c, i64 %%102, !dbg !3 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__103 = (signed int *)(&llvm_cbe_c[(((signed long long )llvm_cbe_tmp__102))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__102));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%100, i32* %%103, align 4, !dbg !3 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_206_count);
  *llvm_cbe_tmp__103 = llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = add i8 %%storemerge15, 1, !dbg !4 for 0x%I64xth hint within @mul  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__104 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_storemerge15&255ull)) + ((unsigned char )(((unsigned char )1)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__104&255ull)));
  if (((llvm_cbe_tmp__104&255U) == (((unsigned char )10)&255U))) {
    goto llvm_cbe_tmp__106;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__104;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '.preheader4' */
llvm_cbe_tmp__107:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @mul}\n");
  return;
}

