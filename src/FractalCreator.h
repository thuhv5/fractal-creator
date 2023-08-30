/*
 * FractalCreator.h
 *
 *  Created on: Aug 30, 2023
 *      Author: thuhv5
 */

#ifndef SRC_FRACTALCREATOR_H_
#define SRC_FRACTALCREATOR_H_

#include <memory>
#include <string>
#include <cmath>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "RGB.h"

namespace fractal_img
{

class FractalCreator
{
private:
	int m_width;
	int m_height;
	int m_total;
	std::unique_ptr<int[]> m_histogram;
	std::unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;

private:
	void calculateIteration();
	void calculateTotalIteration();
	void drawFractal();
	void writeBitmap(std::string name);

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void addZoom(const Zoom& zoom);
	void run(std::string filename);
};

} /* namespace fractal_img */

#endif /* SRC_FRACTALCREATOR_H_ */
