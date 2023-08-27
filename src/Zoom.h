/*
 * Zoom.h
 *
 *  Created on: Aug 27, 2023
 *      Author: thuhv5
 */

#ifndef SRC_ZOOM_H_
#define SRC_ZOOM_H_

namespace fractal_img
{

struct Zoom
{
	int m_x{0};
	int m_y{0};
	double m_scale{1.0};

	Zoom(int x, int y, double scale): m_x(x), m_y(y), m_scale(scale)
	{};
};

} /* namespace fractal_img */

#endif /* SRC_ZOOM_H_ */
