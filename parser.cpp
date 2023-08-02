//
// Created by Timofey Cherlenok on 19.03.2023.
//

#include "parser.h"
Parser::Parser(int argc, char **argv) {
    exception_ = Status::OK;
    if (argc == 1) {
        exception_ = Status::NEED_INFO;
        return;
    }
    if (argc < 3) {
        exception_ = Status::NO_OUTPUT;
        return;
    }

    input_ = argv[1];
    output_ = argv[2];
    if (argc == 3) {
        return;
    }
    size_t index = 3;
    std::string name;
    std::vector<std::string> args;
    while (index < argc) {
        if (argv[index][0] == '-') {

            if (!name.empty()) {
                operations_.emplace_back(ParsedInput{.filter_name = name, .args = args});
                args.clear();
            }
            name = ++argv[index];
        } else {
            args.push_back(argv[index]);
        }
        ++index;
    }
    if (name.empty()) {
        exception_ = Status::INVALID_INPUT;
        return;
    }
    operations_.emplace_back(ParsedInput{.filter_name = name, .args = args});
}
