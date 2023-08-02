//
// Created by Timofey Cherlenok on 22.03.2023.
//
#include "application.h"
#include "parser.h"
#include "pipeline.h"
#include "bitmap.h"
#include "filter_creators.h"

Status Application::Run() {
    Parser parser(argc_, argv_);
    if (parser.GetStatus() != Status::OK) {
        if (parser.GetStatus() == Status::NEED_INFO) {
            std::cout << parser.INFO;
        }
        return parser.GetStatus();
    }
    Pipeline pipeline(parser.GetOperations(), filters_map_);
    if (pipeline.GetStatus() != Status::OK) {
        return parser.GetStatus();
    }
    BitmapReaderWriter bitmap_rw = BitmapReaderWriter(parser.GetInputFilename());
    if (bitmap_rw.GetStatus() != Status::OK) {
        return parser.GetStatus();
    }
    if (pipeline.Apply(bitmap_rw.GetBitmap()) != Status::OK) {
        return pipeline.GetStatus();
    }
    bitmap_rw.Write(parser.GetOutputFilename());
    if (bitmap_rw.GetStatus() != Status::OK) {
        return parser.GetStatus();
    }
    return Status::OK;
}
Application::Application(int argc, char** argv) : argc_(argc), argv_(argv) {
    FillMap();
}
void Application::FillMap() {
    filters_map_ = {{"crop", &CreateCrop},    {"neg", &CreateNegative}, {"sharp", &CreateSharpening},
                    {"gs", &CreateGray},      {"blur", &CreateBlur},    {"edge", &CreateEdgeDetection},
                    {"custom", &CreateCustom}};
}