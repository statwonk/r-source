/*
 *  Mathlib : A C Library of Special Functions
 *  Copyright (C) 1998 Ross Ihaka
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  SYNOPSIS
 *
 *    #include "Mathlib.h"
 *    double pcauchy(double x, double location, double scale);
 *
 *  DESCRIPTION
 *
 *    The distribution function of the Cauchy distribution.
 */

#include "Mathlib.h"

double pcauchy(double x, double location, double scale)
{
    if (
#ifdef IEEE_754
	isnan(x) || !finite(location) || !finite(scale) ||
#endif
	scale <= 0) {
	    ML_ERROR(ME_DOMAIN);
	    return ML_NAN;
	}
	x = (x - location) / scale;
	if(!finite(x)) {
	    if(x < 0) return 0;
	    else return 1;
	}
	return 0.5 + atan(x) / M_PI;
}
