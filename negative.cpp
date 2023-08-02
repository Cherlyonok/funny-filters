//
// Created by Timofey Cherlenok on 14.03.2023.
//

#include "negative.h"
void NegativeFilter::Apply(Matrix<RGB> &bitmap) {
    for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
        for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
            bitmap[i][j].r = static_cast<unsigned char>(MAX_CHR_DB - static_cast<double>(bitmap[i][j].r));
            bitmap[i][j].g = static_cast<unsigned char>(MAX_CHR_DB - static_cast<double>(bitmap[i][j].g));
            bitmap[i][j].b = static_cast<unsigned char>(MAX_CHR_DB - static_cast<double>(bitmap[i][j].b));
        }
    }
}
