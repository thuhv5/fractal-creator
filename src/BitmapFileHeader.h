/*
 * BitmapFileHeader.h
 *
 *  Created on: Aug 24, 2023
 *      Author: thuhv5
 */

#ifndef SRC_BITMAPFILEHEADER_H_
#define SRC_BITMAPFILEHEADER_H_

#include <cstdint>
#pragma pack(2)

namespace fractal_img
{

struct BitmapFileHeader
{
	char header[2] {'B', 'M'};
	int32_t fileSize;
	int32_t reserved {0};
	int32_t dataOffset;
};

}


#endif /* SRC_BITMAPFILEHEADER_H_ */
