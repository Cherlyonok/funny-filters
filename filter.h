//
// Created by Timofey Cherlenok on 13.03.2023.
//

#pragma once
#include <map>
#include <vector>
#include <string>
#include "matrix.h"
class Filter {
public:
    virtual void Apply(Matrix<RGB>& bitmap) = 0;
    virtual ~Filter() {
    }

protected:
    const double MAX_CHR_DB = 255;
    static constexpr double GsTransformFactorR = 0.299;
    static constexpr double GsTransformFactorG = 0.587;
    static constexpr double GsTransformFactorB = 0.114;
};
using FilterMap = const std::map<std::string, Filter* (*)(const std::vector<std::string>&)>;