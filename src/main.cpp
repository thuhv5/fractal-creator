#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "FractalCreator.h"
#include "Zoom.h"

#define W 800
#define H 600

using namespace fractal_img;

int main()
{
	FractalCreator fractalCreator(800, 600);

	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.3, RGB(0, 255, 255));
	fractalCreator.addRange(0.5, RGB(0, 255, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));
	fractalCreator.run("test.bmp");

	cout << "Finished." << endl;
	return 0;
}
