/*
 * Mandelbrot.cpp
 *
 *  Created on: Aug 27, 2023
 *      Author: thuhv5
 */

#include "Mandelbrot.h"

#include <complex>
#include <iostream>

namespace fractal_img
{

Mandelbrot::Mandelbrot()
{
}

Mandelbrot::~Mandelbrot()
{
}

int Mandelbrot::getIterations(double x, double y)
{
	// return number of iter makes abs>2; the lower, the blacker
	std::complex<double> z = 0;
	std::complex<double> c(x, y);
	int iter = 0;
	while (iter < MAX_ITER)
	{
		z = z*z + c;

		if (abs(z) > 2)
			break;

		++iter;
	}

	return iter;
}

} /* namespace fractal_img */
