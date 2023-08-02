//
// Created by Timofey Cherlenok on 22.03.2023.
//
#pragma once
#include "filter.h"
#include "crop.h"
#include "negative.h"
#include "sharpening.h"
#include "grayscale.h"
#include "gaussian_blur.h"
#include "edge_detection.h"
#include "custom_gradient.h"

Filter* CreateCrop(const std::vector<std::string>& args) {
    if (args.size() != CropFilter::NUM_PARAM) {
        return nullptr;
    }
    try {
        std::string::const_iterator it = args[0].begin();
        while (it != args[0].end() && std::isdigit(*it)) {
            ++it;
        }
        if (args[0].empty() || it != args[0].end()) {
            return nullptr;
        }
        it = args[1].begin();
        while (it != args[1].end() && std::isdigit(*it)) {
            ++it;
        }
        if (args[1].empty() || it != args[1].end()) {
            return nullptr;
        }
        if (std::stoi(args[0]) <= 0 || std::stoi(args[1]) <= 0) {
            return nullptr;
        }
        CropFilter* crop = new CropFilter(std::stoi(args[0]), std::stoi(args[1]));
        return crop;
    } catch (std::exception e) {
        return nullptr;
    }
}
Filter* CreateNegative(const std::vector<std::string>& args) {
    if (args.size() != NegativeFilter::NUM_PARAM) {
        return nullptr;
    }
    NegativeFilter* negative = new NegativeFilter();
    return negative;
}
Filter* CreateSharpening(const std::vector<std::string>& args) {
    if (args.size() != SharpeningFilter::NUM_PARAM) {
        return nullptr;
    }
    SharpeningFilter* sharp = new SharpeningFilter();
    return sharp;
}
Filter* CreateGray(const std::vector<std::string>& args) {
    if (args.size() != GrayScaleFilter::NUM_PARAM) {
        return nullptr;
    }
    GrayScaleFilter* gray = new GrayScaleFilter();
    return gray;
}
Filter* CreateBlur(const std::vector<std::string>& args) {
    if (args.size() != GaussianBlurFilter::NUM_PARAM) {
        return nullptr;
    }
    try {
        std::string::const_iterator it = args[0].begin();
        size_t num_dots = 0;
        while (it != args[0].end() && (std::isdigit(*it) || *it == '.')) {
            if (*it == '.') {
                ++num_dots;
            }
            ++it;
        }
        if (args[0].empty() || it != args[0].end() || num_dots > 1) {
            return nullptr;
        }

        GaussianBlurFilter* blur = new GaussianBlurFilter(std::stod(args[0]));
        return blur;
    } catch (std::exception e) {
        return nullptr;
    }
}
Filter* CreateEdgeDetection(const std::vector<std::string>& args) {
    if (args.size() != EdgeDetectionFilter::NUM_PARAM) {
        return nullptr;
    }
    try {
        std::string::const_iterator it = args[0].begin();
        size_t num_dots = 0;
        while (it != args[0].end() && (std::isdigit(*it) || *it == '.')) {
            if (*it == '.') {
                ++num_dots;
            }
            ++it;
        }
        if (args[0].empty() || it != args[0].end() || num_dots > 1) {
            return nullptr;
        }
        EdgeDetectionFilter* edge = new EdgeDetectionFilter(std::stod(args[0]));
        return edge;
    } catch (std::exception e) {
        return nullptr;
    }
}
Filter* CreateCustom(const std::vector<std::string>& args) {
    if (args.size() != EdgeDetectionFilter::NUM_PARAM) {
        return nullptr;
    }
    if (args[0] == "r" || args[0] == "g" || args[0] == "b") {
        CustomGradientFilter* custom = new CustomGradientFilter(args[0][0]);
        return custom;
    }
    return nullptr;
}
