
#include <iostream>
#include "application.h"
#include "status.h"

int main(int argc, char** argv) {
    try {
        Application app(argc, argv);
        return static_cast<int>(app.Run());
    } catch (std::exception& e) {
        std::cout << e.what();
        return static_cast<int>(Status::BROKEN);
    } catch (...) {
        std::cout << "THERE IS SOME KIND OF A PROBLEM...sorry";
        return static_cast<int>(Status::BROKEN);
    }
}