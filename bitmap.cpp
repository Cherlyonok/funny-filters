//
// Created by Timofey Cherlenok on 19.03.2023.
//

#include "bitmap.h"
#include <stdio.h>

BitmapReaderWriter::BitmapReaderWriter(const char* file) {
    exception_ = Status::OK;
    FILE* f = fopen(file, "rb");
    if (f == NULL) {
        exception_ = Status::READ_FILE;
        return;
    }

    fread(info_, sizeof(unsigned char), INFO_SIZE, f);
    if (info_[0] != 'B' || info_[1] != 'M') {
        exception_ = Status::NOT_BMP;
        return;
    }
    int width = *reinterpret_cast<int*>(&info_[WIDTH_ST]);
    int height = *reinterpret_cast<int*>(&info_[HEIGHT_ST]);
    bitmap_.Resize(height, width, {0, 0, 0});

    size_t row_padded = (width * 3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    for (size_t i = 0; i < height; ++i) {
        fread(data, sizeof(unsigned char), row_padded, f);
        for (size_t j = 0; j < width * 3; j += 3) {
            bitmap_[bitmap_.GetRowsNum() - 1 - i][j / 3].r = data[j + 2];
            bitmap_[bitmap_.GetRowsNum() - 1 - i][j / 3].g = data[j + 1];
            bitmap_[bitmap_.GetRowsNum() - 1 - i][j / 3].b = data[j];
        }
    }
    delete[] data;
    fclose(f);
}
void BitmapReaderWriter::Write(const char* file) {
    try {
        size_t height = bitmap_.GetRowsNum();
        size_t width = bitmap_.GetColsNum();

        size_t row_padded = (width * 3 + 3) & (~3);

        FILE* image_file = fopen(file, "wb");

        size_t file_size = INFO_SIZE + (row_padded * height);

        info_[FILE_SIZE_ST] = static_cast<unsigned char>(file_size);
        info_[FILE_SIZE_ST + 1] = static_cast<unsigned char>(file_size >> MOVE);
        info_[FILE_SIZE_ST + 2] = static_cast<unsigned char>(file_size >> MOVE * 2);
        info_[FILE_SIZE_ST + 3] = static_cast<unsigned char>(file_size >> MOVE * 3);
        info_[WIDTH_ST] = static_cast<unsigned char>(width);
        info_[WIDTH_ST + 1] = static_cast<unsigned char>(width >> MOVE);
        info_[WIDTH_ST + 2] = static_cast<unsigned char>(width >> MOVE * 2);
        info_[WIDTH_ST + 3] = static_cast<unsigned char>(width >> MOVE * 3);
        info_[HEIGHT_ST] = static_cast<unsigned char>(height);
        info_[HEIGHT_ST + 1] = static_cast<unsigned char>(height >> MOVE);
        info_[HEIGHT_ST + 2] = static_cast<unsigned char>(height >> MOVE * 2);
        info_[HEIGHT_ST + 3] = static_cast<unsigned char>(height >> MOVE * 3);

        fwrite(info_, 1, INFO_SIZE, image_file);

        unsigned char* data = new unsigned char[row_padded];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width * 3; j += 3) {
                data[j + 2] = bitmap_[bitmap_.GetRowsNum() - 1 - i][j / 3].r;
                data[j + 1] = bitmap_[bitmap_.GetRowsNum() - 1 - i][j / 3].g;
                data[j] = bitmap_[bitmap_.GetRowsNum() - 1 - i][j / 3].b;
            }
            fwrite(data, sizeof(unsigned char), row_padded, image_file);
        }
        delete[] data;
        fclose(image_file);
    } catch (std::exception e) {
        exception_ = Status::WRITE_FILE;
        return;
    }
}
