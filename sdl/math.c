#include <konoha.h>
#ifdef KONOHA_OS__WINDOWS
#define _USE_MATH_DEFINES
#undef METHOD
#define METHOD void __declspec(dllexport) 
#undef KNHAPI
#define KNHAPI(T) T __declspec(dllexport) 
#endif

#include <math.h>

#ifdef __cplusplus 
extern "C" {
#endif


METHOD Math_fabs(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, fabs(p_double(sfp[1])));
}

METHOD Math_abs(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, fabs(p_double(sfp[1])));
}

METHOD Math_pow(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, pow(p_double(sfp[1]),p_double(sfp[2])));
}

METHOD Math_ldexp(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, ldexp(p_double(sfp[1]),p_int(sfp[2])));
}

METHOD Math_modf(Ctx *ctx, knh_sfp_t *sfp)
{
    double iprt = p_double(sfp[2]);
    KNH_RETURN_Float(ctx, sfp, modf(p_double(sfp[1]),&iprt));
}

METHOD Math_frexp(Ctx *ctx, knh_sfp_t *sfp)
{
    int exp = p_int(sfp[2]);
    KNH_RETURN_Float(ctx, sfp, frexp(p_double(sfp[1]),&exp));
}

METHOD Math_fmod(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, fmod(p_double(sfp[1]),p_double(sfp[2])));
}

METHOD Math_ceil(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, ceil(p_double(sfp[1])));
}

#if KONOHA_OS__WINDOWS
METHOD Math_round(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, round(p_double(sfp[1])));
}

METHOD Math_nearbyint(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, nearbyint(p_double(sfp[1])));
}
#endif

METHOD Math_floor(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, floor(p_double(sfp[1])));
}

METHOD Math_sqrt(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx,sfp,sqrt(p_double(sfp[1])));
}

METHOD Math_exp(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx,sfp,exp(p_double(sfp[1])));
}

METHOD Math_log10(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx,sfp,log10(p_double(sfp[1])));
}

METHOD Math_log(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx,sfp,log(p_double(sfp[1])));
}

METHOD Math_sin(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, sin(p_double(sfp[1])));
}

METHOD Math_cos(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, cos(p_double(sfp[1])));
}

METHOD Math_tan(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, tan(p_double(sfp[1])));
}

METHOD Math_asin(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, asin(p_double(sfp[1])));
}

METHOD Math_acos(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, acos(p_double(sfp[1])));
}

METHOD Math_atan(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, atan(p_double(sfp[1])));
}

METHOD Math_atan2(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, atan2(p_double(sfp[1]),p_double(sfp[2])));
}

METHOD Math_sinh(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, sinh(p_double(sfp[1])));
}

METHOD Math_cosh(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, cosh(p_double(sfp[1])));
}

METHOD Math_tanh(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, tanh(p_double(sfp[1])));
}

#if KONOHA_OS__WINDOWS
METHOD Math_asinh(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, asinh(p_double(sfp[1])));
}

METHOD Math_acosh(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, acosh(p_double(sfp[1])));
}

METHOD Math_atanh(Ctx *ctx, knh_sfp_t *sfp)
{
    KNH_RETURN_Float(ctx, sfp, atanh(p_double(sfp[1])));
}
#endif

static
knh_FloatConstData_t FloatConstData[] = {
    {"Math.E", M_E},
    {"Math.LOG2E",M_LOG2E},
    {"Math.LOG10E",M_LOG10E},
    {"Math.LN2",M_LN2},
    {"Math.LN10",M_LN10},
    {"Math.PI", M_PI},
    {"Math.PI_2",M_PI_2},
    {"Math.PI_4",M_PI_4},
    {"Math.SQRT2",M_SQRT2},
    {NULL}
};

KNHAPI(int) init(Ctx *ctx)
{
    KNH_NOTICE(ctx, "loading math...");
    konoha_loadFloatConstData(ctx, FloatConstData);
    return 1;
}

#ifdef __cplusplus
}
#endif

