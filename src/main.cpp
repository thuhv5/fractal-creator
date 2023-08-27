#include <cmath>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Bitmap.h"
#include "Mandelbrot.h"
#include <cstdint>
#include <memory>
#include "ZoomList.h"

#define W 800
#define H 600

using namespace fractal_img;

int main()
{
	Bitmap bitmap(W, H);
	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITER + 1]{});
	std::unique_ptr<int[]> fractal(new int[W*H]{});

	ZoomList zoomList(W, H);
	zoomList.add(Zoom(W/2, H/2, 4.0/W));
	zoomList.add(Zoom(3*W/4, 3*H/4, 1));	//zoom > 1: zoom out

	// calc pixels and histogram: pixels per iter
	for (int x=0; x<W; ++x)
		for (int y=0; y<H; ++y)
		{
			std::pair<double, double> coords = zoomList.doZoom(x, y);

			//std::cout << coords.first << " " << coords.second << std::endl;

			int iters = Mandelbrot::getIterations(coords.first, coords.second);
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
			if (iters < Mandelbrot::MAX_ITER)
				for (int i=0; i<=iters; ++i)
					hue += (double)histogram[i] / total;

			int bright = pow(255, hue);

			bitmap.setPixel(x, y, 0, bright, 0);
		}

	bitmap.write("test.bmp");
	cout << "Finished." << endl;
	return 0;
}
