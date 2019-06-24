// -- ASCII Art Generator by Aemilius --
// Project: https://github.com/aemiliu5/ascii
// Compilation: g++ ascii.cpp -o ascii -std=c++17 -O3 -L/usr/X11R6/lib -lm -lpthread -lX11 -lstdc++fs
#include <iostream>
#include <cstdlib>
#include <experimental/filesystem>
#include "CImg.h"
using namespace std;
using namespace cimg_library;

char const* deb 	=	"-d";
char const* deb2 	=	"--debug";
char const* inv 	=	"-i";
char const* inv2	=	"--invert";

bool ArgumentExists(int argc, char** argv, char const* s)
{
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], s) == 0)
			return true;
	}

	return false;
}

int main(int argc, char** argv)
{
	bool debug 		= (ArgumentExists(argc, argv, deb) || ArgumentExists(argc, argv, deb2));
	bool invert 	= (ArgumentExists(argc, argv, inv) || ArgumentExists(argc, argv, inv2));

	if(argc < 2) cout << "usage: ascii <image> <downscale factor> [-i | --invert] [-d | --debug]" << endl;
	else
	{
		if(!std::experimental::filesystem::exists(argv[1]))
			cout << "ascii: [error] file does not exist." << endl;
		else
		{
			// Import the image and immediately resize it.
			CImg<unsigned char> image(argv[1]);

			if(argc > 2) 
			{
				bool argIsNum = !(strcmp(argv[2], deb) == 0 || strcmp(argv[2], deb2) == 0) || (strcmp(argv[2], inv) == 0 || strcmp(argv[2], inv2) == 0);

				if(argIsNum) // [TODO: use safer function than atoi]
					image = image.resize(image.width()/atoi(argv[2]), image.height()/atoi(argv[2]));
			}

			// Imported image attributes
			const int w = image.width();
			const int h = image.height();

			// Store its values in a 2D array
			int a[w][h] = { 0 };

			for(int y = 0; y < h; ++y)
			{
				for(int x = 0; x < w; ++x)
				{
					a[x][y] = (int)image(x,y);

					if(invert)
						a[x][y] = abs(a[x][y] - 255);

					if(debug)
						cout << x << "," << y << ": " << a[x][y] << endl;
				}
			}

			// Display it on the console
			for(int y = 0; y < h; y++)
			{
				for(int x = 0; x < w; x++)
				{
					if		(a[x][y] > 224)		cout << "@@@";
					else if (a[x][y] > 192)		cout << "$$$";
					else if (a[x][y] > 160)		cout << "###";
					else if (a[x][y] > 128)		cout << "&&&";
					else if (a[x][y] > 96)		cout << "***";
					else if (a[x][y] > 64)		cout << ":::";
					else if (a[x][y] > 32)		cout << "^^^";
					else						cout << "...";
				}
				cout << endl;
			}
		}
	}
	return 0;
}