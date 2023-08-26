/*
 * Bitmap.cpp
 *
 *  Created on: Aug 26, 2023
 *      Author: thuhv5
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "string.h"

using namespace fractal_img;

namespace fractal_img
{

Bitmap::Bitmap(int width, int height)
		: m_width(width),
		  m_height(height),
		  m_pPixels(new uint8_t[width*height*3]{})
{
}

Bitmap::~Bitmap()
{
}

bool Bitmap::write(std::string filename)
{
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::binary);
	if (!file)
		return false;

	//memset((void*)m_pPixels.get(), 255, m_width*m_height*3);

	int size = m_width*m_height*3;
	for (int i=0; i<size; ++i)
	{
		if (i%3==1)
			m_pPixels[i] = 255;
	}

	file.write((char*)&fileHeader, sizeof(fileHeader));
	file.write((char*)&infoHeader, sizeof(infoHeader));
	file.write((char*)m_pPixels.get(), m_width*m_height*3);

	file.close();

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
{
}


} /* namespace fractal_img */
