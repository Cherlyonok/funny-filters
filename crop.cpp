//
// Created by Timofey Cherlenok on 14.03.2023.
//
#include "crop.h"
void CropFilter::Apply(Matrix<RGB> &matrix) {
    matrix.Resize(std::min(height_, matrix.GetRowsNum()), std::min(width_, matrix.GetColsNum()), {0, 0, 0});
}
