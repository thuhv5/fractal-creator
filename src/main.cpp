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
	std::unique_ptr<int[]> fractal(new int[W*H]{});

	// calc pixels and histogram: pixels per iter
	for (int x=0; x<W; ++x)
		for (int y=0; y<H; ++y)
		{
			double xFractal = (double(x) - W/2 - 200) / (H/2);
			double yFractal = (double(y) - H/2) / (H/2);
			std::cout << xFractal << " " << yFractal << std::endl;

			int iters = Mandelbrot::getIterations(xFractal, yFractal);
			if (iters != Mandelbrot::MAX_ITER)
				++histogram[iters];
			fractal[y*W+x] = iters;
		}

	int total = 0;
	for (int i=0; i<Mandelbrot::MAX_ITER; ++i)
		total += histogram[i];

	// rendering, bigger iter == brighter
	for (int x=0; x<W; ++x)
		for (int y=0; y<H; ++y)
		{
			int iters = fractal[y*W+x];

			double hue = 0;
			for (int i=0; i<=iters; ++i)
				hue += (double)histogram[i] / total;

			int bright = hue * 255;

			bitmap.setPixel(x, y, 0, bright, 0);
		}

	bitmap.write("test.bmp");
	cout << "Finished." << endl;
	return 0;
}
