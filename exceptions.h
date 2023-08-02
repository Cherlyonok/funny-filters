//
// Created by Timofey Cherlenok on 21.03.2023.
//

#pragma once
#include <string>
#include "status.h"
class Exceptions {
public:
    Status GetStatus() const {
        return exception_;
    }

protected:
    Status exception_;
};
