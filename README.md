# Image Filtering Project 🎨  

This repository contains my **Image Filtering** project, developed as part of the **CS50 Week 4 Assignment**. The project demonstrates how to implement basic image filtering techniques in C, working with BMP image files.  

## Features ✨  

- **Grayscale Filter:** Converts an image into shades of gray.  
- **Sepia Filter:** Applies a sepia tone for a warm, vintage look.  
- **Reflection:** Creates a mirrored reflection of the image.  
- **Blur Filter:** Smoothens the image using a simple box blur algorithm.  

## Tools & Technologies 🛠  

- **Language:** C  
- **Images:** BMP format  
- **Frameworks/Libraries:** N/A (Implemented from scratch)  

## Getting Started 🚀  

### Prerequisites  

Ensure you have the following installed:  

- GCC or any C compiler  
- Make utility  

### Installation  

1. Clone this repository:  
   ```bash  
   git clone https://github.com/not-human213/image-filter.git
   cd image-filter  
2. Run the program:
  ```bash
   ./filter <filter_type> infile.bmp outfile.bmp
```
Replace <filter_type> with one of these
<ul>
   <li>-g   for grascale</li>
   <li>-b   for blur</li>
   <li>-r   for reflect</li>
   <li>-e   to identify edges</li>
</ul>
