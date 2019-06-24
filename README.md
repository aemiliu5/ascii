# ASCII Art Generator
> A simple ASCII art generator written in C++.

## The Premise
Coded in one morning for a programming challenge, with the bells and whistles added overtime.

Uses the [CImg](https://github.com/dtschump/CImg) library.

## Compilation
To compile, use the following command:

```g++ ascii.cpp -o ascii -std=c++17 -O3 -L/usr/X11R6/lib -lm -lpthread -lX11 -lstdc++fs```

## Usage
```ascii <image> <downscale factor> [-i | --invert] [-d | --debug]```

- image: the image you want to convert (ex: test.jpg)
- downscale factor: the resize factor (ex: 2 will resize the image to half its resolution)
- invert: inverts the pixel values, might improve the look of some images
- debug: outputs raw pixel values before converting the image

The downscale factor is necessary for larger images because the resulting output will probably be unreadable through a standard terminal.

## License
This software uses the [GNU LGPL](LICENSE) license, because it is the closest to the CECILL-C license that CImg uses.
