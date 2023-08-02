//
// Created by Timofey Cherlenok on 21.03.2023.
//

#pragma once
#include <iostream>
#include "filter.h"

class CustomGradientFilter : public Filter {
public:
    static const size_t NUM_PARAM = 1;
    explicit CustomGradientFilter(char color) : color_(color){};
    void Apply(Matrix<RGB> &bitmap) override;

private:
    char color_;
};
