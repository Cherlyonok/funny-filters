//
// Created by Timofey Cherlenok on 14.03.2023.
//

#pragma once
#include <iostream>
#include "filter.h"
class CropFilter : public Filter {
public:
    static const size_t NUM_PARAM = 2;
    CropFilter(size_t width, size_t height) : width_(width), height_(height){};
    void Apply(Matrix<RGB> &matrix) override;

private:
    size_t width_;
    size_t height_;
};