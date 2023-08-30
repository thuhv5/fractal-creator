/*
 * RGB.h
 *
 *  Created on: Aug 30, 2023
 *      Author: thuhv5
 */

#ifndef SRC_RGB_H_
#define SRC_RGB_H_

namespace fractal_img
{

struct RGB
{
	double r;
	double g;
	double b;

	RGB(double r, double g, double b);
};

RGB operator-(const RGB& first, const RGB& second);

} /* namespace fractal_img */

#endif /* SRC_RGB_H_ */
