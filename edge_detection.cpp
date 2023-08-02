//
// Created by Timofey Cherlenok on 14.03.2023.
//

#include "edge_detection.h"
void EdgeDetectionFilter::Apply(Matrix<RGB> &bitmap) {

    Matrix<double> newbitmap(bitmap.GetRowsNum(), bitmap.GetColsNum(), 0);
    for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
        for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
            bitmap[i][j].r = static_cast<unsigned char>((GsTransformFactorR * (static_cast<double>(bitmap[i][j].r)) +
                                                         GsTransformFactorG * (static_cast<double>(bitmap[i][j].g)) +
                                                         GsTransformFactorB * (static_cast<double>(bitmap[i][j].b))));
            bitmap[i][j].g = bitmap[i][j].r;
            bitmap[i][j].b = bitmap[i][j].r;
        }
    }

    for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
        for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
            double ans = 4 * (static_cast<double>(bitmap[i][j].r));

            if (i > 0) {
                ans -= (static_cast<double>(bitmap[i - 1][j].r));

            } else {
                ans -= (static_cast<double>(bitmap[i][j].r));
            }
            if (j > 0) {
                ans -= (static_cast<double>(bitmap[i][j - 1].r));

            } else {
                ans -= (static_cast<double>(bitmap[i][j].r));
            }
            if (i < bitmap.GetRowsNum() - 1) {
                ans -= (static_cast<double>(bitmap[i + 1][j].r));

            } else {
                ans -= (static_cast<double>(bitmap[i][j].r));
            }
            if (j < bitmap.GetColsNum() - 1) {
                ans -= (static_cast<double>(bitmap[i][j + 1].r));

            } else {
                ans -= (static_cast<double>(bitmap[i][j].r));
            }
            newbitmap[i][j] = static_cast<unsigned char>(std::min(MAX_CHR_DB, std::max(0.0, ans)));
        }
    }
    for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
        for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
            if (newbitmap[i][j] < MAX_CHR_DB * threshold_) {
                bitmap[i][j].r = 0;
                bitmap[i][j].g = 0;
                bitmap[i][j].b = 0;

            } else {
                bitmap[i][j].r = static_cast<unsigned char>(MAX_CHR_DB);
                bitmap[i][j].g = static_cast<unsigned char>(MAX_CHR_DB);
                bitmap[i][j].b = static_cast<unsigned char>(MAX_CHR_DB);
            }
        }
    }
}
