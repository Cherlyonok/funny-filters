//
// Created by Timofey Cherlenok on 19.03.2023.
//

#pragma once
#include <string>
#include <vector>
#include "parsed_input.h"
#include "exceptions.h"
class Parser : public Exceptions {
public:
    Parser(int argc, char** argv);

    const char* GetInputFilename() const {
        return input_;
    }
    const char* GetOutputFilename() const {
        return output_;
    }
    const std::vector<ParsedInput>& GetOperations() const {
        return operations_;
    }
    const std::string INFO =
        "HELLO!\n This is CherTim's project!\n You can add filters to you pictures using my program\n Just insert "
        "input file path (IN BMP-24), output file path and list of filters\n 1. CROP -- use -crop (INT) (INT) - new "
        "WIDTH and HEIGHT of your image\n 2. GRAYSCALE -- use -gs\n 3. NEGATIVE -- use -neg\n 4. SHARPENING -- use "
        "-sharp\n 5. EDGE DETECTION -- use -edge (DOUBLE) - threshold (i'd use around 0.1)\n 6. BLUR -- use -blur "
        "(DOUBLE) - sigma parameter (less than 6 pls)\n 7. GRADIENT -- use -custom (r or g or b) - color for "
        "gradient\n Love ya!";

private:
    const char* input_;
    const char* output_;
    std::vector<ParsedInput> operations_;
};