/*
 * Bitmap.h
 *
 *  Created on: Aug 26, 2023
 *      Author: thuhv5
 */

#ifndef SRC_BITMAP_H_
#define SRC_BITMAP_H_

#include <string>
#include <cstdint>

namespace fractal_img
{

class Bitmap
{
private:
	int m_width{0};
	int m_height{0};

public:
	Bitmap(int width, int height);
	virtual ~Bitmap();

	bool write(std::string filename);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
};

} /* namespace fractal_img */

#endif /* SRC_BITMAP_H_ */
