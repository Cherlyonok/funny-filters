//
// Created by Timofey Cherlenok on 14.03.2023.
//

#pragma once
#include <iostream>
#include "filter.h"

class SharpeningFilter : public Filter {
public:
    static const size_t NUM_PARAM = 0;
    SharpeningFilter(){};
    void Apply(Matrix<RGB> &bitmap) override;

private:
    static const size_t SHARPENING = 5;
};
