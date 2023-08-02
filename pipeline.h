//
// Created by Timofey Cherlenok on 19.03.2023.
//

#pragma once
#include "parsed_input.h"
#include "filter.h"
#include "matrix.h"
#include "exceptions.h"
class Pipeline : public Exceptions {
public:
    explicit Pipeline(const std::vector<ParsedInput>& parsed_input, FilterMap& filters_map);
    Pipeline(const Pipeline& pipeline) = delete;
    Pipeline operator=(const Pipeline& pipeline) = delete;

    Status Apply(Matrix<RGB>& bitmap);
    ~Pipeline();

private:
    std::vector<Filter*> operations_;
};
