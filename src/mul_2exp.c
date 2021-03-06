/* mpc_mul_2exp -- Multiply a complex number by 2^e.

Copyright (C) 2002, 2009 Andreas Enge, Paul Zimmermann, Philippe Th\'eveny

This file is part of the MPC Library.

The MPC Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The MPC Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the MPC Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#include "mpc-impl.h"

int
mpc_mul_2exp (mpc_ptr a, mpc_srcptr b, unsigned long int c, mpc_rnd_t rnd)
{
  int inex_re, inex_im;

  inex_re = mpfr_mul_2exp (MPC_RE(a), MPC_RE(b), c, MPC_RND_RE(rnd));
  inex_im = mpfr_mul_2exp (MPC_IM(a), MPC_IM(b), c, MPC_RND_IM(rnd));

  return MPC_INEX(inex_re, inex_im);
}
