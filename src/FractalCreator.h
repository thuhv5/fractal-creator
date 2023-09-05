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
#include <vector>
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

	std::vector<int> m_ranges;
	std::vector<RGB> m_colors;
	std::vector<int> m_rangeTotals;
	bool m_bGotFirstRange{false};

private:
	void calculateTotalIterations();
	void calculateRangeTotals();
	void calculateIteration();
	void calculateTotalIteration();
	void drawFractal();
	void writeBitmap(std::string name);
	int getRange(int iterations) const; //won't modify member-variables

public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void addRange(double rangeEnd, const RGB& rgb);
	void addZoom(const Zoom& zoom);
	void run(std::string filename);
};

} /* namespace fractal_img */

#endif /* SRC_FRACTALCREATOR_H_ */
