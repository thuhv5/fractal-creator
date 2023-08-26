#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Bitmap.h"

#define W 800
#define H 600

using namespace fractal_img;

int main()
{
	Bitmap bitmap(W, H);
	for (int i=0; i<W; ++i)
		for (int j=0; j<H; ++j)
			bitmap.setPixel(i, j, 0, 255, 0);


	bitmap.write("test.bmp");
	cout << "Finished." << endl;
	return 0;
}
