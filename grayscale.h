//
// Created by Timofey Cherlenok on 14.03.2023.
//

#pragma once
#include <iostream>
#include "filter.h"

class GrayScaleFilter : public Filter {
public:
    static const size_t NUM_PARAM = 0;
    GrayScaleFilter(){};
    void Apply(Matrix<RGB> &bitmap) override;

private:
};
