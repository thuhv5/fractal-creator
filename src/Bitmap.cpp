/*
 * Bitmap.cpp
 *
 *  Created on: Aug 26, 2023
 *      Author: thuhv5
 */

#include "Bitmap.h"

namespace fractal_img
{

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height)
{
}

Bitmap::~Bitmap()
{
}

bool Bitmap::write(std::string filename)
{
	return false;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
}

} /* namespace fractal_img */
