//
// Created by Timofey Cherlenok on 19.03.2023.
//

#include "pipeline.h"
#include "matrix.h"

Pipeline::Pipeline(const std::vector<ParsedInput>& parsed_input, FilterMap& filters_map) {
    exception_ = Status::OK;
    for (const ParsedInput& parsed : parsed_input) {
        auto it = filters_map.find(parsed.filter_name);
        if (it == filters_map.end()) {
            exception_ = Status::INVALID_FILTER_NAME;
            return;
        }
        operations_.push_back(((it->second))(parsed.args));
        if (operations_[operations_.size() - 1] == nullptr) {
            exception_ = Status::FILTER_CREATION;
        }
    }
}
Status Pipeline::Apply(Matrix<RGB>& bitmap) {
    for (Filter* filter : operations_) {
        try {
            filter->Apply(bitmap);
        } catch (std::exception e) {
            exception_ = Status::FILTER_APPLIANCE;
            return exception_;
        }
    }
    return exception_;
}

Pipeline::~Pipeline() {
    for (Filter* filter : operations_) {
        delete filter;
    }
}
