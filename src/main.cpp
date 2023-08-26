#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Bitmap.h"

using namespace fractal_img;

int main()
{
	Bitmap bitmap(800, 600);
	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}
