# funny-filters
HSE C++ project - several image filters

To use run the program from command line for instructions

Processor takes BMP24 images as inputs. 

Arguments:

`{program name} {input image path} {output image path} [-{1 filter name} [1 parameter] [2 parameter] ...] [-{2 filter name} [1 parameter] [2 parameter] ...] ...`


FILTERS (with my picture 💅💅💅):


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/me.bmp"
	alt="me - #NO FILTERS"
	height = "500"
	width = "500"
	class="center">

### CROP 
crops the image by given width and height

`pics/me.bmp pics/crop.bmp -crop 1000 1000`

	
<image
		src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/crop.bmp"
		alt="me - crop"
		height = "500"
		width = "500"
		class="center">
		
		
### GRAYSCALE 
turns image into b/w

`pics/me.bmp pics/gs.bmp -gs`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/gs.bmp"
	alt="me - gs"
	height = "500"
	width = "500"
	class="center">


### NEGATIVE 
turns image into negative

`pics/me.bmp pics/neg.bmp -neg`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/neg.bmp"
	alt="me - neg"
	height = "500"
	width = "500"
	class="center">
	
### SHARPENING 
makes image sharper

`pics/me.bmp pics/sharp.bmp -sharp`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/sharp.bmp"
	alt="me - sharp"
	height = "500"
	width = "500"
	class="center">
	
### EDGE DETECTION
turns image into only borders - USES THRESHOLD (around 0.1 is good)

`pics/me.bmp pics/edge.bmp -edge 0.03`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/edge.bmp"
	alt="me - edge"
	height = "500"
	width = "500"
	class="center">
	
### GAUSSIAN BLUR

blurs image using [Gaussian Blur](https://en.wikipedia.org/wiki/Gaussian_blur)  (DON'T USE SIGMA PARAMETER MORE THAN 6)

`pics/me.bmp pics/blur.bmp -blur 5`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/blur.bmp"
	alt="me - blur"
	height = "500"
	width = "500"
	class="center">
	
###GRADIENT

turns image into gradient (r g b available only)

`pics/me.bmp pics/custom-r.bmp -custom r`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/custom-r.bmp"
	alt="me - r"
	height = "500"
	width = "500"
	class="center">
	
`pics/me.bmp pics/custom-g.bmp -custom g`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/custom-g.bmp"
	alt="me - g"
	height = "500"
	width = "500"
	class="center">
	
`pics/me.bmp pics/custom-b.bmp -custom b`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/custom-b.bmp"
	alt="me - b"
	height = "500"
	width = "500"
	class="center">
	
	
###COMBO

u can also combine different filters

`pics/me.bmp pics/combo.bmp -blur 5 -custom r`


<image
	src="https://github.com/Cherlyonok/funny-filters/raw/main/pics/combo.bmp"
	alt="me - combo"
	height = "500"
	width = "500"
	class="center">