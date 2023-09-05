/*
 * FractalCreator.cpp
 *
 *  Created on: Aug 30, 2023
 *      Author: thuhv5
 */

#include "FractalCreator.h"
#include <iostream>
#include <assert.h>

namespace fractal_img
{

void FractalCreator::calculateRangeTotals()
{
	int rangeIndex = 0;
	for (int i=0; i<Mandelbrot::MAX_ITER; ++i)
	{
		int pixels = m_histogram[i];
		if (i > m_ranges[rangeIndex + 1])
			++rangeIndex;
		m_rangeTotals[rangeIndex] += pixels;
	}

}

void FractalCreator::calculateTotalIterations()
{
	int totalIter = 0;
	for (int i=0; i<Mandelbrot::MAX_ITER; ++i)
	{
		totalIter += m_histogram[i];
	}
}

int FractalCreator::getRange(int iterations) const
{
	int range = 0;
	for (int i=1; i<(int)m_ranges.size(); ++i)
	{
		range = i;
		if (m_ranges[i] > iterations)
			break;
	}
	--range;
	assert(range > -1);
	assert(range < (int)m_ranges.size());

	return range;

}

void FractalCreator::run(std::string filename)
{
	this->calculateIteration();
	this->calculateTotalIteration();
	this->calculateRangeTotals();
	this->drawFractal();
	this->writeBitmap(filename);
}

FractalCreator::FractalCreator(int width, int height) :
		m_width(width),
		m_height(height),
		m_total(0),
		m_histogram(new int[Mandelbrot::MAX_ITER + 1]{}),
		m_fractal(new int[m_width * m_height]{}),
		m_bitmap(m_width, m_height),
		m_zoomList(m_width, m_height)
{
	m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb)
{
	m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITER);
	m_colors.push_back(rgb);

	if (m_bGotFirstRange)
		m_rangeTotals.push_back(0);
	m_bGotFirstRange = true;
}

void FractalCreator::addZoom(const Zoom &zoom)
{
	m_zoomList.add(zoom);
}

void FractalCreator::calculateIteration()
{
	for (int x = 0; x < m_width; ++x)
		for (int y = 0; y < m_height; ++y)
		{
			std::pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iters = Mandelbrot::getIterations(coords.first, coords.second);
			if (iters != Mandelbrot::MAX_ITER)
				++m_histogram[iters];
			m_fractal[y * m_width + x] = iters;
		}
}

void FractalCreator::calculateTotalIteration()
{
	for (int i = 0; i < Mandelbrot::MAX_ITER; ++i)
		m_total += m_histogram[i];
}

void FractalCreator::drawFractal()
{
	for (int x = 0; x < m_width; ++x)
		for (int y = 0; y < m_height; ++y)
		{
			int iters = m_fractal[y * m_width + x];
			int range = getRange(iters);
			int rangeTotal = m_rangeTotals[range];
			int rangeStart = m_ranges[range];

			RGB& startColor = m_colors[range];
			RGB& endColor = m_colors[range + 1];
			RGB colorDiff = endColor - startColor;

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			if (iters < Mandelbrot::MAX_ITER)
			{
				int totalPixels = 0;
				for (int i = rangeStart; i <= iters; ++i)
					totalPixels += m_histogram[i];

				red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
				green = startColor.g + colorDiff.g * (double)totalPixels/rangeTotal;
				blue = startColor.b + colorDiff.b * (double)totalPixels/rangeTotal;
			}

			m_bitmap.setPixel(x, y, red, green, blue);
		}
}

void FractalCreator::writeBitmap(std::string name)
{
	m_bitmap.write(name);
}

FractalCreator::~FractalCreator()
{
}


} /* namespace fractal_img */
