/*
 * ZoomList.h
 *
 *  Created on: Aug 27, 2023
 *      Author: thuhv5
 */

#ifndef SRC_ZOOMLIST_H_
#define SRC_ZOOMLIST_H_

#include <vector>
#include "Zoom.h"
#include "utility"

namespace fractal_img
{

class ZoomList
{
private:
	int m_width{0};
	int m_height{0};
	std::vector<Zoom> zooms;

public:
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	std::pair<double, double> doZoom(int x, int y);
};

} /* namespace fractal_img */

#endif /* SRC_ZOOMLIST_H_ */
