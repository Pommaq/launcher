//
// Created by timmy on 10/25/20.
//

#include "../includes/filedetect.h"
#include <filesystem>
#include <vector>
#include <iostream>
#include <fstream>

int getfiles(std::vector<program> &toFill) {
    // NOTE: Requires C++17 or newer
    for (const auto& entry: std::filesystem::directory_iterator("./programs")){
        if (entry.is_regular_file() && validate_program(std::filesystem::path(entry).filename())){
            toFill.emplace_back(std::filesystem::path(entry).filename(), entry.path());
        }
    }
    return 0;
}

bool validate_program(std::string progName) {
    std::ifstream file;
    bool valid = false;

    file.open("./instructions/" + progName + ".instr");
    if (file.good()){
        std::string data;
        file >> data; // Reads first line
        if (data == "PROGNAME=" + progName){
            valid = true;
        }
    }
    return valid;
}
