#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Bitmap.h"
#include "Mandelbrot.h"
#include <cstdint>
#include <memory>

#define W 800
#define H 600

using namespace fractal_img;

int main()
{
	Bitmap bitmap(W, H);
	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITER + 1]{});

	for (int x=0; x<W; ++x)
		for (int y=0; y<H; ++y)
		{
			double xFractal = (double(x) - W/2 - 200) / (H/2);
			double yFractal = (double(y) - H/2) / (H/2);
			std::cout << xFractal << " " << yFractal << std::endl;

			int iters = Mandelbrot::getIterations(xFractal, yFractal);
			++histogram[iters];
			uint8_t bright = (uint8_t)(256*((double)iters / Mandelbrot::MAX_ITER));
			bright = bright*bright*bright;

			bitmap.setPixel(x, y, 0, bright, 0);
		}

	bitmap.write("test.bmp");
	cout << "Finished." << endl;
	return 0;
}
