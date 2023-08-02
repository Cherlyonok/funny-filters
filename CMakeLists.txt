add_executable(
        image_processor
        image_processor.cpp
        filter.h crop.h crop.cpp negative.cpp negative.h sharpening.cpp sharpening.h grayscale.cpp grayscale.h edge_detection.cpp edge_detection.h gaussian_blur.cpp gaussian_blur.h parser.cpp parser.h pipeline.cpp pipeline.h parsed_input.h bitmap.cpp bitmap.h matrix.h custom_gradient.cpp custom_gradient.h exceptions.h application.cpp application.h status.h filter_creators.h)
add_catch(test_img crop.cpp negative.cpp sharpening.cpp grayscale.cpp edge_detection.cpp gaussian_blur.cpp parser.cpp pipeline.cpp bitmap.cpp custom_gradient.cpp test.cpp)
