// Copyright (c) 2016-2017, XMOS Ltd, All rights reserved

#ifndef DSP_TRANSFORMS_H_
#define DSP_TRANSFORMS_H_

#include <stdint.h>
#include <dsp_complex.h>

#if defined(__XS2A__)

/** This function computes the number of leading sign bits in an array of
 * complex numbers. This can be used to calculate the current headroom, and
 * using dsp_bfp_shl to increase the headroom or to reduce the headroom (in
 * order to increase dynamic range).
 *
 * Requires at most 9 x N instructions.
 *
 * \param[in]     pts   Array of dsp_complex_t elements.
 * \param[in]     N     Number of points.
 * 
 * \returns       number of bits of headroom
 */
uint32_t dsp_bfp_cls(dsp_complex_t pts[], const uint32_t N);

/** This function shifts an array of complex numbers to adjust the headroom
 * It shifts left if the shift argument is positive, or right if the shift
 * argument is negative. Hence, a sequence::
 *
 * Requires at most 6 x N instructions.
 *
 *   unsigned ls = dsp_bfp_cls(x,N)
 *   dsp_bfp_shl(x, ls-1, N)
 *
 * will result in one leading sign bit; minimising headroom and maximising
 * dynamic range.
 *
 * \param[in,out] pts       Array of dsp_complex_t elements.
 * \param[in]     shift     Number of places to shift left by.
 * \param[in]     N         Number of points. Must be a power of two.
 */
void dsp_bfp_shl( dsp_complex_t pts[], const uint32_t shift, const uint32_t N );

#endif

#endif

