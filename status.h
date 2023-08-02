//
// Created by Timofey Cherlenok on 22.03.2023.
//

#pragma once

enum class Status {
    OK = 0,
    BROKEN = 1,
    READ_FILE = 101,
    NOT_BMP = 102,
    WRITE_FILE = 103,
    NO_OUTPUT = 201,
    INVALID_INPUT = 202,
    INVALID_FILTER_NAME = 301,
    FILTER_CREATION = 302,
    FILTER_APPLIANCE = 303,
    NEED_INFO = 500
};