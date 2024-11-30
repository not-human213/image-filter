<h2>Image Filtering Project 🎨</he>
This repository contains my Image Filtering project, developed as part of the CS50 Week 4 Assignment. The project demonstrates how to implement basic image filtering techniques in C, working with BMP image files.

Features ✨
Grayscale Filter: Converts an image into shades of gray.
Sepia Filter: Applies a sepia tone for a warm, vintage look.
Reflection: Creates a mirrored reflection of the image.
Blur Filter: Smoothens the image using a simple box blur algorithm.
Tools & Technologies 🛠
Language: C
Images: BMP format
Frameworks/Libraries: N/A (Implemented from scratch)
Getting Started 🚀
Prerequisites
Ensure you have the following installed:

GCC or any C compiler
Make utility
Installation
Clone this repository:

bash
Copy code
git clone https://github.com/username/image-filtering.git  
cd image-filtering  
Compile the program:

bash
Copy code
make filter  
Usage
Run the program:

bash
Copy code
./filter <filter_type> infile.bmp outfile.bmp  
Replace <filter_type> with one of the following:

grayscale
sepia
reflect
blur
Example:

bash
Copy code
./filter grayscale input.bmp output.bmp  
Example Output
