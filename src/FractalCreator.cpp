/*
 * FractalCreator.cpp
 *
 *  Created on: Aug 30, 2023
 *      Author: thuhv5
 */

#include "FractalCreator.h"

namespace fractal_img
{

FractalCreator::FractalCreator(int width, int height)
		: m_width(width),
		  m_height(height),
		  m_total(0),
		  m_histogram(new int[Mandelbrot::MAX_ITER + 1]{}),
		  m_fractal(new int[m_width*m_height]{}),
		  m_bitmap(m_width, m_height),
		  m_zoomList(m_width, m_height)
{
	m_zoomList.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
}

FractalCreator::~FractalCreator()
{
}

void FractalCreator::calculateIteration()
{
	for (int x=0; x<m_width; ++x)
		for (int y=0; y<m_height; ++y)
		{
			std::pair<double, double> coords = m_zoomList.doZoom(x, y);

			//std::cout << coords.first << " " << coords.second << std::endl;

			int iters = Mandelbrot::getIterations(coords.first, coords.second);
			if (iters != Mandelbrot::MAX_ITER)
				++m_histogram[iters];
			m_fractal[y*m_width + x] = iters;
		}
}

void FractalCreator::calculateTotalIteration()
{
	for (int i=0; i<Mandelbrot::MAX_ITER; ++i)
		m_total += m_histogram[i];
}


void FractalCreator::drawFractal()
{
	for (int x=0; x<m_width; ++x)
		for (int y=0; y<m_height; ++y)
		{
			int iters = m_fractal[y*m_width+x];

			double hue = 0;
			if (iters < Mandelbrot::MAX_ITER)
				for (int i=0; i<=iters; ++i)
					hue += (double)m_histogram[i] / m_total;

			int bright = hue*255; //pow(255, hue);

			m_bitmap.setPixel(x, y, 0, bright, 0);
		}
}

void FractalCreator::addZoom(const Zoom &zoom)
{
	m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(std::string name)
{
	m_bitmap.write(name);
}

void FractalCreator::run(std::string filename)
{
	this->addZoom(Zoom(295, 600-202, 0.1));
	this->addZoom(Zoom(312, 600-304, 0.1));
	this->calculateIteration();
	this->calculateTotalIteration();
	this->drawFractal();
	this->writeBitmap(filename);
}

} /* namespace fractal_img */
