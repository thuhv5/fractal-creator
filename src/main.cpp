#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "FractalCreator.h"
#include "RGB.h"

#define W 800
#define H 600

using namespace fractal_img;

int main()
{
	RGB rgb1(4,5,6);
	RGB rgb2(1,2,3);
	RGB rgb3 = rgb1 - rgb2;
	cout << rgb3.r << " " << rgb3.g << " " << rgb3.b << endl;

	FractalCreator fractalCreator(800, 600);
	fractalCreator.run("test.bmp");

	cout << "Finished." << endl;
	return 0;
}
