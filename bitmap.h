//
// Created by Timofey Cherlenok on 19.03.2023.
//

#pragma once
#include "matrix.h"
#include <string>
#include "exceptions.h"

class BitmapReaderWriter : public Exceptions {
public:
    explicit BitmapReaderWriter(const char* file);
    Matrix<RGB>& GetBitmap() {
        return bitmap_;
    }
    void Write(const char* file);

private:
    static const size_t INFO_SIZE = 54;

    static const size_t FILE_SIZE_ST = 2;
    static const size_t WIDTH_ST = 18;
    static const size_t HEIGHT_ST = 22;
    static const size_t MOVE = 8;

    Matrix<RGB> bitmap_ = Matrix<RGB>(0, 0, {0, 0, 0});

    unsigned char info_[INFO_SIZE];
};