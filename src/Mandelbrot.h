/*
 * Mandelbrot.h
 *
 *  Created on: Aug 27, 2023
 *      Author: thuhv5
 */

#ifndef SRC_MANDELBROT_H_
#define SRC_MANDELBROT_H_

namespace fractal_img
{

class Mandelbrot
{
public:
	static const int MAX_ITER = 1000;
public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterations(double x, double y);
};

} /* namespace fractal_img */

#endif /* SRC_MANDELBROT_H_ */
