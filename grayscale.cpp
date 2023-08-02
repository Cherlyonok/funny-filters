//
// Created by Timofey Cherlenok on 14.03.2023.
//

#include "grayscale.h"

void GrayScaleFilter::Apply(Matrix<RGB> &bitmap) {
    for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
        for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
            bitmap[i][j].r = static_cast<unsigned char>((GsTransformFactorR * (static_cast<double>(bitmap[i][j].r)) +
                                                         GsTransformFactorG * (static_cast<double>(bitmap[i][j].g)) +
                                                         GsTransformFactorB * (static_cast<double>(bitmap[i][j].b))));
            bitmap[i][j].g = bitmap[i][j].r;
            bitmap[i][j].b = bitmap[i][j].r;
        }
    }
}
