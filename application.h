//
// Created by Timofey Cherlenok on 22.03.2023.
//

#pragma once
#include "status.h"
#include "string"
#include "map"
#include "vector"
#include "filter.h"
class Application {
public:
    using FilterPointer = Filter* (*)(const std::vector<std::string>&);
    using FilterMap = std::map<std::string, FilterPointer>;

    Application(int argc, char** argv);  // Parser как параметр
    Status Run();
    Application(const Application& application) = delete;
    Application operator=(const Application& application) = delete;

private:
    int argc_;
    char** argv_;
    FilterMap filters_map_;

    void FillMap();
};