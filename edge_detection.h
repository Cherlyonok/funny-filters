//
// Created by Timofey Cherlenok on 14.03.2023.
//

#pragma once
#include <iostream>
#include "filter.h"

class EdgeDetectionFilter : public Filter {
public:
    static const size_t NUM_PARAM = 1;
    explicit EdgeDetectionFilter(double threshold) : threshold_(threshold){};
    void Apply(Matrix<RGB> &bitmap) override;

private:
    double threshold_;
};
