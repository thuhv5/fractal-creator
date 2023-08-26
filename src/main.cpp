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
	for (int x=0; x<W; ++x)
		for (int y=0; y<H; ++y)
		{
			bitmap.setPixel(x, y, 255, 255, 0);
			double xFractal = (x - W/2) / (W/2 / 2);
			double yFractal = (y - H/2) / (H/2 / 2);
		}


	bitmap.write("test.bmp");
	cout << "Finished." << endl;
	return 0;
}
