# funny-filters
HSE C++ project - several image filters

To use run the program from command line for instructions

Processor takes BMP24 images as inputs. 

Arguments:

`{program name} {input image path} {output image path} [-{1 filter name} [1 parameter] [2 parameter] ...] [-{2 filter name} [1 parameter] [2 parameter] ...] ...`


FILTERS (with my picture 💅💅💅):

![me](https://github.com/Cherlyonok/funny-filters/raw/main/pics/me.bmp)

CROP - crops the image by given width and height

`./pics/me.bmp ./pics/crop.bmp -crop 1000 1000`

