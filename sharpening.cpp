//
// Created by Timofey Cherlenok on 14.03.2023.
//

#include "sharpening.h"

void SharpeningFilter::Apply(Matrix<RGB> &bitmap) {
    Matrix<RGB> newbitmap(bitmap.GetRowsNum(), bitmap.GetColsNum(), {0, 0, 0});
    for (size_t i = 0; i < bitmap.GetRowsNum(); ++i) {
        for (size_t j = 0; j < bitmap.GetColsNum(); ++j) {
            double ans = SHARPENING * (static_cast<double>(bitmap[i][j].r));
            double ansg = SHARPENING * (static_cast<double>(bitmap[i][j].g));
            double ansb = SHARPENING * (static_cast<double>(bitmap[i][j].b));
            if (i > 0) {
                ans -= (static_cast<double>(bitmap[i - 1][j].r));
                ansg -= (static_cast<double>(bitmap[i - 1][j].g));
                ansb -= (static_cast<double>(bitmap[i - 1][j].b));
            } else {
                ans -= (static_cast<double>(bitmap[i][j].r));
                ansg -= (static_cast<double>(bitmap[i][j].g));
                ansb -= (static_cast<double>(bitmap[i][j].b));
            }
            if (j > 0) {
                ans -= (static_cast<double>(bitmap[i][j - 1].r));
                ansg -= (static_cast<double>(bitmap[i][j - 1].g));
                ansb -= (static_cast<double>(bitmap[i][j - 1].b));
            } else {
                ans -= (static_cast<double>(bitmap[i][j].r));
                ansg -= (static_cast<double>(bitmap[i][j].g));
                ansb -= (static_cast<double>(bitmap[i][j].b));
            }
            if (i < bitmap.GetRowsNum() - 1) {
                ans -= (static_cast<double>(bitmap[i + 1][j].r));
                ansg -= (static_cast<double>(bitmap[i + 1][j].g));
                ansb -= (static_cast<double>(bitmap[i + 1][j].b));
            } else {
                ans -= (static_cast<double>(bitmap[i][j].r));
                ansg -= (static_cast<double>(bitmap[i][j].g));
                ansb -= (static_cast<double>(bitmap[i][j].b));
            }
            if (j < bitmap.GetColsNum() - 1) {
                ans -= (static_cast<double>(bitmap[i][j + 1].r));
                ansg -= (static_cast<double>(bitmap[i][j + 1].g));
                ansb -= (static_cast<double>(bitmap[i][j + 1].b));
            } else {
                ans -= (static_cast<double>(bitmap[i][j].r));
                ansg -= (static_cast<double>(bitmap[i][j].g));
                ansb -= (static_cast<double>(bitmap[i][j].b));
            }
            newbitmap[i][j].r = static_cast<unsigned char>(std::min(MAX_CHR_DB, std::max(0.0, ans)));
            newbitmap[i][j].g = static_cast<unsigned char>(std::min(MAX_CHR_DB, std::max(0.0, ansg)));
            newbitmap[i][j].b = static_cast<unsigned char>(std::min(MAX_CHR_DB, std::max(0.0, ansb)));
        }
    }
    bitmap = newbitmap;
}
