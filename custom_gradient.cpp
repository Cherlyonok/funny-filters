//
// Created by Timofey Cherlenok on 21.03.2023.
//

#include "custom_gradient.h"
void CustomGradientFilter::Apply(Matrix<RGB>& bitmap) {
    for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
        for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
            bitmap[i][j].r = static_cast<unsigned char>((GsTransformFactorR * (static_cast<double>(bitmap[i][j].r)) +
                                                         GsTransformFactorG * (static_cast<double>(bitmap[i][j].g)) +
                                                         GsTransformFactorB * (static_cast<double>(bitmap[i][j].b))));
            bitmap[i][j].g = bitmap[i][j].r;
            bitmap[i][j].b = bitmap[i][j].r;
        }
    }
    if (color_ == 'r') {
        for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
            for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
                if (bitmap[i][j].r > MAX_CHR_DB / 2) {
                    bitmap[i][j].r = static_cast<unsigned char>(MAX_CHR_DB / 2 -
                                                                (static_cast<double>(bitmap[i][j].r) - MAX_CHR_DB / 2));
                }
                if (bitmap[i][j].r < MAX_CHR_DB / 4) {
                    bitmap[i][j].b = 0;
                    bitmap[i][j].g = 0;
                    bitmap[i][j].r = static_cast<unsigned char>(static_cast<double>(bitmap[i][j].r) * 4);
                } else {

                    bitmap[i][j].b =
                        static_cast<unsigned char>((static_cast<double>(bitmap[i][j].r) - MAX_CHR_DB / 4) * 4);
                    bitmap[i][j].g = bitmap[i][j].b;
                    bitmap[i][j].r = static_cast<unsigned char>(MAX_CHR_DB);
                }
            }
        }
    }
    if (color_ == 'g') {
        for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
            for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
                if (bitmap[i][j].g > MAX_CHR_DB / 2) {
                    bitmap[i][j].g = static_cast<unsigned char>(MAX_CHR_DB / 2 -
                                                                (static_cast<double>(bitmap[i][j].g) - MAX_CHR_DB / 2));
                }
                if (bitmap[i][j].g < MAX_CHR_DB / 4) {
                    bitmap[i][j].b = 0;
                    bitmap[i][j].r = 0;
                    bitmap[i][j].g = static_cast<unsigned char>(static_cast<double>(bitmap[i][j].g) * 4);
                } else {
                    bitmap[i][j].b =
                        static_cast<unsigned char>((static_cast<double>(bitmap[i][j].g) - MAX_CHR_DB / 4) * 4);
                    bitmap[i][j].r = bitmap[i][j].b;
                    bitmap[i][j].g = static_cast<unsigned char>(MAX_CHR_DB);
                }
            }
        }
    }
    if (color_ == 'b') {
        for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
            for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
                if (bitmap[i][j].b > MAX_CHR_DB / 2) {
                    bitmap[i][j].b = static_cast<unsigned char>(MAX_CHR_DB / 2 -
                                                                (static_cast<double>(bitmap[i][j].b) - MAX_CHR_DB / 2));
                }
                if (bitmap[i][j].b < MAX_CHR_DB / 4) {
                    bitmap[i][j].g = 0;
                    bitmap[i][j].r = 0;
                    bitmap[i][j].b = static_cast<unsigned char>(static_cast<double>(bitmap[i][j].b) * 4);
                } else {
                    bitmap[i][j].g =
                        static_cast<unsigned char>((static_cast<double>(bitmap[i][j].b) - MAX_CHR_DB / 4) * 4);
                    bitmap[i][j].r = bitmap[i][j].g;
                    bitmap[i][j].b = static_cast<unsigned char>(MAX_CHR_DB);
                }
            }
        }
    }
}
