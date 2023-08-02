//
// Created by Timofey Cherlenok on 23.03.2023.
//
#include <catch.hpp>
#include "filter.h"
#include "parsed_input.h"
#include "pipeline.h"
#include "bitmap.h"
#include "filter_creators.h"
#include "parser.h"

// TESTS TO TEST FILTER CREATIONS
TEST_CASE("CROP") {
    FilterMap map = {{"crop", &CreateCrop}};
    std::vector<ParsedInput> input = {{"crop", {"500", "500"}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
    REQUIRE(pipeline.Apply(bmp_rw.GetBitmap()) == Status::OK);
    bmp_rw.Write("test_script/data/lenna2.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}

TEST_CASE("CROP_BIG") {
    FilterMap map = {{"crop", &CreateCrop}};
    std::vector<ParsedInput> input = {{"crop", {"10000", "10000"}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
    REQUIRE(pipeline.Apply(bmp_rw.GetBitmap()) == Status::OK);
    bmp_rw.Write("test_script/data/lenna2.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}

TEST_CASE("GRAY") {
    FilterMap map = {{"gs", &CreateGray}};
    std::vector<ParsedInput> input = {{"gs", {}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
    REQUIRE(pipeline.Apply(bmp_rw.GetBitmap()) == Status::OK);
    bmp_rw.Write("test_script/data/lenna2.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}

TEST_CASE("EDGE") {
    FilterMap map = {{"edge", &CreateEdgeDetection}};
    std::vector<ParsedInput> input = {{"edge", {"0.1"}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
    REQUIRE(pipeline.Apply(bmp_rw.GetBitmap()) == Status::OK);
    bmp_rw.Write("test_script/data/lenna2.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}

TEST_CASE("BLUR") {
    FilterMap map = {{"blur", &CreateBlur}};
    std::vector<ParsedInput> input = {{"blur", {"7.5"}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
    REQUIRE(pipeline.Apply(bmp_rw.GetBitmap()) == Status::OK);
    bmp_rw.Write("test_script/data/lenna2.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}

TEST_CASE("NEGATIVE") {
    FilterMap map = {{"neg", &CreateNegative}};
    std::vector<ParsedInput> input = {{"neg", {}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
    REQUIRE(pipeline.Apply(bmp_rw.GetBitmap()) == Status::OK);
    bmp_rw.Write("test_script/data/lenna2.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}

TEST_CASE("SHARP") {
    FilterMap map = {{"sharp", &CreateSharpening}};
    std::vector<ParsedInput> input = {{"sharp", {}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
    REQUIRE(pipeline.Apply(bmp_rw.GetBitmap()) == Status::OK);
    bmp_rw.Write("test_script/data/lenna2.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}

TEST_CASE("CUSTOM") {
    FilterMap map = {{"custom", &CreateCustom}};
    std::vector<ParsedInput> input = {{"crop", {"r"}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
    REQUIRE(pipeline.Apply(bmp_rw.GetBitmap()) == Status::OK);
    bmp_rw.Write("test_script/data/lenna2.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}

// TESTS TO TEST OTHER MODULES OF THE PROGRAM

TEST_CASE("READ_FILE") {
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lennnnna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::READ_FILE);
}

TEST_CASE("NOT_BMP") {
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.png");
    REQUIRE(bmp_rw.GetStatus() == Status::NOT_BMP);
}

// TEST_CASE("NO_OUTPUT"){
//     Parser parser(2, (char **)("program_name input.bmp"));
//     REQUIRE(parser.GetStatus() == Status::NO_OUTPUT);
// }

TEST_CASE("INVALID_FILTER_NAME") {
    FilterMap map = {{"crop", &CreateCrop}};
    std::vector<ParsedInput> input = {{"cropp", {"500", "500"}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::INVALID_FILTER_NAME);
}

TEST_CASE("PIPELINE") {
    FilterMap map = {{"crop", &CreateCrop}};
    std::vector<ParsedInput> input = {{"crop", {"500", "500"}}};
    Pipeline pipeline(input, map);
    REQUIRE(pipeline.GetStatus() == Status::OK);
}

TEST_CASE("READER") {
    BitmapReaderWriter bmp_rw = BitmapReaderWriter("test_script/data/lenna.bmp");
    REQUIRE(bmp_rw.GetStatus() == Status::OK);
}