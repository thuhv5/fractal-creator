#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "FractalCreator.h"

#define W 800
#define H 600

using namespace fractal_img;

int main()
{
	FractalCreator fractalCreator(800, 600);

	fractalCreator.addZoom(Zoom(295, 600-202, 0.1));
	fractalCreator.addZoom(Zoom(312, 600-304, 0.1));
	fractalCreator.calculateIteration();
	fractalCreator.calculateTotalIteration();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmap("test.bmp");

	cout << "Finished." << endl;
	return 0;
}
