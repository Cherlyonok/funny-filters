//
// Created by Timofey Cherlenok on 14.03.2023.
//

#include "gaussian_blur.h"
#include <math.h>
#include <vector>
void GaussianBlurFilter::Apply(Matrix<RGB> &bitmap) {
    Matrix<RGB> newbitmap(bitmap.GetRowsNum(), bitmap.GetColsNum(), {0, 0, 0});
    int len = static_cast<int>(3 * sigma_);
    std::vector<std::vector<double>> parameters(2 * len + 1);
    for (int i = 0; i < 2 * len + 1; ++i) {
        for (int j = 0; j < 2 * len + 1; ++j) {
            parameters[i].push_back(exp(-(((i - len) * (i - len) + (j - len) * (j - len))) / (2 * sigma_ * sigma_)) /
                                    (2 * sigma_ * sigma_ * M_PI));
        }
    }
    for (int i = 0; i < (bitmap.GetRowsNum()); ++i) {
        for (int j = 0; j < (bitmap.GetColsNum()); ++j) {
            double ansr = 0;
            double ansg = 0;
            double ansb = 0;
            int li = std::max(0, i - len);
            int ri = std::min(i + len, static_cast<int>((bitmap.GetRowsNum() - 1)));
            double sum = 0;
            for (int i2 = li; i2 <= ri; ++i2) {
                ansr += (static_cast<double>(bitmap[i2][j].r) * parameters[len - (i - i2)][len]);
                ansg += (static_cast<double>(bitmap[i2][j].g) * parameters[len - (i - i2)][len]);
                ansb += (static_cast<double>(bitmap[i2][j].b) * parameters[len - (i - i2)][len]);
                sum += parameters[len - (i - i2)][len];
            }
            newbitmap[i][j].r = static_cast<unsigned char>(ansr / sum);
            newbitmap[i][j].g = static_cast<unsigned char>(ansg / sum);
            newbitmap[i][j].b = static_cast<unsigned char>(ansb / sum);
        }
    }
    bitmap = newbitmap;
    for (int i = 0; i < (bitmap.GetRowsNum()); ++i) {
        for (int j = 0; j < (bitmap.GetColsNum()); ++j) {
            double ansr = 0;
            double ansg = 0;
            double ansb = 0;
            int lj = std::max(0, j - len);
            int rj = std::min(j + len, static_cast<int>((bitmap.GetColsNum() - 1)));
            double sum = 0;
            for (int j2 = lj; j2 <= rj; ++j2) {
                ansr += (static_cast<double>(bitmap[i][j2].r) * parameters[len][len - (j - j2)]);
                ansg += (static_cast<double>(bitmap[i][j2].g) * parameters[len][len - (j - j2)]);
                ansb += (static_cast<double>(bitmap[i][j2].b) * parameters[len][len - (j - j2)]);
                sum += parameters[len][len - (j - j2)];
            }

            newbitmap[i][j].r = static_cast<unsigned char>(ansr / sum);
            newbitmap[i][j].g = static_cast<unsigned char>(ansg / sum);
            newbitmap[i][j].b = static_cast<unsigned char>(ansb / sum);
        }
    }
    bitmap = newbitmap;
}
